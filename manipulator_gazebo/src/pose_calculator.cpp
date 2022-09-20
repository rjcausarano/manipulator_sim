#include "manipulator_gazebo/pose_calculator.hpp"
#include <string>
#include <chrono>

using namespace std::chrono_literals;

PoseCalculator::PoseCalculator()
: Node("pose_calculator")
{
    publisher_ = this->create_publisher<manipulator_msgs::msg::Pose>("set_pose", 10);
    pose_msg_.data = {1, 1, 1};
    publisher_->publish(pose_msg_);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PoseCalculator>());
    rclcpp::shutdown();
    return 0;
}