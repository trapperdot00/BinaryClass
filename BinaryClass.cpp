#include "BinaryClass.h"

// CONSTRUCTORS

Binary::Binary(const long long unsigned& decVal) {
    binaryValue = decToBin(decVal);
}
Binary::Binary(const std::string& s) {
    binaryValue = strip(s);
}
Binary::Binary(const char* c) {
    binaryValue = strip(c);
}

// PUBLIC MEMBER FUNCTIONS

std::ostream& Binary::printBin(std::ostream& os) const {
    os << getValueBin();
    return os;
}
std::ostream& Binary::printDec(std::ostream& os) const {
    os << binToDec(getValueBin());
    return os;
}
std::istream& Binary::readBin(std::istream& is) {
    std::string userInput;
    if (is >> userInput && isBinaryString(userInput)) {
        binaryValue = strip(userInput);
    }
    else {
        is.setstate(is.rdstate() | is.failbit);
    }
    return is;
}
std::istream& Binary::readDec(std::istream& is) {
    long long int userInput;
    if (is >> userInput && userInput >= 0 && userInput <= UINT_MAX) {
        binaryValue = decToBin(userInput);
    } else {
        is.setstate(is.rdstate() | is.failbit);
    }
    return is;
}

const unsigned Binary::getValueDec() const {
    return binToDec(binaryValue);
}

// PRIVATE MEMBER FUNCTIONS

const std::string Binary::strip(const std::string& unstripped_value) const {
    std::string stripped;
    bool hasOne = false;
    for (const char c : unstripped_value) {
        if (!hasOne && c == '1') {
            stripped.push_back(c);
            hasOne = true;
        } else if (hasOne) {
            stripped.push_back(c);
        }
    }
    return stripped.empty() ? "0" : stripped;
}
const char* Binary::strip(const char* value) const {
    while (*value && *value != '1') {
        ++value;
    }
    return value;
}
bool Binary::isBinaryString(const std::string& s) const {
    for (std::string::size_type index = 0; index != s.size(); ++index) {
        if (s[index] != '0' && s[index] != '1') {
            return false;
        }
    }
    return true;
}
bool Binary::isBinaryString(const char* c) const {
    while (c && *c != '\0') {
        if (*c != '0' && *c != '1') {
            return false;
        }
        ++c;
    }
    return true;
}

// NON-MEMBER FUNCTIONS

const std::string decToBin(const long long unsigned& decVal) {
    bool hasOne = false;
    std::string binary;
    for (int shift = sizeof(decVal)*8-1; shift != -1; --shift) {
        if (hasOne) {
            if ((decVal >> shift) & 1)
                binary += "1";
            else
                binary += "0";
        }
        else if ((decVal >> shift) & 1) {
            binary += "1";
            hasOne = true;
        }
    }
    return binary.size() ? binary : "0";
}
const unsigned binToDec(const std::string& binary) {
    unsigned decimal = 0;
    for (std::string::size_type index = 0; index != binary.size(); ++index) {
        if (binary[index] == '1') {
            decimal += powerOfNum(2, binary.size()-index-1);
        }
    }
    return decimal;
}
const unsigned binToDec(const Binary& obj) {
    std::string binary = obj.getValueBin();
    unsigned sz = binary.size();
    unsigned decimal = 0;
    for (unsigned index = 0; index != sz; ++index) {
        if (binary[index] == '1') {
            decimal += powerOfNum(2, int(sz)-index-1);
        }
    }
    return decimal;
}
const int powerOfNum(const int& num, const int& power) {
    if (power > 0) {
        int result = num;
        for (int count = 1; count != power; ++count) {
            result *= num;
        }
        return result;
    }
    return 1;
}
