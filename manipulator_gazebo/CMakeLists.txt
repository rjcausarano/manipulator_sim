cmake_minimum_required(VERSION 3.5)

project(manipulator_gazebo)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake REQUIRED)
find_package(gazebo REQUIRED)
find_package(gazebo_dev REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(urdf REQUIRED)
find_package(xacro REQUIRED)
find_package(manipulator_msgs REQUIRED)
find_package(rclcpp REQUIRED)

link_directories(${gazebo_dev_LIBRARY_DIRS})

# ament_python_install_package(manipulator_launcher)

add_library(manipulator_drive SHARED
  src/manipulator_drive.cpp
)
target_include_directories(manipulator_drive PUBLIC include)
ament_target_dependencies(manipulator_drive
  "gazebo_dev"
  "gazebo_ros"
  "rclcpp"
  "manipulator_msgs"
)
ament_export_libraries(manipulator_drive)

add_executable(pose_calculator src/pose_calculator.cpp)
target_include_directories(pose_calculator PUBLIC include)
ament_target_dependencies(pose_calculator
  "manipulator_msgs"
  "rclcpp"
)

install(
  DIRECTORY
    model
    launch
    urdf
    worlds
  DESTINATION
    share/${PROJECT_NAME}/
)

install(DIRECTORY include/
        DESTINATION include)

install(TARGETS
    manipulator_drive
    pose_calculator
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME})

# install(
#   DIRECTORY
#     manipulator_launcher
#   DESTINATION lib/${PROJECT_NAME}/
# )

# Update gazebo resources path
ament_environment_hooks("${CMAKE_CURRENT_SOURCE_DIR}/env-hooks/manipulator_gazebo.dsv.in")
ament_environment_hooks("${CMAKE_CURRENT_SOURCE_DIR}/env-hooks/manipulator_gazebo.sh.in")

ament_package()


