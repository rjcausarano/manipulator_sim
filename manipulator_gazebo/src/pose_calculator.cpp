#include "manipulator_gazebo/pose_calculator.hpp"
#include <string>

PoseCalculator::PoseCalculator()
: Node("pose_calculator")
{
    publisher_ = this->create_publisher<manipulator_msgs::msg::Pose>("set_pose", 10);
    short unsigned int x, y, z;
    while(true){
        std::cin >> x;
        std::cin >> y;
        std::cin >> z;
        pose_msg_.data = {x, y, z};
        publisher_->publish(pose_msg_);
    }
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PoseCalculator>());
    rclcpp::shutdown();
    return 0;
}