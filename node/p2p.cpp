#include "p2p.h"
#include <iostream>

P2PNode::P2PNode(int p) {
    port = p;
}

void P2PNode::connectToPeer(const std::string& address) {
    peers.push_back(address);
    std::cout << "Connected to peer: " << address << std::endl;
}

void P2PNode::broadcast(const std::string& message) {
    for (auto& peer : peers) {
        std::cout << "Broadcast to " << peer << ": " << message << std::endl;
    }
}
