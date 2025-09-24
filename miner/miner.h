#pragma once
#include "../src/block.h"

Block mineBlock(int index, const std::string& prevHash, const std::vector<Transaction>& txs, int difficulty);
