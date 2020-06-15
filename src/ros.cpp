#include <topic_offset/ros.h>


namespace topic_offset {

void TopicOffsetROS::init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh) {

    ROS_INFO ("Initializing TopicOffsetROS...");
    nh_ = public_nh;
    private_nh_ = private_nh;
    reconfigureFnc_ = boost::bind ( &TopicOffsetROS::callbackConfigLocalPlanner, this,  _1, _2 );
    reconfigureServer_.setCallback ( reconfigureFnc_ );
    sub_imu_ = nh_.subscribe("imu", 10, &TopicOffsetROS::callbackIMU, this);
    sub_cloud_ = nh_.subscribe("points2", 10, &TopicOffsetROS::callbackPoints2, this);
}


void TopicOffsetROS::callbackConfigLocalPlanner ( topic_offset::TopicOffsetConfig &config, uint32_t level ) {
    ROS_INFO ("callbackConfig");
    config_ = config;
}

void TopicOffsetROS::callbackIMU(const sensor_msgs::Imu::ConstPtr &msg) {
    ROS_INFO ("callbackIMU");
    bool trigger;
    
}

void TopicOffsetROS::callbackPoints2(const sensor_msgs::PointCloud2::ConstPtr &msg) {
    ROS_INFO ("callbackPoints2");
}

}
