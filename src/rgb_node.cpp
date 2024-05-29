#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <iostream>

int main(int argc, char** argv) {
  ros::init(argc, argv, "rgb");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::Int32>("/computer/traffic_light/cmd", 2);
  std::string buf;
  std::cin >> buf;
  while (buf != "c" && ros::ok()) {
    std_msgs::Int32 msg;
    switch (buf[0]) {
    case 'R':
      msg.data = 4;
      break;
    case 'G':
      msg.data = 2;
      break;
    case 'B':
      msg.data = 3;
      break;
    default:
      break;
    }
    pub.publish(msg);
    std::cin >> buf;
  }
}
