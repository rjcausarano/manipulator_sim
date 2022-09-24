#pragma once

#include <manipulator_msgs/msg/pose.hpp>
#include "rclcpp/rclcpp.hpp"
#include <vector>

class PoseCalculator  : public rclcpp::Node{

public:
    PoseCalculator();
    ~PoseCalculator(){};

private:
    rclcpp::Publisher<manipulator_msgs::msg::Pose>::SharedPtr publisher_;
    manipulator_msgs::msg::Pose pose_msg_;
    const float D1=0.06f, D2=0.25f, D3=0.20f;

    std::vector<float> calculate_pose(std::vector<float> pose);
    bool validate_pose(std::vector<float> pose);
};
