#include <ros/ros.h>
#include <ros/console.h>
#include "pidcontrol/controler.h"
#include <iostream>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "lqr_controller");
  ros::NodeHandle nh;
  pidcontrol::LQRController lqr_controller(nh);
  ros::spin();

  return 0;
}
