#!/bin/bash

xacro manipulator.urdf.xacro > model/manipulator/manipulator.urdf
gazebo --verbose manipulator.world
