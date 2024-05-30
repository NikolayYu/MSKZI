#include <iostream>
#include <vector>
#include <bitset>
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

void stat(){
    int value;
    int sdvig;
    float perem, x = 0, y = 0;
    
    cout << "Введите значение первого полинома: ";
    cin >> value;
    bitset<7> a(value);
    
    cout << "Введите значение второго полинома: ";
    cin >> value;
    bitset<7> b(value);
    
    cout << "Введите длинну результирующей полсдовательности: ";
    cin >> value;
    
    cout << "Введите длинну сдвига АКФ: ";
    cin >> sdvig;


    vector<bool> vect(value);
    bitset<1> posled1 = 0;
    bitset<2> posled2 = 0;
    bitset<3> posled3 = 0;
    bitset<4> posled4 = 0;
    float stat1[2]{};
    float stat2[4]{};
    float stat3[8]{};
    float stat4[16]{};
    
    for(int i = 0; i < value; i++){
        vect[i] = foo(a, b);
        posled1[0] = vect[i];
        posled2[0] = vect[i];
        posled3[0] = vect[i];
        posled4[0] = vect[i];
        stat1[(int)(posled1.to_ulong())]++;
        stat2[(int)(posled2.to_ulong())]++;
        stat3[(int)(posled3.to_ulong())]++;
        stat4[(int)(posled4.to_ulong())]++;
        posled1 <<= 1;
        posled2 <<= 1;
        posled3 <<= 1;
        posled4 <<= 1;
    }
    cout << "\n";
    
    for(unsigned int i = 0; i < size(stat1); i++){
        posled1 = i;
        cout << "Количкество элементов " << posled1.to_string<char, char_traits<char>, allocator<char> >() << ": " << stat1[i]/*value*/ << endl;
    }

    for(unsigned int i = 0; i < size(stat2); i++){
        posled2 = i;
        cout << "Количкество элементов " << posled2.to_string<char, char_traits<char>, allocator<char> >() << ": " << stat2[i]/*value*/ << endl;
    }

    for(unsigned int i = 0; i < size(stat3); i++){
        posled3 = i;
        cout << "Количкество элементов " << posled3.to_string<char, char_traits<char>, allocator<char> >() << ": " << stat3[i]/*value*/ << endl;
    }

    for(unsigned int i = 0; i < size(stat4); i++){
        posled4 = i;
        cout << "Количкество элементов " << posled4.to_string<char, char_traits<char>, allocator<char> >() << ": " << stat4[i]/*value*/ << endl;
    }
    cout << endl <<"Автокорелляционная функция\n";

    vector<int> corelation(value);
    for(int i=0; i< value; i++){
        //cout << vect[i];
        
        if (i>=0 and i<32){
            cout << i+1 << " " << vect[i] << vect[i+sdvig] <<" t: "<< (vect[i]^vect[i+sdvig]) <<endl;
        }
    }

}


int main(){

    stat();
    return 0;
}