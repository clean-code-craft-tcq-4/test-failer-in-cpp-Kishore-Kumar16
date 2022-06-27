#include <iostream>
#include <assert.h>
#include <iomanip>

#include "misaligned.hpp"

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);
    
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << std::left << std::setw(MAX_WIDTH) <<i * 5 + j + 1 << " | " << std::setw(MAX_WIDTH)
            << majorColor[i] << " | " << std::setw(MAX_WIDTH)<< minorColor[j] << "\n";

            
            int PairNum = ColorNum_To_PairNum(i, j, numberOfMinorColors);

            assert(PairNum == i * 5 + j + 1 ); // add 1 to get the correct Pairno index

            // Since "i" is taken for both minor & major color index, compare with "i"
            assert(PairNum_To_MajorColor(PairNum, numberOfMinorColors) == i);
            assert(PairNum_To_MinorColor(PairNum, numberOfMinorColors) == j);
        }
    }
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}