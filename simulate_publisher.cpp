//
// Created by huoxiao on 2024/1/11.
//

#include <ros/ros.h>
#include <std_msgs/Int32.h>

    std_msgs::Int32 velocity_msg;
    std_msgs::Int32 direction_msg;

int main(int argc, char** argv){
    ros::init(argc, argv, "control_simulation");
    ros::NodeHandle DOG;
//    ros::Rate loop_rate(1);

    ros::Publisher velocity_pub = DOG.advertise<std_msgs::Int32>("command_velocity", 10);
    ros::Publisher direction_pub = DOG.advertise<std_msgs::Int32>("command_direction", 10);
/*
    int velocity_msgs[3] = {0,1,2};
    int direction_msgs[3] = {4,5,6};
*/

    while (ros::ok()){


    velocity_msg.data = 0;
    velocity_pub.publish(velocity_msg);

    ROS_INFO("%d \n", velocity_msg);
 /*   velocity_msg.data = 1;
    velocity_pub.publish(velocity_msg);
    ROS_INFO("%d \n", velocity_msg);
    velocity_msg.data = 2;
    velocity_pub.publish(velocity_msg);
    ROS_INFO("%d \n", velocity_msg);
*/

 
  //  direction_msg.data = direction_msgs[rand() % 3];
/*
    direction_msg.data = 4;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);

*/
ros::Rate loop_rate(10);

for(int i=1;i<=80;i++){
    direction_msg.data = 4;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}


for(int i=1;i<=40;i++){
    direction_msg.data = 5;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}

for(int i=1;i<=30;i++){
    direction_msg.data = 4;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}


for(int i=1;i<=20;i++){
    direction_msg.data = 6;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}

for(int i=1;i<=40;i++){
    direction_msg.data = 4;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}

for(int i=1;i<=20;i++){
    direction_msg.data = 5;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}

for(int i=1;i<=40;i++){
    direction_msg.data = 4;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}


for(int i=1;i<=10;i++){
    direction_msg.data = 5;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}

for(int i=1;i<=40;i++){
    direction_msg.data = 4;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}

for(int i=1;i<=60;i++){
    direction_msg.data = 5;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}

for(int i=1;i<=100;i++){
    direction_msg.data = 4;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}

for(int i=1;i<=10;i++){
    direction_msg.data = 5;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
        ros::spinOnce();
        loop_rate.sleep();
}



/*    direction_msg.data = 5;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);

*/
/*
    direction_msg.data = 6;
    direction_pub.publish(direction_msg);
    ROS_INFO("%d \n", direction_msg);
*/


  //      ros::spin();
        ros::spinOnce();
        loop_rate.sleep();

        //ros::sleep();
    }

    return  0;
}

