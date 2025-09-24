#include "transaction.h"
#include <sstream>

std::string Transaction::toString() const {
    std::stringstream ss;
    for (auto& in : inputs) {
        ss << in.prevTxHash << in.outputIndex;
    }
    for (auto& out : outputs) {
        ss << out.amount << out.address;
    }
    return ss.str();
}
