cmake_minimum_required(VERSION 2.8.3)
project(moosros_tester)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  rostopic
  std_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(counter src/counter.cpp)
target_link_libraries(counter ${catkin_LIBRARIES})