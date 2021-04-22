FROM ubuntu:18.04
FROM ros:melodic

MAINTAINER Chao-Chun Hsu



# INSTALLING TOOL
RUN apt-get update\
    && echo "update successfully"\
    && apt install -y vim\
    && apt install -y gnupg2\
    && apt install -y subversion\
    && echo "svn successfully" 
# INSTALLING TOOL

# INSTALLING MOOS-IVP
RUN cd ~/ \
    && svn co --trust-server-cert --non-interactive https://oceanai.mit.edu/svn/moos-ivp-aro/trunk/ moos-ivp\
    && cd moos-ivp\
    && svn update --trust-server-cert --non-interactive
# INSTALLING MOOS-IVP

RUN apt-get install -y g++  cmake  xterm\
    && apt-get install -y libfltk1.3-dev  freeglut3-dev  libpng-dev  libjpeg-dev\
    && apt-get install -y libxft-dev  libxinerama-dev   libtiff5-dev

RUN cd ~/moos-ivp\
    && ./build.sh

# SETTING MOOS-IVP VARIABLE PATH
RUN cd ~/ \
    && apt install -y wget \
    && wget http://oceanai.mit.edu/2.680/docs/.bashrc \
    && rm .bashrc \
    && mv .bashrc.1 .bashrc 
# SETTING MOOS-IVP VARIABLE PATH 

RUN apt install netbase

RUN apt-get update && apt-get install -y \ 
    ros-${ROS_DISTRO}-desktop-full \
    ros-$ROS_DISTRO-serial \
    ros-$ROS_DISTRO-soem \
    ros-$ROS_DISTRO-openslam-gmapping \
    ros-$ROS_DISTRO-geodesy \
    ros-$ROS_DISTRO-cartographer-* \
    ros-$ROS_DISTRO-ddynamic-reconfigure \
    ros-$ROS_DISTRO-perception \
    ros-$ROS_DISTRO-rgbd-launch \
    ros-$ROS_DISTRO-joystick-drivers \
    ros-$ROS_DISTRO-pointcloud-to-laserscan \
    ros-$ROS_DISTRO-robot-localization \
    ros-$ROS_DISTRO-spacenav-node \
    ros-$ROS_DISTRO-tf2-sensor-msgs \
    ros-$ROS_DISTRO-controller-manager \
    ros-$ROS_DISTRO-twist-mux \
    ros-$ROS_DISTRO-velodyne-simulator \
    ros-$ROS_DISTRO-gazebo-ros \
    ros-$ROS_DISTRO-move-base-msgs \
    ros-$ROS_DISTRO-lms1xx \
    ros-$ROS_DISTRO-rviz-imu-plugin \
    ros-$ROS_DISTRO-interactive-marker-twist-server \
    ros-$ROS_DISTRO-teleop-twist-joy \
    ros-$ROS_DISTRO-rosserial-arduino \
    ros-$ROS_DISTRO-rosserial \
    ros-$ROS_DISTRO-vision-msgs \
    python-rosdep \
    python-rosinstall \
    python-rosinstall-generator \
    python-wstool \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*


RUN cd ~/ \
    && git clone https://github.com/hsuchaochun/moos-ros-bridge.git \
    && cd ..\
    && echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc\
    && echo "source ~/moos-ros-bridge/catkin_ws/devel/setup.bash" >> ~/.bashrc
#    && /bin/bash -c 'source /opt/ros/melodic/setup.bash;catkin_make'




