#pragma once

#include <manipulator_msgs/msg/pose.hpp>
#include "rclcpp/rclcpp.hpp"
#include <gazebo/common/Plugin.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/Joint.hh>
#include <gazebo_ros/node.hpp>
#include <memory>

namespace manipulator_gazebo
{

class ManipulatorDrive : public gazebo::ModelPlugin
{
public:
  ManipulatorDrive();

protected:
  void Load(gazebo::physics::ModelPtr _model, sdf::ElementPtr _sdf) override;
  void Reset() override;

private:
  void OnSetPose(manipulator_msgs::msg::Pose::SharedPtr msg);

  gazebo_ros::Node::SharedPtr ros_node_{nullptr};
  rclcpp::Subscription<manipulator_msgs::msg::Pose>::SharedPtr pose_angles_sub_;
  gazebo::physics::JointPtr joint_1_{nullptr};
  gazebo::physics::JointPtr joint_2_{nullptr};
  gazebo::physics::JointPtr joint_3_{nullptr};
};
}
