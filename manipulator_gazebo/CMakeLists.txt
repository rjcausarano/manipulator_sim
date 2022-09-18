cmake_minimum_required(VERSION 3.5)

project(manipulator_gazebo)

find_package(ament_cmake REQUIRED)
find_package(gazebo REQUIRED)
find_package(urdf REQUIRED)
find_package(xacro REQUIRED)

# ament_python_install_package(manipulator_launcher)

install(
  DIRECTORY
    model
    launch
    urdf
    worlds
  DESTINATION
    share/${PROJECT_NAME}/
)

# install(
#   DIRECTORY
#     manipulator_launcher
#   DESTINATION lib/${PROJECT_NAME}/
# )

# Update gazebo resources path
ament_environment_hooks("${CMAKE_CURRENT_SOURCE_DIR}/env-hooks/manipulator_gazebo.dsv.in")
ament_environment_hooks("${CMAKE_CURRENT_SOURCE_DIR}/env-hooks/manipulator_gazebo.sh.in")

ament_package()


