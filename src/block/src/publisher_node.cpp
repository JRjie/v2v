#ifndef PUBLISHER_NODE_CPP
#define PUBLISHER_NODE_CPP

#include "block/publisher_node.hpp"
namespace block
{

PublisherNode::PublisherNode(const rclcpp::NodeOptions &options)
: rclcpp::Node("publisher_node", options)
{
  this->declare_parameter("port", 12345);
  port = this->get_parameter("port").as_int();

  publisher = this->create_publisher<my_interfaces::msg::PostureArray>("posture_array", rclcpp::QoS(10));
  
  socket = std::make_unique<boost::asio::ip::udp::socket>(io_service, udp::endpoint(udp::v4(), port));

  udp_thread = std::thread([this]() {
    CreateUDP();
    io_service.run();
  });
}

PublisherNode::~PublisherNode()
{
  io_service.stop();
  if(upd_thread.joinable())
  {
    udp_thread.join();
  }
}

void PublisherNode::CreateUDP(const io_service &io, const int &port)
{

}

} //namespace
#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(block::PublisherNode)
