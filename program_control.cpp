/**
 * 该例程将发布chatter话题，消息类型String
 */
 
#include <sstream>
#include <iostream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "geometry_msgs/Twist.h"


/*
int linear_state_;
int  angular_state_;
*/
    ///////////////////////////////////////////////////////////////
    ////setting initial scale, now is 0.2 and 0.5 respectively/////
    ///////////////////////////////////////////////////////////////
float    linear_scale_ = 0.2;
float linear_min_ =  0.2;
float    angular_scale_ = 0.2;
float angular_min_ = 0.5;



//int velocity_state_number = 0;
int direction_state_number = 0;

std::string ich_mochte_alles_torten;

//std_msgs::String direction_state_number = '0';


geometry_msgs::Twist twist;

ros::Subscriber command_sub_velocity;
ros::Subscriber command_sub_direction;
/*
void VelocityCallBack(const std_msgs::String::ConstPtr& msg){
    velocity_state_number =  msg->data;
    // 将接收到的消息打印出来
    ROS_INFO("I heard the velocity is: [%s]", msg->data.c_str());
   // ROS_INFO("%d",velocity_state_number);
}
*/

void DirectionCallBack(const std_msgs::String::ConstPtr& msg){
	ich_mochte_alles_torten =  msg->data;    // 将接收到的消息打印出来
	direction_state_number = std::stoi(ich_mochte_alles_torten);
	ROS_INFO("I heard the direction is: [%d]", direction_state_number);
/*
if(ich_mochte_alles_torten == '4')
direction_state_number = 4;
*/
}

void Straight(){
return ;
        //    ROS_INFO("%f %f" , twist.linear.x, twist.angular.z);
}
void Left(){
    return;
}

void Right(){
    return;
}

void KeepSpeed(){
    return;
}

void Acceleration(){
    return;
}

void Deceleration(){
    return;
}

bool img_read(){
    return 1;

}

bool vdo_read(){
    return 1;
}



    int main(int argc, char **argv) {
        // ROS节点初始化
        ros::init(argc, argv, "program_control");
        ros::NodeHandle GOD;
        ros::Publisher twist_pub_ = GOD.advertise<geometry_msgs::Twist>("my_topic",10);

        ROS_INFO("INFO: The car is starting!!!!");
        ROS_INFO("INFO: The car is starting!!!!");
        ROS_INFO("INFO: The car is starting!!!!");
        ROS_INFO("INFO: The car is starting!!!!");
        ROS_INFO("\n\n\n\n\n\n\n\n\n\n\n\n");  
    ROS_INFO(     "                          i  i  i                         ");
     ROS_INFO(    "                   |~~~~~~~~~~~~~~~~~~|                   ");
    ROS_INFO(     "                   |~~~~~~~~~~~~~~~~~~|                   ");
     ROS_INFO(    "                   |~~~~~~~~~~~~~~~~~~|                   ");
     ROS_INFO(    "                   |~~~~~~~~~~~~~~~~~~|                   ");
     ROS_INFO(    "                   |~~~~~~~~~~~~~~~~~~|                   ");
      ROS_INFO(   "                 __|~~~~~~~~~~~~~~~~~~|__                 ");
      ROS_INFO(   "                |________________________|                ");
        ROS_INFO("\n\n\n\n\n");  

            command_sub_direction = GOD.subscribe("command_direction", 1000, DirectionCallBack); // 订阅发布者发布的主题
/*
            command_sub_velocity = GOD.subscribe("command_velocity", 1000, VelocityCallBack);
*/ // 订阅发布者发布的主题

        while (ros::ok()) {


/*
            if (velocity_state_number == 0)
                twist.linear.x = 2 * linear_scale_;

      //          KeepSpeed();
            else if (velocity_state_number == 1)
                twist.linear.x = 0.5 * linear_scale_;

     //           Deceleration();
            else if (velocity_state_number == 2)
                twist.linear.x = 4 * linear_scale_;

       //         twist_pub_.publish(twist);
    //            Acceleration();

*/
            if (direction_state_number == 4)   {
                twist.angular.z = 0 * angular_scale_;
		twist.linear.x = 1.6*5 * linear_scale_;
}

       //         Straight();
            else if (direction_state_number == 5){
                twist.angular.z = 1 * angular_scale_;
		twist.linear.x = 1 * linear_scale_;
}
       //         Left();
            else if (direction_state_number == 6){
                twist.angular.z = -1 * angular_scale_;
		twist.linear.x = 1 * linear_scale_;
}
            twist_pub_.publish(twist);

      //          Right();

            ros::spinOnce();

          //  run();

        }
        return 0;
    }
