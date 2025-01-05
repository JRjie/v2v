#ifndef BLOCK_PUBLISHER_HPP
#define BLOCK_PUBLISHER_HPP

#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class PublisherNode : public rclcpp::Node
{
  public:
    PublisherNode()
    : Node("publisher_node")
    {

    }

    private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    
};


#endif
