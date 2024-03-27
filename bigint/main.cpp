#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;

string bigIntSum(string number1, string number2);
string bigIntSub(string number1, string number2);
int getCharToInt(char c);

int main() {
    string input1, input2;
    cout << "First number   >> ";
    cin >> input1;
    cout << "Second number  >> ";
    cin >> input2;

    cout << "Sum            >> " << bigIntSum(input1, input2) << std::endl;
    cout << "Sub            >> " << bigIntSub(input1, input2) << std::endl;
    return 0;
}

string bigIntSub(string number1, string number2) {
    bool isNa = false;
    if (number1.size() < number2.size()) {
        string temp = number1;
        number1 = number2;
        number2 = temp;
        isNa = true;
    } else if (number1.size() == number2.size()) {
        bool c = false;
        for(size_t i = 0; i < number1.size(); i++) {
            if (number1[i] > number2[i]) {
                c = true;
                break;
            }
            if (number1[i] < number2[i]) {
                string temp = number1;
                number1 = number2;
                number2 = temp;
                c = true;
                isNa = true;
                break;
            }
        }
        if (!c) return "0";
    }
    int carry = 0;
    string newNumber;
    size_t n1Index = number1.size();
    size_t n2Index = number2.size();
    while(n1Index > 0 || n2Index > 0) {
        // int e1 = --n1Index >= 0 ? getCharToInt(number1[n1Index]) : 0;
        // int e2 = --n2Index >= 0 ? getCharToInt(number2[n2Index]) : 0;
        int e1 = 0, e2 = 0;
        if (n1Index > 0) e1 = getCharToInt(number1[--n1Index]);
        if (n2Index > 0) e2 = getCharToInt(number2[--n2Index]);

        int t = e1 - e2 - carry;
        if (t < 0) {
            t += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        newNumber.insert(0, 1, (char)t + '0');
    }
    while(true) {
        if (newNumber[0] == '0') newNumber.erase(0, 1);
        else break;
    }

    if (isNa) newNumber.insert(0, 1, '-');
   
    return newNumber;
}

string bigIntSum(string number1, string number2) {
    // cout << (int)number2.size() - (int)number1.size() << std::endl;
    // for(int i = 0; i < number2.size()-number1.size(); i++) {
    //     number1.insert(0, 1, '0');
    // }
    // for(int i = 0; i < number1.size()-number2.size(); i++) {
    //     number2.insert(0, 1, '0');
    // }
    int carry = 0;
    string newNumber;
    size_t n1Index = number1.size();
    size_t n2Index = number2.size();
    while(n1Index > 0 || n2Index > 0 || carry != 0) {
        // int e1 = --n1Index >= 0 ? getCharToInt(number1[n1Index]) : 0;
        // int e2 = --n2Index >= 0 ? getCharToInt(number2[n2Index]) : 0;

        int e1 = 0, e2 = 0;
        if (n1Index > 0) e1 = getCharToInt(number1[--n1Index]);
        if (n2Index > 0) e2 = getCharToInt(number2[--n2Index]);
        
        int t = e1+e2+carry;
        newNumber.insert(0, 1, (char)t%10 + '0');
        carry = t/10;
    }
    return newNumber;
}

int getCharToInt(char c) {
    return c - '0';
}