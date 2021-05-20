#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
     ros::init(argc, argv, "counter");
     ros::NodeHandle n;
     ros::Publisher chatter_pub = n.advertise<std_msgs::Float64>("pub2moos/VEH_LAT", 1000);
     //ros::Publisher chatt_pub = n.advertise<std_msgs::String>("pubmoos/TASK_NAME", 1000);

     ros::Rate loop_rate(1);

     int count = 0;
     std_msgs::Float64 msg;
     while (ros::ok()) {

	  msg.data = count;

	  chatter_pub.publish(msg);
//	  chatt_pub.publish(msg);

	  ros::spinOnce();

	  loop_rate.sleep();
	  ++count;
     }


     return 0;
}
