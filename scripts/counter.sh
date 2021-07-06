#!/bin/bash

# Launch the ROS nodes
roslaunch moos-ros-bridge vrx_moos_ros.launch &
ROSLAUNCH_PID=$!

# Launch the MOOS nodes
pAntler $(rospack find moos-ros-bridge)/config/bridge.moos >& /dev/null &
PANTLER_PID=$!

uMAC $(rospack find moos-ros-bridge)/config/bridge.moos

printf "Killing all processes, safely ... \n"
kill -SIGTERM $ROSLAUNCH_PID
kill -SIGTERM $PANTLER_PID
printf "Done killing processes.   \n"
