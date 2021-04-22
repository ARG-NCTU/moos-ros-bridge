cmake_minimum_required(VERSION 2.8.3)
project(posestamped_sim)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  geometry_msgs
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(posestamped_sim src/posestamped_sim.cpp)
target_link_libraries(posestamped_sim ${catkin_LIBRARIES})