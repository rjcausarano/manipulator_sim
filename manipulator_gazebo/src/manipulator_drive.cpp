#include <manipulator_gazebo/manipulator_drive.hpp>
#include <math.h>

namespace manipulator_gazebo
{

ManipulatorDrive::ManipulatorDrive()
  : gazebo::ModelPlugin()
{
}

void ManipulatorDrive::Load(gazebo::physics::ModelPtr _model, sdf::ElementPtr _sdf)
{
  ros_node_ = gazebo_ros::Node::Get(_sdf);
  const gazebo_ros::QoS& qos = ros_node_->get_qos();
  pose_angles_sub_ = ros_node_->create_subscription<manipulator_msgs::msg::Pose>(
    "set_pose", qos.get_subscription_qos("set_pose", rclcpp::SensorDataQoS().reliable()),
    std::bind(&ManipulatorDrive::OnSetPose, this, std::placeholders::_1));
  joint_1_ = _model->GetJoint("joint_1");
  joint_2_ = _model->GetJoint("joint_2");
  joint_3_ = _model->GetJoint("joint_3");
}

void ManipulatorDrive::Reset()
{
}

void ManipulatorDrive::OnSetPose(manipulator_msgs::msg::Pose::SharedPtr msg)
{
  std::cout << "You are trying to set the pose: " << msg->data[0] << msg->data[1] << msg->data[2] << std::endl;
  joint_1_->SetPosition(0, msg->data[0]);
  joint_2_->SetPosition(0, msg->data[1]);
  joint_3_->SetPosition(0, msg->data[2]);
}

GZ_REGISTER_MODEL_PLUGIN(ManipulatorDrive)
}
