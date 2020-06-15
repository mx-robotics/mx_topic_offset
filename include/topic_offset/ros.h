#ifndef TOPIC_OFFSET_ROS_H
#define TOPIC_OFFSET_ROS_H

#include <ros/ros.h>

#include <sensor_msgs/LaserScan.h>
#include <dynamic_reconfigure/server.h>
#include <topic_offset/TopicOffsetConfig.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Imu.h>


namespace topic_offset {

class TopicOffsetROS {
    
private:
    ros::Subscriber sub_cloud_;
    ros::Subscriber sub_imu_;
    ros::Publisher pub_offest;
    ros::Timer timer_;
    ros::NodeHandle nh_;
    ros::NodeHandle private_nh_;
    topic_offset::TopicOffsetConfig config_;
    dynamic_reconfigure::Server<topic_offset::TopicOffsetConfig> reconfigureServer_; /// parameter server stuff
    dynamic_reconfigure::Server<topic_offset::TopicOffsetConfig>::CallbackType reconfigureFnc_;  /// parameter server stuff
    void callbackConfigLocalPlanner ( topic_offset::TopicOffsetConfig &config, uint32_t level ); /// callback function on incoming parameter changes

public:
    void init(ros::NodeHandle &public_nh, ros::NodeHandle &private_nh);
    void callbackPoints2 ( const sensor_msgs::PointCloud2::ConstPtr &msg);
    void callbackIMU ( const sensor_msgs::Imu::ConstPtr& msg);

};
}

#endif  // TOPIC_OFFSET_ROS_H
