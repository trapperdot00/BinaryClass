#include "BinaryClass.h"

using std::cout;
using std::cin;
using std::endl;

void printNumData(const Binary* p) {
    cout << "Decimal value: " << p->getValueDec() << '\n';
    cout << "Binary value: " << p->getValueBin() << "\n\n";
}
void printNumData(const Binary b) {
    cout << "Decimal value: " << b.getValueDec() << '\n';
    cout << "Binary value: " << b.getValueBin() << "\n\n";
}

int main()
{
    Binary *num = new Binary;
    char choice;
    cout << "Enter base (b, d) and value." << "\n\n";
    do {
        if (!(cin >> choice))
            break;

        if (choice == 'b') {
            if (!num->readBin(cin)) {
                break;
            }
            printNumData(num);
        }
        else if (choice == 'd') {
            if (!num->readDec(cin))
                break;
            printNumData(num);
        }
    } while (cin);
    delete num;

    return 0;
}
