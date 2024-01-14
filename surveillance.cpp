#include <ros/ros.h>  
#include <geometry_msgs/Twist.h>  
#include <geometry_msgs/TwistWithCovariance.h>
  
void VelocityCallback(const geometry_msgs::Twist::ConstPtr& msg)  
{  
    // 在这里处理接收到的速度控制消息  
    float linear = msg->linear.x; // 线性速度x分量  
    float angular = msg->angular.z; // 角速度z分量  
    // ... 进行其他处理 ...  
//	ROS_INFO("|||||||||||||||");
    if (linear < 0.4) {
        ROS_INFO("                                                    ");
        ROS_INFO("        ##           ##                             ");
        ROS_INFO("         ##         ##               ##     ##      ");
        ROS_INFO("     ####################    ##  ################   ");
        ROS_INFO("                             ##      ##     ##      ");
        ROS_INFO("          ####      ##       ##  ################   ");
        ROS_INFO("          #  #      ##       ##      ##     ##      ");
        ROS_INFO("          ####  ##  ##       ##      ##     ##      ");
        ROS_INFO("          #  #  ##  ##       #####################  ");
        ROS_INFO("          ####  ##  ##                              ");
        ROS_INFO("          #  #      ##                              ");
        ROS_INFO("                                                    ");

    }
    else if (linear > 1){
        ROS_INFO("                                                    ");
        ROS_INFO("        ##########   ####        ####  ############                            ");
        ROS_INFO("        ##########   ####        ####  #############                             ");
        ROS_INFO("        ##########   ####        ####  ####        ##                    ");
        ROS_INFO("        ##########   ####        ####  ####     ###                      ");
        ROS_INFO("        ##########   ####        ####  ####   ###                         ");
        ROS_INFO("           ####      ####        ####  #### ###                       ");
        ROS_INFO("           ####      ####        ####  #######                         ");
        ROS_INFO("           ####      ####        ####  ####  ###                      ");
        ROS_INFO("           ####      ####        ####  ####    ###                    ");
        ROS_INFO("           ####      ####        ####  ####     ###                    ");
        ROS_INFO("           ####        ############    ####      ###                       ");
        ROS_INFO("           ####         ##########     ####       ###                     ");
        ROS_INFO("                                                    ");
        ROS_INFO("                                                    ");

    }


    //  ROS_DEBUG_STREAM("The speed of linear is: " << linear);
  //  ROS_DEBUG_STREAM("The speed of angular is: " << angular);

} 

void odomCallback(const geometry_msgs::TwistWithCovariance::ConstPtr &odom_msg)
{
     double velocity_ = odom_msg->twist.linear.x;
     ROS_INFO("Current speed is : %f \nCurrent speed is :%f \nCurrent speed is :%f \nCurrent speed is :%f \nCurrent speed is :%f \n\n\n", velocity_, velocity_, velocity_, velocity_, velocity_);
}

  
int main(int argc, char** argv)  
{  
    ros::init(argc, argv, "surveillance");  
    ros::NodeHandle nh_1;  


//ros::Rate loop_rate(1);

	while(ros::ok()){
        ros::Subscriber sub = nh_1.subscribe("my_topic", 10, VelocityCallback); // 订阅发布者发布的主题
        ros::Subscriber odom_sub_ = nh_1.subscribe<geometry_msgs::TwistWithCovariance>("/wheel_odom", 10, odomCallback);
    //    ros::spinOnce();
	//	loop_rate.sleep();
	ros::spin();
	}

    return 0;  
}
