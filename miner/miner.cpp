#include "miner.h"
#include "../src/block.h"
#include <iostream>

Block mineBlock(int index, const std::string& prevHash, const std::vector<Transaction>& txs, int difficulty) {
    Block block(index, prevHash, txs);
    std::string target(difficulty, '0');

    while (block.hash.substr(0, difficulty) != target) {
        block.nonce++;
        block.hash = block.calculateHash();
    }
    std::cout << "✅ Block mined: " << block.hash << std::endl;
    return block;
}
