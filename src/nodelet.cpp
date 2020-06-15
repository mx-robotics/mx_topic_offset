#include <topic_offset/nodelet.h>
#include <pluginlib/class_list_macros.h>

    
namespace topic_offset {

void TopicOffsetNodelet::onInit() {

    NODELET_INFO ("Initializing nodelet TopicOffsetNodelet...");
        TopicOffsetROS::init(getNodeHandle(), getPrivateNodeHandle());
}
}


PLUGINLIB_EXPORT_CLASS (topic_offset::TopicOffsetNodelet, nodelet::Nodelet)
//int main(int argc, char **argv) {}
