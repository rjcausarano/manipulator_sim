#include "manipulator_gazebo/pose_calculator.hpp"
#include <cmath>

PoseCalculator::PoseCalculator()
: Node("pose_calculator")
{
    publisher_ = this->create_publisher<manipulator_msgs::msg::Pose>("set_pose", 10);
    float x, y, z;
    std::cout << "Enter x, y, z coordinates of tool" << std::endl;
    std::cin >> x >> y >> z;
    std::vector<float> input_pose = {x, y, z};
    if(validate_pose(input_pose)){
        pose_msg_.data = calculate_pose(input_pose);
        publisher_->publish(pose_msg_);
    } else{
        std::cout << "Pose introduced is not valid! please try again" << std::endl;
    }
}

std::vector<float> PoseCalculator::calculate_pose(std::vector<float> pose){
    float xt = pose[0], yt = pose[1], zt = pose[2];
    std::cout << "xt: " << xt << " yt: " << yt << " zt: " << zt << std::endl;
    float dt = sqrt(xt*xt + yt*yt);
    float ht = zt - D1;
    std::cout << "dt: " << dt << " ht: " << ht << std::endl;
    float a3 = acos((dt*dt + ht*ht - D2*D2 - D3*D3) / (-2*D2*D3));
    float w = atan2(D3*sin(M_PI - a3), D2 + D3*cos(M_PI - a3));
    float a2 = atan2(ht, dt) + w;
    float a1 = atan2(yt, xt);
    std::cout << "a3: " << a3 << " a2: " << a2 << " a1: " << a1 << " w: " << w << std::endl;
    return {a1, a2, a3};
}

bool PoseCalculator::validate_pose(std::vector<float> pose){
    float xt = pose[0], yt = pose[1], zt = pose[2];
    return D2 + D3 >= sqrt((zt - D1)*(zt - D1) + xt*xt + yt*yt);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PoseCalculator>());
    rclcpp::shutdown();
    return 0;
}