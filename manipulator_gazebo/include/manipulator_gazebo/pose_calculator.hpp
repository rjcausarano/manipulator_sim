#pragma once

#include <manipulator_msgs/msg/pose.hpp>
#include "rclcpp/rclcpp.hpp"

class PoseCalculator  : public rclcpp::Node{

public:
    PoseCalculator();
    ~PoseCalculator(){};

private:
    // rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    rclcpp::Publisher<manipulator_msgs::msg::Pose>::SharedPtr publisher_;
    manipulator_msgs::msg::Pose pose_msg_;
    rclcpp::TimerBase::SharedPtr timer_;

    void timer_callback();
};
