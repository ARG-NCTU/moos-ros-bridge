#include "ros/ros.h"
#include "geometry_msgs/PoseStamped.h"
#include <sstream>

int main (int argc, char **argv)
{
     ros::init(argc, argv, "robot_simulator");
     ros::NodeHandle n;
     ros::Publisher chatter_pub = n.advertise<geometry_msgs::PoseStamped>("robot_pose", 1000);

     ros::Rate loop_rate(1);

     geometry_msgs::PoseStamped msg;

     std::stringstream ss;
     ss << "testing poseStamped";
     msg.header.frame_id = ss.str();
     msg.pose.position.x = 5.0;
     msg.pose.position.y = 6.0;
     msg.pose.position.z = 0.1;
     msg.pose.orientation.x = 0.3;
     msg.pose.orientation.y = 0.4;
     msg.pose.orientation.z = 0.5;
     msg.pose.orientation.w = 0.6;     
     while (ros::ok()) {
          msg.header.stamp = ros::Time::now();
	     chatter_pub.publish(msg);
	     ros::spinOnce();
	     loop_rate.sleep();
     }


     return 0;
}
