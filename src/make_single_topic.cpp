#include "camera_rename/make_single_topic.h"

MakeSingleTopic::MakeSingleTopic():private_nh("~")
{
    sub_image_1 = nh.subscribe("/roomba1/camera/color/image_rect_color",100,&MakeSingleTopic::image_callback_1,this);
    sub_image_2 = nh.subscribe("/roomba2/camera/color/image_rect_color",100,&MakeSingleTopic::image_callback_2,this);
    sub_image_3 = nh.subscribe("/roomba3/camera/color/image_rect_color",100,&MakeSingleTopic::image_callback_3,this);
    sub_image_4 = nh.subscribe("/roomba4/camera/color/image_rect_color",100,&MakeSingleTopic::image_callback_4,this);
    sub_image_5 = nh.subscribe("/roomba5/camera/color/image_rect_color",100,&MakeSingleTopic::image_callback_5,this);
    sub_image_6 = nh.subscribe("/roomba6/camera/color/image_rect_color",100,&MakeSingleTopic::image_callback_6,this);

    pub_image = nh.advertise<sensor_msgs::Image>("/camera/color/image_rect_color",100);
}

void MakeSingleTopic::image_callback_1(const sensor_msgs::Image::ConstPtr &msg)
{
    image_1 = *msg;
    image_checker_1 = true;
    if(image_checker_1)
    {
        std::cout << "1:" << image_1.header.frame_id << std::endl;
        image_1.header.frame_id = "roomba1";
        pub_image.publish(image_1);
    }
}

void MakeSingleTopic::image_callback_2(const sensor_msgs::Image::ConstPtr &msg)
{
    image_2 = *msg;
    image_checker_2 = true;
    if(image_checker_2)
    {
        std::cout << "2:" << image_2.header.frame_id << std::endl;
        image_2.header.frame_id = "roomba2";
        pub_image.publish(image_2);
    }
}

void MakeSingleTopic::image_callback_3(const sensor_msgs::Image::ConstPtr &msg)
{
    image_3 = *msg;
    image_checker_3 = true;
    if(image_checker_3)
    {
        std::cout << "3:" << image_3.header.frame_id << std::endl;
        image_3.header.frame_id = "roomba3";
        pub_image.publish(image_3);
    }
}

void MakeSingleTopic::image_callback_4(const sensor_msgs::Image::ConstPtr &msg)
{
    image_4 = *msg;
    image_checker_4 = true;
    if(image_checker_4)
    {
        std::cout << "4:" << image_4.header.frame_id << std::endl;
        image_4.header.frame_id = "roomba4";
        pub_image.publish(image_4);
    }
}

void MakeSingleTopic::image_callback_5(const sensor_msgs::Image::ConstPtr &msg)
{
    image_5 = *msg;
    image_checker_5 = true;
    if(image_checker_5)
    {
        std::cout << "5:" << image_5.header.frame_id << std::endl;
        image_5.header.frame_id = "roomba5";
        pub_image.publish(image_5);
    }
}

void MakeSingleTopic::image_callback_6(const sensor_msgs::Image::ConstPtr &msg)
{
    image_6 = *msg;
    image_checker_6 = true;
    if(image_checker_6)
    {
        std::cout << "6:" << image_6.header.frame_id << std::endl;
        image_6.header.frame_id = "roomba6";
        pub_image.publish(image_6);
    }
}

void MakeSingleTopic::process()
{
    ros::Rate rate(10);
    while(ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
    }
}

int main(int argc,char** argv)
{
    ros::init(argc,argv,"make_single_topic");
    MakeSingleTopic single_t;
    single_t.process();
    return 0;
}
