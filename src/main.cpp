#include "data_detector.h"
#include <iostream>
#include <string>

int main() {
    std::string binaryInput;
    std::cout << "Please enter a binary string:" << std::endl;
    std::cin >> binaryInput;

    for (char c : binaryInput) {
        if (c != '0' && c != '1') {
            std::cout << "Error: only 0 and 1 are allowed!" << std::endl;
            return 1;
        }
    }

    detectDataType(binaryInput);
    return 0;
}
