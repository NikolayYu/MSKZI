#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
bool foo(bitset<24> &a, bitset<125> &b){
    bool result, num1, num2;
    num1 = a[23]^a[5];
    num2 = b[124]^b[37];
    a <<= 1;
    a[0] = num1;
    b <<= 1;
    b[0] = num2;
    result = num1^num2;
    return result;
}


int main(){
    int value,perem, x=0, y=0;
    cout << "Введите значение первого полинома: ";
    cin >> value;
    bitset<24> a(value);
    cout << "Введите значение второго полинома: ";
    cin >> value;
    bitset<125> b(value);
    cout << "Введите длинну результирующей полсдовательности: ";
    cin >> value;
    for(int i = 0; i < value; i++){
        cout << foo(a, b);
    }
return 0;
}