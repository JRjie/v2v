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
    StartReceive();
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

void PublisherNode::StartReceive(const io_service &io, const int &port)
{
  socket->async_receive_from(
    boost::asio::buffer(receive_buffer), remote_endpoint_,
    [this](const boost::system::error_code &error, std::size_t bytes_transferred)
    {
      HandleReceive(error, bytes_transferred);
    }
  );
}

void PublisherNode::HandleReceive(const boost::system::error_code &error, size_t bytes_transferred)
{
  if(!error && bytes_transferred > 0)
  {
    // 将数据转换为字符串
    std::string data(recv_buffer.data(), bytes_transferred);
    
    auto msg = Split(data);

    publisher->publish(msg);
            
    RCLCPP_INFO(this->get_logger(), "Received and published: '%s'", data.c_str());
  }
  StartReceive();
}

my_interfaces::msg::PostureArray PublisherNode::Split(const std::string &data)
{
  //my_id@id1.x1.y1.z1.p1.y1.r1.t1.h1|id2.x2.y2.z2.p2.y2.r2.t2.h2| ... 
  
}

} //namespace
#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(block::PublisherNode)
