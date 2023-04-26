#include "BinaryClass.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Binary *num = new Binary;
    do {
        cout << "Enter binary value: ";
        if (!num->readBin(cin))
            break;
        cout << "Decimal value: " << num->getValueDec() << endl;
        cout << "Binary value: " << num->getValueBin() << endl;
        cout << endl;
        cout << "Enter decimal value: ";
        if (!num->readDec(cin))
            break;
        cout << "Decimal value: " << num->getValueDec() << endl;
        cout << "Binary value: " << num->getValueBin() << endl;
        cout << endl;

    } while (cin);
    delete num;
    return 0;
}
