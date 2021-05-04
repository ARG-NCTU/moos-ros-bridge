# moos-ros-bridge
This ros pkg is based on [moos-ros-bridge](https://github.com/SyllogismRXS/moos-ros-bridge). We change the CmakeList from rosbuild to catkin.

### How to build & run this project in your computer
Clone this repo to your catkin_ws/src. For example
```
$ cd
$ mkdir -p moos-ros-bridge/catkin_ws/src
$ cd moos-ros-bridge/catkin_ws/src/
$ git clone https://github.com/ARG-NCTU/moos-ros-bridge/tree/devel-MF.git 
$ cd ../
$ caktin_make
$ source /opt/ros/kinetic/setup.bash
$ source ~/moos-ros-bridge/catkin_ws/devel/setup.bash
$ export PATH=$HOME/moos-ivp/bin:$PATH
$ source moos_setup_script.sh (If you do not have moos in your local computer)
```
First terminal: </br>
$ roslaunch moosros_tester example.launch </br>
Second terminal: </br>
$ source moos_run.sh </br>
Now you can get moos-ivp's log file in ($this pkg's location)/moosros/moos/BH_cave</br>

### How to build & run this project in docker 
Clone this repo to your catkin_ws/src. For example
```
$ cd
$ mkdir -p moos-ros-bridge/catkin_ws/src
$ cd moos-ros-bridge/catkin_ws/src/
$ git clone https://github.com/ARG-NCTU/moos-ros-bridge/tree/devel-MF.git 
$ cd docker/
$ source docker_build.sh

To start a docker container(if there is not any docker container exit):
$ source docker_join.sh

Then you can open an existed container's terminal with:
$ source docker_join.sh

If you want to terminate running container
$ source docker_stop.sh
```
First terminal: </br>
$ roslaunch moosros_tester example.launch </br>
Second terminal: </br>
$ source moos_run.sh </br>
Now you can get moos-ivp's log file in ($this pkg's location)/moosros/moos/BH_cave</br>











