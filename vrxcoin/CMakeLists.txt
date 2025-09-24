cmake_minimum_required(VERSION 3.10)
project(vrxcoin)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

include_directories(src wallet miner node)

add_executable(vrx
    src/main.cpp
    src/block.cpp
    src/transaction.cpp
    src/crypto.cpp
    src/blockchain.cpp
    miner/miner.cpp
    wallet/wallet.cpp
    node/p2p.cpp
)

add_executable(vrx-wallet wallet/cli.cpp wallet/wallet.cpp)

target_link_libraries(vrx OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(vrx-wallet OpenSSL::SSL OpenSSL::Crypto)
