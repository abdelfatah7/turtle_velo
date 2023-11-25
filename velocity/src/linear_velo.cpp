#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle_velocity_publisher");

  ros::NodeHandle n;

  ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 50);

  ros::Rate loop_rate(10);

  while (ros::ok())
  {
   geometry_msgs::Twist vel_msg;

   vel_msg.linear.x = 0.5;
   vel_msg.angular.z = 0.0;

    cmd_vel_pub.publish(vel_msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}