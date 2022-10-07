#include <ctime>
#include <vector>
#include <iostream>
#include <windef.h>
typedef unsigned char BYTE;

using namespace std;

#include "sha256.hpp"

typedef struct BlockStruct {
    std::string hash;
    std::string data;
    std::string prevHash;
} BlockStruct;

class Block {

public:

    std::string hash;
    std::string data;
    std::string prevHash;

};

BlockStruct createBlock(std::string data, std::string prevHash) {
    std::string hashBlock = "";
    BlockStruct block;
    block.hash = hashBlock;
    block.data = data;
    block.prevHash = prevHash;

    return block;
}

void HashBlock(BlockStruct &b1, BlockStruct &b2) {
    char data[b1.hash.length()];

    for(int i = 0; i < b1.hash.length(); i++) {
        if (b1.hash[i] != '/0') {
            data[i] = b1.hash[i];
        }
        std::cout << data[i] << std::endl;
    }

    // std::cout << SHA256(data) << std::endl;
    std::string finalHash = SHA256(data);

    b2.hash = finalHash;
}

BlockStruct Genesis() {
   return createBlock("Genesis", "");
}

void DisplayData(BlockStruct blockchain[], int i) {
    std::cout << "\n----------------------------------------\n" << std::endl;
    std::cout << "Hash : " << blockchain[i].hash << std::endl;
    std::cout << "Data: " << blockchain[i].data << std::endl;
    std::cout << "Prev Hash: " << blockchain[i].prevHash << std::endl;
}


int main(int argc, char *argv[]) 
{
    const int BCHAIN_SIZE = 5;
    BlockStruct BlockChain[BCHAIN_SIZE];
    BlockChain[0] = Genesis();
    BlockChain[1] = createBlock("Hello world !, 1 after genesis", "81ddc8d248b2dccdd3fdd5e84f0cad62b08f2d10b57f9a831c13451e5c5c80a5");
    BlockChain[1].hash ="81ddc8d248b2dccdd3fdd5e84f0cad62b08f2d10b57f9a831c13451e5c5c80a5";
        
    BlockChain[2] = createBlock("Hello again !, 2 after Genesis", BlockChain[1].hash);

    HashBlock(BlockChain[1], BlockChain[2]);

    DisplayData(BlockChain, 0);
    DisplayData(BlockChain, 1);
    DisplayData(BlockChain, 2);
    
    return 0;
}
