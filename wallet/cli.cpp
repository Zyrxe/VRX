#include "wallet.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: vrx-wallet create" << std::endl;
        return 0;
    }
    if (std::string(argv[1]) == "create") {
        std::string addr = generateAddress();
        std::cout << "New VRX address: " << addr << std::endl;
    }
    return 0;
}
