
#include "ros/ros.h"
#include "std_msgs/Int32.h"

#include <sstream>

int main(int argc, char **argv)
{
     ros::init(argc, argv, "counter");
     ros::NodeHandle n;
     ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("counter", 1000);

     ros::Rate loop_rate(1);

     int count = 556;
     std_msgs::Int32 msg;
     while (ros::ok()) {

	  msg.data = count;

	  chatter_pub.publish(msg);

	  ros::spinOnce();

	  loop_rate.sleep();
     }


     return 0;
}