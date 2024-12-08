#ifndef DATA_DETECTOR_H
#define DATA_DETECTOR_H

#include <string>

bool isASCIIString(const std::string& binary);
bool isNumber(const std::string& binary);
bool isPNGFile(const std::string& binary);
void detectDataType(const std::string& binary);

#endif