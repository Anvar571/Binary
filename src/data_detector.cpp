#include "data_detector.h"
#include <iostream>
#include <bitset>
#include <cstdio>

bool isASCIIString(const std::string& binary) {
    std::string result = "";
    for (size_t i = 0; i < binary.size(); i += 8) {
        if (i + 8 > binary.size()) break;
        std::string byte = binary.substr(i, 8);
        char character = (char)std::bitset<8>(byte).to_ulong();
        if (!isprint(character)) return false;
        result += character;
    }
    std::cout << "Decoded string: " << result << std::endl;
    return true;
}

bool isNumber(const std::string& binary) {
    try {
        int number = std::stoi(binary, 0, 2);
        std::cout << "This is a number: " << number << std::endl;
        return true;
    } catch (...) {
        return false;
    }
}

bool isPNGFile(const std::string& binary) {
    std::string pngHeader = "89504E47";
    std::string binaryHeader = "";
    
    for (size_t i = 0; i < 4; ++i) {
        if (i * 8 + 8 > binary.size()) break;
        std::string byte = binary.substr(i * 8, 8);
        int decimalValue = std::bitset<8>(byte).to_ulong();
        char hex[3];
        sprintf(hex, "%02X", decimalValue);
        binaryHeader += hex;
    }
    std::cout << "Identified file header: " << binaryHeader << std::endl;
    return binaryHeader == pngHeader;
}

void detectDataType(const std::string& binary) {
    std::cout << "Input data: " << binary << std::endl;

    if (isASCIIString(binary)) {
        std::cout << "This is a string (text)!" << std::endl;
        return;
    }

    if (isNumber(binary)) {
        std::cout << "This is a number!" << std::endl;
        return;
    }

    if (isPNGFile(binary)) {
        std::cout << "This is a PNG file!" << std::endl;
        return;
    }

    std::cout << "Data type not identified." << std::endl;
}