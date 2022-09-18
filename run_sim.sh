#!/bin/bash

CURRENT_PATH=$( dirname -- "$0"; )
cd $CURRENT_PATH
xacro manipulator_gazebo/urdf/manipulator.urdf.xacro > manipulator_gazebo/model/manipulator/manipulator.urdf
ros2 launch manipulator_gazebo run_sim.launch.py
