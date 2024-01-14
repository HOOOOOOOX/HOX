Extensible framework for traffic signal detection
==

>This is a function package for traffic signal detection and driving Autolabor Pro 1. The function includes going straight, turning right and turning right by the perception of camera form a camera. Now the whole package can only read the camera information form the camera embed in the laptop, if you want to use the camera information for usb_camera, you need to modify the topic name in the profile photo_process.py. The current image information is acquired via OpenCV.

####

**Modifier:** [Chenshuo Tang]  @[**huoxiaohnn@163.com**]()

**Cofounder:** [Chenhui He, Ye Wu]
###

## 1. Prerequisites
### 1.1 **Ubuntu** and **ROS**
>Ubuntu 18.04.
ROS Melodic.

### 1.2 **OpenCV**

>To exploit the the detect function, you must install OpenCV and config properly.
* *the version of OpenCV may have a effect on the result. OpenCV 3.2.0 and OpenCV 3.4.11 have been proven to be effective
### 1.3 **Kinect_V2**

>To connect the camera embed in the Autolabor Pro 1, the relevant drivers are needed.
#####
#
## 2. Run the system
#####
~~~
$ catkin_make
$ roscore
$ source devel/setup.bash
~~~

#####
### 2.1 program_control
#####
~~~
$ rosrun traffic_detection rosrun program_control
~~~
#####
### 2.2 surveillance
#####
~~~
$ rosrun traffic_detection rosrun surveillance
~~~
#####
### 2.3 photo_process
#####
~~~
$ ./photo_process.py
~~~
* *a python file is a executable program, you can directly run from the directory.
However, if it doesn't work, you are supposed to run from an IDE like PyCharm, the topic will be sent to the target node.
#####
###

#####
## 3. Simulation
>If you have no condition running the code on a real car, we have provide you a program to simulate the track.

### 3.1 Start the simulator

~~~
$ rosrun traffic_detection simulate_publisher.
~~~

* *if you start successfully, you can see the icons in the surveillance window implicating the targeted routine
* *for the lack of time to test, we cannot guarantee that the routine is circuit.


#####
## 4. Result
>The system can concern the Straight ,Left and Right sign and drive the  Autolabor Pro 1 go to the respect direction.

* *the default speed may be fast, you must pay enough attention to the surroundings in case of emergency and we have no charge for the damage car aroused.


##

---
2024.1.13
