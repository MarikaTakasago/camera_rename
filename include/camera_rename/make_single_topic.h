#ifndef MAKE_SINGLE_TOPIC_H
#define MAKE_SINGLE_TOPIC_H

#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Image.h>

class MakeSingleTopic
{
    public:
        MakeSingleTopic();
        void process();

    private:
        //method
        void image_callback_1(const sensor_msgs::Image::ConstPtr &msg);
        void image_callback_2(const sensor_msgs::Image::ConstPtr &msg);
        void image_callback_3(const sensor_msgs::Image::ConstPtr &msg);
        void image_callback_4(const sensor_msgs::Image::ConstPtr &msg);
        void image_callback_5(const sensor_msgs::Image::ConstPtr &msg);
        void image_callback_6(const sensor_msgs::Image::ConstPtr &msg);

        //param
        bool image_checker_1 = false;
        bool image_checker_2 = false;
        bool image_checker_3 = false;
        bool image_checker_4 = false;
        bool image_checker_5 = false;
        bool image_checker_6 = false;


        //member
        ros::NodeHandle nh;
        ros::NodeHandle private_nh;

        ros::Subscriber sub_image_1;
        ros::Subscriber sub_image_2;
        ros::Subscriber sub_image_3;
        ros::Subscriber sub_image_4;
        ros::Subscriber sub_image_5;
        ros::Subscriber sub_image_6;

        ros::Publisher pub_image;

        sensor_msgs::Image image_1;
        sensor_msgs::Image image_2;
        sensor_msgs::Image image_3;
        sensor_msgs::Image image_4;
        sensor_msgs::Image image_5;
        sensor_msgs::Image image_6;
};

#endif





