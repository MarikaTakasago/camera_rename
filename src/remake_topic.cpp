#include "camera_rename/remake_topic.h"

RemakeTopic::RemakeTopic():private_nh("~")
{
    sub_image = nh.subscribe("/camera/color/image_rect_color",100,&RemakeTopic::image_callback,this);

    pub_image_1 = nh.advertise<sensor_msgs::Image>("/roomba1/memera/color/image_rect_color",100);
}

void RemakeTopic::image_callback(const sensor_msgs::Image::ConstPtr &msg)
{
    image = *msg;
    image_checker = true;
    if(image_checker)
    {
        std::cout << image.header.frame_id << std::endl;

        if(image.header.frame_id == "roomba1")
        {
            image.header.frame_id = "camera_color_optical_frame";
            pub_image_1.publish(image);
        }
    }
}

void RemakeTopic::process()
{
    ros::Rate rate(10);
    while(ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
    }
}

int main(int argc, char** argv)
{
    ros::init(argc,argv,"remake_topic");
    RemakeTopic remake_t;
    remake_t.process();
    return 0;
}
