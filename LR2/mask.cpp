#include <iostream>
#include <string>
#include <bitset>
#include <fstream>
using namespace std;

bool foo(bitset<24> &a, bitset<125> &b){
    bool result, num1, num2;
    num1 = a[23]^a[5];
    num2 = b[124]^b[37];
    a = (a <<= 1);
    a[0] = num1;
    b = (b <<= 1);
    b[0] = num2;
    result = num1^num2;
    return result;
}

int main(){
    int value;
    string file_name;
    cout << "Введите значение первого полинома: ";
    cin >> value;
    bitset<24> a(value);
    cout << "Введите значение второго полинома: ";
    cin >> value;
    bitset<125> b(value);
    //cout << "Введите название файла для маскировки\n";
    ifstream inputFile("result.bmp", ios::binary);
    ofstream outputFile("result1.bmp", ios::binary);
    char c;
    while (inputFile.get(c)) {
        bitset<8> byte(c); // конвертация в биты
        for (int i = 0; i < 8; i++) {
            bool random_bit = foo(a, b);
            bool original_bit = byte[i];
            bool masked_bit = original_bit ^ random_bit;
            byte[i] = masked_bit;
        }
        c = static_cast<char>(byte.to_ulong()); // конвертация в символ
        outputFile.put(c);
    }
return 0;
}