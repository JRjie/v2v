#ifndef BLOCK_PUBLISHER_HPP
#define BLOCK_PUBLISHER_HPP

#include <chrono>
#include <memory>
#include <string>
#include <vector>
#include <thread>
#include <memory>

#include <rclcpp/rclcpp.hpp>

#include <boost/asio.hpp>

#include "my_interface/posture_array.hpp"

namespace block
{
class PublisherNode : public rclcpp::Node {
  public:
    explicit PublisherNode(const rclcpp::NodeOptions & options);
    explicit ~PublisherNode();

  private:
    rclcpp::Publisher<my_interfaces::msg::PostureArray>::SharedPtr publisher;
    void CreateUDP(const io_service &io, const int &port);

  private:
    int port;
    io_service io_service;
    std::vector<char> receive_buffer;
    std::unique_ptr<boost::asio::ip::udp::socket> socket;
    std::thread udp_thread;

};

} // namespace
#endif
