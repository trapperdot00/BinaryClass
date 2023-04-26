#include <iostream>
#include <string>

const int powerOfNum(const int& num, const int& power)
{
    if (power > 0) {
        int result = num;
        for (unsigned count = 1; count != power; ++count) {
            result *= num;
        }
        return result;
    }
    return 1;
}

const bool isOnlyBinary(const std::string& s)
{
    bool onlyBinary = true;
    for (std::string::size_type index = 0; index != s.size() && onlyBinary; ++index) {
        if (s[index] != '0' && s[index] != '1') {
            onlyBinary = false;
        }
    }
    return onlyBinary;
}

class Binary
{
    friend const unsigned binToDec(const Binary&);
public:
    Binary() = default;
    Binary(const long long unsigned& decVal) {
        binaryValue = decToBin(decVal);
    }
    Binary(const std::string&);
    Binary(const char*);

    const std::string decToBin(const long long unsigned&) const;
    std::ostream& print(std::ostream&) const;
    std::istream& read(std::istream&);
    Binary& assignIt(const long long unsigned&);
    Binary& assignIt(std::string&);
    const std::string& getValue() const { return binaryValue; }

private:
    std::string binaryValue;
};

Binary::Binary(const char* c)
{
    while (*c) {
        binaryValue += *c++;
    }
}
Binary::Binary(const std::string& s)
{
    if (isOnlyBinary(s)) {
        binaryValue = s;
    }
    else {
        binaryValue = "0";
    }
}
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
            decimal += powerOfNum(2, int(sz)-index-1);
        }
    }
    return decimal;
}
const unsigned binToDec(const std::string& binary) {
    unsigned sz = binary.size();
    unsigned decimal = 0;
    for (int index = 0; index != sz; ++index) {
        if (binary[index] == '1') {
            decimal += powerOfNum(2, int(sz)-index-1);
        }
    }
    return decimal;
}

const std::string strip(const std::string& s)
{
    bool hasOne = false;
    std::string newStr;
    for (std::string::size_type index = 0; index != s.size(); ++index) {
        if (!hasOne) {
            if (s[index] == '1') {
                hasOne = true;
                newStr += '1';
            }
        }
        else {
            newStr += s[index];
        }
    }
    return newStr;
}

Binary andOP(const Binary& obj1, const Binary& obj2) {
    Binary andOP(binToDec(obj1.getValue()) & binToDec(obj2.getValue()));
    return andOP;
}

int main() {
    /*
    Binary num("1001");
    //Binary num("11101");
    num.print(std::cout) << std::endl;
    std::cout << binToDec(num);
    */
    std::string val("000100100");
    std::cout << strip(val);
    return 0;
}
// TODO: remove 0s from start of binaryValue in constructors
//       remove assignIt functions
