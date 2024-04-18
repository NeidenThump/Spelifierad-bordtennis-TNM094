#include "websocket/websocketClient.h"

bool WebSocketClient::connect() {
    try {
        auto const results = resolver.resolve(host, port);
        net::connect(ws.next_layer(), results.begin(), results.end());
        ws.set_option(websocket::stream_base::decorator(
            [](websocket::request_type& req) {
                req.set(http::field::user_agent,
                std::string(BOOST_BEAST_VERSION_STRING) +
                " websocket-client-coro");
            }));
        ws.handshake(host, "/");
        return true;
    }
    catch (std::exception const& e) {
        std::cerr << "Connect error: " << e.what() << std::endl;
        return false;
    }
}

void WebSocketClient::send(const std::string& message) {
    ws.write(net::buffer(message));
}

std::string WebSocketClient::read() {
    beast::flat_buffer buffer;
    try {
        ws.read(buffer);
    }
    catch (std::exception const& e) {
        std::cerr << "Read error: " << e.what() << std::endl;
    }
    return beast::buffers_to_string(buffer.data());
}

std::pair<int, int> readCoordinates(const std::string& input) {
    // Find positions of 'X' and 'Y'
    size_t xPos = input.find('X');
    size_t yPos = input.find('Y');


    if (xPos == std::string::npos || yPos == std::string::npos || xPos > yPos) {
        throw std::invalid_argument("Invalid input format");
    }


    // Extract numeric parts for x and y
    std::string xPart = input.substr(xPos + 1, yPos - xPos - 1);
    std::string yPart = input.substr(yPos + 1);

    // Check if the substrings are non-empty and contain only digits
    if (xPart.empty() || yPart.empty() || xPart.find_first_not_of("0123456789") != std::string::npos ||
        yPart.find_first_not_of("0123456789") != std::string::npos) {
        throw std::invalid_argument("Coordinates must be numeric");
    }

    // Convert extracted strings to integers
    int x = std::stoi(xPart);
    int y = std::stoi(yPart);

    return { x, y };
}

