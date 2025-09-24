#pragma once
#include "block.h"
#include <vector>

class Blockchain {
public:
    std::vector<Block> chain;
    int difficulty;

    Blockchain();
    Block getLatestBlock() const;
    void addBlock(const Block& newBlock);
    bool isChainValid() const;
};
