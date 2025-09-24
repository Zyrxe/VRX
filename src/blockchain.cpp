#include "blockchain.h"
#include "../miner/miner.h"
#include <iostream>

Blockchain::Blockchain() {
    // Genesis block
    Transaction genesisTx;
    genesisTx.outputs.push_back({1000000, "VRX_FOUNDER"});
    std::vector<Transaction> txs = {genesisTx};
    Block genesis(0, "0", txs);
    chain.push_back(genesis);
    difficulty = 4;
}

Block Blockchain::getLatestBlock() const {
    return chain.back();
}

void Blockchain::addBlock(const Block& newBlock) {
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid() const {
    for (size_t i = 1; i < chain.size(); i++) {
        if (chain[i].hash != chain[i].calculateHash()) return false;
        if (chain[i].prevHash != chain[i - 1].hash) return false;
    }
    return true;
}
