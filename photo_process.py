import cv2
import numpy as np
import os
import rospy
from std_msgs.msg import String

path = 'ImagesQuery'
images = []
className = []
myList = os.listdir(path)
print('Total Classes Detected', len(myList))
cap = cv2.VideoCapture(0)


pub = rospy.Publisher('command_direction', String, queue_size=10)
rospy.init_node('photo_process')


while not rospy.is_shutdown():
    hello_str = 'hello %s' % rospy.get_time()

   # rospy.loginfo(hello_str)
    #pub.publish(hello_str)

    success, img = cap.read()
    imgOriginal = img.copy()
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    scores = []
    final = []
    for i in range(4):
        template = cv2.imread('ImagesQuery/' + myList[i])
        template = cv2.cvtColor(template, cv2.COLOR_BGR2GRAY)
        res = cv2.matchTemplate(img_gray, template, cv2.TM_CCORR_NORMED)
        (_, score, _, _) = cv2.minMaxLoc(res)
        threshold = 0.8
        h, w = template.shape[:2]
        if score > 0.90:
            print(myList[i])
            if myList[i] == 'Left.png':
                hello_str = '5'
                pub.publish(hello_str)
            elif myList[i] == 'Right.png':
                hello_str = '6'
                pub.publish(hello_str)
            elif myList[i] == 'Forward.png':
                hello_str = '4'
                pub.publish(hello_str)
            loc = np.where(res >= threshold)
            for pt in zip(*loc[::-1]):
                bottom_right = (pt[0] + w, pt[1] + h)
                cv2.rectangle(img, pt, bottom_right, (0, 0, 255), 1)
    cv2.imshow('img', img)
    cv2.waitKey(1)


