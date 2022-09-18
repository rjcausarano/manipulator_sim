#!/usr/bin/env python3

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess
from launch.substitutions import PathJoinSubstitution

# Set path variables
manipulator_gazebo_pkg = get_package_share_directory('manipulator_gazebo')
world_path = PathJoinSubstitution([manipulator_gazebo_pkg, 'worlds', 'manipulator.world'])

gzserver = ExecuteProcess(
            cmd=['gzserver', '--verbose', '-s', 'libgazebo_ros_factory.so', '-s', 'libgazebo_ros_init.so', world_path],
            output='screen')

gzclient = ExecuteProcess(
            cmd=['gzclient'],
            output='screen')

def generate_launch_description():
    ld = LaunchDescription()
    # Add nodes to LaunchDescription
    ld.add_action(gzserver)
    ld.add_action(gzclient)

    return ld
