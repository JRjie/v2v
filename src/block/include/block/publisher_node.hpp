#ifndef BLOCK_PUBLISHER_HPP
#define BLOCK_PUBLISHER_HPP

#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>

#include "my_interface/posture_array.hpp"

namespace block
{
class PublisherNode : public rclcpp::Node {
  public:
    explicit PublisherNode(const rclcpp::NodeOptions & options);

  private:
    rclcpp::Publisher<my_interfaces::msg::PostureArray>::SharedPtr publisher;


};

} // namespace
#endif
