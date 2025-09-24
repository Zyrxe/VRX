#include <iostream>
#include "blockchain.h"
#include "transaction.h"
#include "../miner/miner.h"
#include "../node/p2p.h"

int main() {
    std::cout << "🚀 VRX Node started" << std::endl;

    Blockchain vrx;

    // Tambah transaksi mining reward
    std::vector<Transaction> txs;
    Transaction tx1;
    tx1.outputs.push_back({50, "miner1"});
    txs.push_back(tx1);

    Block newBlock = mineBlock(1, vrx.getLatestBlock().hash, txs, vrx.difficulty);
    vrx.addBlock(newBlock);

    std::cout << "Blockchain length: " << vrx.chain.size() << std::endl;
    std::cout << "Latest Block Hash: " << vrx.getLatestBlock().hash << std::endl;

    // P2P test
    P2PNode node(8333);
    node.connectToPeer("127.0.0.1:8334");
    node.broadcast("New block mined: " + vrx.getLatestBlock().hash);

    return 0;
}
