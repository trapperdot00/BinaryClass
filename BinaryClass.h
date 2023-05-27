#include <iostream>
#include <string>

class Binary;

const std::string decToBin(const long long unsigned&);
const unsigned long long binToDec(const std::string&);
const unsigned long long binToDec(const Binary&);
const unsigned long long powerOfNum(const unsigned long long&, const short&);

class Binary {
    friend const unsigned long long binToDec(const Binary&);

public:
    explicit Binary(const long long unsigned& decVal);
    explicit Binary(const std::string&);
    explicit Binary(const char*);
    Binary() : binaryValue("0") {}

    std::ostream& printBin(std::ostream&) const;
    std::ostream& printDec(std::ostream&) const;
    std::istream& readBin(std::istream&);
    std::istream& readDec(std::istream&);
    const std::string& getValueBin() const { return binaryValue; }
    const unsigned long long getValueDec() const;

private:
    const std::string strip(const std::string&) const;
    const char* strip(const char*) const;
    bool isBinaryString(const std::string&) const;
    bool isBinaryString(const char*) const;

    std::string binaryValue;
};
