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
    Binary(const long long unsigned& decVal) {
        binaryValue = decToBin(decVal);
    }
    Binary(const std::string&);
    Binary(const char*);

    std::ostream& print(std::ostream&) const;
    const std::string& getValue() const { return binaryValue; }

private:
    std::string binaryValue;
    const std::string strip(const std::string&) const;
    const char* strip(const char*) const;

};

