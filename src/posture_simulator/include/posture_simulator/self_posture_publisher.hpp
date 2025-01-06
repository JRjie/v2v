#ifndef SELF_POSTURE_PUBLISHER_HPP
#define SELF_POSTURE_PUBLISHER_HPP

#include <chrono>
#include <memory>
#include <boost/asio.hpp>

#include "rclcpp/rclcpp.hpp"

class SelfPosturePublisher : public rclcpp::Node
{
  public:
    SelfPosturePublisher()
    : Node("self_posture_publisher"){}

    
};

#endif
