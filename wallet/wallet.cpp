#include "wallet.h"
#include <iostream>
#include <openssl/rand.h>
#include <sstream>

std::string generateAddress() {
    unsigned char key[32];
    RAND_bytes(key, sizeof(key));
    std::stringstream ss;
    for (int i = 0; i < 32; i++)
        ss << std::hex << (int)key[i];
    return "VRX_" + ss.str();
}
