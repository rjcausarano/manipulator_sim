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
    std::cout << "Hello World! I've initialized" << std::endl;
}

void ManipulatorDrive::Reset()
{
    std::cout << "Hello World! I've Reset" << std::endl;
}

GZ_REGISTER_MODEL_PLUGIN(ManipulatorDrive)
}
