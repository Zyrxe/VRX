#pragma once
#include <string>
#include <vector>

class P2PNode {
public:
    int port;
    std::vector<std::string> peers;

    P2PNode(int p);
    void connectToPeer(const std::string& address);
    void broadcast(const std::string& message);
};
