#pragma once

#include <gazebo/common/Plugin.hh>
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

};
}
