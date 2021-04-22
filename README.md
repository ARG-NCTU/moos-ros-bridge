# moos-ros-bridge
This ros pkg is based on [moos-ros-bridge](https://github.com/SyllogismRXS/moos-ros-bridge). We change the CmakeList from rosbuild to catkin.

### How to run
Clone this repo to your catkin_ws/src. For example
```
$ cd
$ mkdir -p moos-ros-bridge/catkin_ws/src
$ cd moos-ros-bridge/catkin_ws/src/
$ git clone https://github.com/tonycar12002/moos-ros-bridge.git 
$ cd ../
$ caktin_make
$ source /opt/ros/kinetic/setup.bash
$ source ~/moos-ros-bridge/catkin_ws/devel/setup.bash
$ export PATH=$HOME/moos-ivp/bin:$PATH
```
First terminal </br>
$ roscore </br>
Second terminal</br>
$ MOOSDB </br>
Third terminal, remind to source the setup.bash </br>
$ roslaunch moosros_tester counter.launch </br>
Fourth terminal, see the data from ros to moos </br>
$ uXMS CounterFromROS </br> 
Fifth terminal, see the data from moos to ros </br>
$ rostopic echo /CounterFromMOOS </br> 
Sixth terminal, send the msg <br>
$ uPokeDB CounterFromMOOS=23










