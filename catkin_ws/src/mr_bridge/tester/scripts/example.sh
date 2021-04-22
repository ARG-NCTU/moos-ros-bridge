#!/bin/bash

# Launch the ROS nodes
roslaunch tester examle.launch &
ROSLAUNCH_PID=$!

# Launch the MOOS nodes
pAntler $(rospack find bridge)/m_launch/example/bridge.moos >& /dev/null &
PANTLER_PID=$!

uMAC $(rospack find bridge)/moos_launch/example/bridge.moos

printf "Killing all processes, safely ... \n"
kill -SIGTERM $ROSLAUNCH_PID
kill -SIGTERM $PANTLER_PID
printf "Done killing processes.   \n"


