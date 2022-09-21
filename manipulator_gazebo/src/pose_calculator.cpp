#include "manipulator_gazebo/pose_calculator.hpp"
#include <cmath>

PoseCalculator::PoseCalculator()
: Node("pose_calculator")
{
    publisher_ = this->create_publisher<manipulator_msgs::msg::Pose>("set_pose", 10);
    float x, y, z;
    unsigned char i;
    while(true){
        std::cout << "Enter x, y, z coordinates of tool" << std::endl;
        std::cin >> x >> y >> z;
        pose_msg_.data = calculate_pose({x, y, z});
        publisher_->publish(pose_msg_);

        std::cout << "Would you like to enter another coordinate? y/n" << std::endl;
        std::cin >> i;
        if(i == 'n'){
            break;
        }
    }
}

std::vector<float> PoseCalculator::calculate_pose(std::vector<float> pose){
    float xt = pose[0], yt = pose[1], zt = pose[2];

    float dt = sqrt(xt*xt + yt*yt);
    float ht = zt - D1;

    float a3 = acos((dt*dt + ht*ht - D2*D2 - D3*D3) / -2*D2*D3);
    float w = atan2(D3*sin(M_PI - a3), D2 + D3*cos(M_PI - a3));
    float a2 = atan2(ht, dt) + w;
    float a1 = atan2(yt, xt);
    return {a1, a2, a3};
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PoseCalculator>());
    rclcpp::shutdown();
    return 0;
}