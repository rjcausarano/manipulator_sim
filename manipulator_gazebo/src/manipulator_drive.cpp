#include <manipulator_gazebo/manipulator_drive.hpp>

namespace manipulator_gazebo
{

ManipulatorDrive::ManipulatorDrive()
  : gazebo::ModelPlugin()
{
    std::cout << "Hello World! Constructor executed!" << std::endl;
}

void ManipulatorDrive::Load(gazebo::physics::ModelPtr _model, sdf::ElementPtr _sdf)
{
    ros_node_ = gazebo_ros::Node::Get(_sdf);
    const gazebo_ros::QoS& qos = ros_node_->get_qos();
    pose_angles_sub_ = ros_node_->create_subscription<manipulator_msgs::msg::Pose>(
      "set_pose", qos.get_subscription_qos("set_pose", rclcpp::SensorDataQoS().reliable()),
      std::bind(&ManipulatorDrive::OnSetPose, this, std::placeholders::_1));
    std::cout << "Hello World! I've initialized" << std::endl;
}

void ManipulatorDrive::Reset()
{
    std::cout << "Hello World! I've Reset" << std::endl;
}

void ManipulatorDrive::OnSetPose(manipulator_msgs::msg::Pose::SharedPtr msg)
{
    std::cout << "The vector size is: " << msg->data.size() << std::endl;
    // std::cout << "You are trying to set the pose: " << msg->data[0] << msg->data[1] << msg->data[2] << std::endl;
}

GZ_REGISTER_MODEL_PLUGIN(ManipulatorDrive)
}
