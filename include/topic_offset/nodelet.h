#ifndef TOPIC_OFFSET_NODELET_H
#define TOPIC_OFFSET_NODELET_H

#include <nodelet/nodelet.h>
#include <topic_offset/ros.h>


namespace topic_offset {


class TopicOffsetNodelet: public TopicOffsetROS, public nodelet::Nodelet {
public:
    virtual void onInit();
};

}

#endif  // TOPIC_OFFSET_NODELET_H
