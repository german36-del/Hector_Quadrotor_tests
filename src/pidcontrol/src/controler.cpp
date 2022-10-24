#include "ros/ros.h"
#include <ros/console.h>
#include "pidcontrol/controler.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "nav_msgs/Odometry.h"
#include <tf/tf.h>
#include <sstream>
#include <iostream>

const std::vector<std::vector<int>> waypoints = {{0,0,8,0}, {0,0,0,0}};
const float kp = 0.3;
const float kd = 0.2;
const float ki = 0.1;
int waypopint_number = 0;



namespace pidcontrol{
LQRController::LQRController(ros::NodeHandle nh){
        pub_cmd = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
        sub_states = nh.subscribe("/ground_truth/state", 1000000000, &LQRController::Get_States, this);
    }



void LQRController::Get_States(const nav_msgs::Odometry::ConstPtr &msg){
       
          x_a = msg-> pose.pose.position.x;
          y_a = msg-> pose.pose.position.y;
          z_a = msg-> pose.pose.position.z;
          tf::Quaternion q(
            msg->pose.pose.orientation.x,
            msg->pose.pose.orientation.y,
            msg->pose.pose.orientation.z,
            msg->pose.pose.orientation.w);
          tf::Matrix3x3 m(q);
          double roll, pitch, yaw;
          m.getRPY(roll, pitch, yaw);
          orientation_z = yaw;

          this->Calculate_Control();
          
}
void LQRController::Calculate_Control(){
    
        
        error_x = waypoints[waypopint_number][0] - x_a;
        error_y = waypoints[waypopint_number][1] - y_a;
        error_z = waypoints[waypopint_number][2] - z_a;
        error_orientation = waypoints[waypopint_number][3] - orientation_z;
        
        double u__z = kp * error_z;
        geometry_msgs::Twist msg_pub;
          msg_pub.linear.x = 0;
          msg_pub.linear.y = 0;
          msg_pub.linear.z = u__z;
          msg_pub.angular.x = 0;
          msg_pub.angular.y = 0;
          msg_pub.angular.z = 0;
          pub_cmd.publish(msg_pub);
          
          ROS_INFO("error en z %f", error_z);
        if (abs(error_z) < 0.5 and waypopint_number + 1 < waypoints.size() ){
          ROS_INFO("cambio de waypoint");
          ++waypopint_number;
        }

      }
         
}



    
   
   
      

