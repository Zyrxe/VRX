#pragma once
#include <string>
#include <vector>

struct TxOut {
    double amount;
    std::string address;
};

struct TxIn {
    std::string prevTxHash;
    int outputIndex;
};

struct Transaction {
    std::vector<TxIn> inputs;
    std::vector<TxOut> outputs;

    std::string toString() const;
};
