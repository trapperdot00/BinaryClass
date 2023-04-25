#include <iostream>
#include <string>
#include <cmath>

class Binary
{
    friend const unsigned binToDec(const Binary&);
public:
    Binary() = default;
    Binary(const long long unsigned& decVal) {
        binaryValue = decToBin(decVal);
    }

    const std::string decToBin(const long long unsigned&) const;
    std::ostream& print(std::ostream&) const;
    std::istream& read(std::istream&);
    Binary& assignIt(const long long unsigned&);
    Binary& assignIt(std::string&);
    const std::string& getValue() const { return binaryValue; }

private:
    std::string binaryValue;
};

const std::string Binary::decToBin(const long long unsigned& decVal) const {
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
    return binary;
}
std::ostream& Binary::print(std::ostream& os) const {
    os << getValue();
    return os;
}
std::istream& Binary::read(std::istream& is) {
    unsigned long long decVal;
    is >> decVal;
    binaryValue = decToBin(decVal);
    return is;
}
Binary& Binary::assignIt(const long long unsigned& assignedDecimalValue) {
    binaryValue = decToBin(assignedDecimalValue);
    return *this;
}
Binary& Binary::assignIt(std::string& assignedBinaryValue) {
    binaryValue = assignedBinaryValue;
    return *this;
}


const unsigned binToDec(const Binary& obj) {
    std::string binary = obj.getValue();
    unsigned sz = binary.size();
    unsigned decimal = 0;
    for (int index = 0; index != sz; ++index) {
        if (binary[index] == '1') {
            decimal += pow(2, int(sz)-index-1);
        }
    }
    return decimal;
}

const unsigned binToDec(const std::string& binary) {
    unsigned sz = binary.size();
    unsigned decimal = 0;
    for (int index = 0; index != sz; ++index) {
        if (binary[index] == '1') {
            decimal += pow(2, int(sz)-index-1);
        }
    }
    return decimal;
}

Binary andOP(const Binary& obj1, const Binary& obj2) {
    Binary andOP(binToDec(obj1.getValue()) & binToDec(obj2.getValue()));
    return andOP;
}
