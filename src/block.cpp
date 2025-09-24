#include "block.h"
#include "crypto.h"
#include <sstream>

Block::Block(int idx, const std::string& prev, const std::vector<Transaction>& txs) {
    index = idx;
    prevHash = prev;
    timestamp = std::time(nullptr);
    transactions = txs;
    nonce = 0;
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << index << prevHash << timestamp << nonce;
    for (auto& tx : transactions) {
        ss << tx.toString();
    }
    return sha256(ss.str());
}
