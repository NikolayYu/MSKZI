#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>

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
    
    ifstream inputFile("img.bmp", ios::binary);  
    ofstream outputFile("resimg.bmp", ios::binary); 
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
    inputFile.close();
    outputFile.close();
return 0;
}