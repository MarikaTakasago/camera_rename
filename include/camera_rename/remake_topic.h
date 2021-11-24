#ifndef REMAKE_TOPIC_H
#define REMAKE_TOPIC_H

#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Image.h>

class RemakeTopic
{
    public:
        RemakeTopic();
        void process();

    private:
        //method
        void image_callback(const sensor_msgs::Image::ConstPtr &msg);

        //param
        bool image_checker = false;

        //member

        ros::NodeHandle nh;
        ros::NodeHandle private_nh;

        ros::Subscriber sub_image;

        ros::Publisher pub_image_1;

        sensor_msgs::Image image;
};

#endif
