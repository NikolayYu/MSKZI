#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>

using namespace std;

bool foo(bitset<7> &a, bitset<7> &b){
    bool result, num1, num2;
    num1 = a[6]^a[1];
    num2 = b[6]^b[5]^b[2]^b[1];
    a <<= 1;
    a[0] = num1;
    b <<= 1;
    b[0] = num2;
    result = num1^num2;
    return result;
}
double size_file(){
    // Создание объекта для чтения файла
    ifstream file;

    // Открытие файла
    file.open("File.txt");

    // Проверка, был ли файл успешно открыт
    if (!file.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        return 0;
    }

    // Перемещение указателя текущей позиции в конец файла
    file.seekg(0, ios::end);

    // Получение текущего значения указателя (размер файла)
    double size = file.tellg();
    return size;
}

int main(){
    int value,perem, x=0, y=0;
    cout << "Введите значение первого полинома: ";
    cin >> value;
    bitset<7> a(value);
    cout << "Введите значение второго полинома: ";
    cin >> value;
    bitset<7> b(value);
    ifstream inputFile("File.txt", ios::binary);  
    ofstream outputFile("stat.txt", ios::binary); 
    
    char c;
    double x0 = 0,x1 = 0, len = 0;
    
    int n = 5,m = 0;
    while (inputFile.get(c)) {
        bitset<8> byte(c); // конвертация в биты
        for (int i = 0; i < 8; i++) {
            bool random_bit = foo(a, b);
            bool original_bit = byte[i];
            if(original_bit == 1){
                x0++;
            }
            bool masked_bit = original_bit ^ random_bit;
            if(masked_bit == 1){
                x1++;
                m++;
                
                /*Гамма с преобладанием
                if(n == m){
                    masked_bit = 0;
                    m=0;
                    x1--;
                    x0++;
                }*/
            }
            byte[i] = masked_bit;
            len++;
        }        
        c = static_cast<char>(byte.to_ulong()); // конвертация в символ
        outputFile.put(c);
    }     
    inputFile.close();
    outputFile.close();

    cout <<"Ориг. 1: " << x0<< " 0: "<< len - x0<<endl;
    cout <<"Код.  1: " << x1<< " 0: "<< len - x1<<endl;
return 0;
}