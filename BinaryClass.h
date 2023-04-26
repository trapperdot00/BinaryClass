#include <iostream>
#include <string>

class Binary;
const std::string decToBin(const long long unsigned&);
const unsigned binToDec(const std::string&);
const unsigned binToDec(const Binary&);
const int powerOfNum(const int&, const int&);

class Binary {
    friend const unsigned binToDec(const Binary&);
public:
    Binary() = default;
    Binary(const long long unsigned& decVal);
    Binary(const std::string&);
    Binary(const char*);

    std::ostream& printBin(std::ostream&) const;
    std::ostream& printDec(std::ostream&) const;
    std::istream& readBin(std::istream&);
    std::istream& readDec(std::istream&);
    const std::string& getValueBin() const { return binaryValue; }
    const unsigned getValueDec() const;
private:
    std::string binaryValue = "0";
    const std::string strip(const std::string&) const;
    const char* strip(const char*) const;
    const bool isBinaryString(const std::string& s) const;

};

