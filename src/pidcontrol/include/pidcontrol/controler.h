#include <ros/ros.h>
#include "nav_msgs/Odometry.h"
#include <ros/console.h>


namespace pidcontrol{
class LQRController{ 

public:

    LQRController(ros::NodeHandle nh);

    ~LQRController(){ 
    }
    double x_a;
    double y_a;
    double z_a;
    double orientation_z;
    double error_x;
    double error_y;
    double error_z;
    double error_orientation;


    void Calculate_Control();
    void Get_States(const nav_msgs::Odometry::ConstPtr &msg);
    ros::Publisher pub_cmd;
    ros::Subscriber sub_states;
    



};
}