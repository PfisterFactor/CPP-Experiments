//
//  main.cpp
//  findCarlos
//
//  Created by Eric Pfister on 1/28/15.
//
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>


const char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
std::random_device randDevice;
std::mt19937 md(randDevice());
std::string garbage = "";
unsigned int randomPerSecond = 0;


int randRange(int start, int finish) {
    std::uniform_real_distribution<double> dist(start, finish);
    int randomVar = dist(md);
    return randomVar;
}
void generateGarbage() {
	
    for (int i = 0; i<10;i++) {
        int randomVar = randRange(0,24);
        garbage += alphabet[randomVar];
    }
    std::cout << garbage;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::string toMatch = "carlos";
    std::cout << "Begin finding of string: " + toMatch;
    int totalMaxHit = 0;
    std::string totalMatchedString = "";
    while (true) {
        generateGarbage();
        int matchCounter = 0;
        int maxHit = 0;
        for (char Character : garbage) {
            if (Character == toMatch[matchCounter]) {
                matchCounter++;
                if (maxHit < matchCounter) {
                    maxHit++;
                    
                }
            }
            else {
                matchCounter = 0;
            }
        }
        
        if (totalMaxHit < maxHit) {
            totalMaxHit = maxHit;
            totalMatchedString = garbage;
        }
        garbage = "";
        if (totalMaxHit == 6) {
            std::cout << "\n\nCarlos found! " + garbage << " -- " << maxHit << " hits!\n";
            break;
        }
        else {
            std::cout << garbage << " -- " << maxHit << " hits! -- " << totalMaxHit << " -- " << totalMatchedString << std::endl;
            matchCounter = 0;
        }
    }
    
    return 0;
}
