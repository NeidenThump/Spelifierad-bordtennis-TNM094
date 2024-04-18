#pragma once
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdexcept> // For std::invalid_argument exception

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>


class WebSocketClient {
private:
    net::io_context ioc;
    tcp::resolver resolver{ ioc };
    websocket::stream<tcp::socket> ws{ ioc };
    std::string host;
    std::string port;

public:
    WebSocketClient(const std::string& host, const std::string& port) : host(host), port(port) {}

    bool connect();

    void send(const std::string& message);

    std::string read();

    void close() {
        ws.close(websocket::close_code::normal);
    }
    // Check if the WebSocket connection is still open
    bool isConnected() {
        return ws.is_open();
    }
};

std::pair<int, int> readCoordinates(const std::string& input);
