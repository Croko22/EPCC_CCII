#include <bits/stdc++.h>
#include <sstream>
using namespace std;

class Diamante {
private:
    char size;
    vector<string> diamante;
public:
    Diamante(char _size) {size = _size; genDiamante();}
    void setSize(char _size){size = _size; genDiamante();}
    void genDiamante() {
        diamante.clear(); //Resetar el vector
        int number{1}, i, j, k = 0;
        
        if (size>'A'&&size<'Z') number = size - 'A'+1; //Tamaño del diamante
        
        char ch{'A'}; //Cadena para recorrer
        //Primera mitad
        for (i = 1; i <= number; i++)
        {
            stringstream ss;
            for (j = 1; j <= number - i; j++)
            {
                ss << "·"; 
            }
            while (k != (2 * i - 1))
            {
                if (k == 0 || k == 2 * i - 2)
                    ss << (char)(ch + i - 1) ; 
                else
                    ss << "·" ;
                k++;
            }
            for (int z = 0; z < number - i; z++) ss << "·" ;
            k = 0;
            diamante.push_back(ss.str());
        }
        //Mitad de abajo
        number--;
        for (i = number; i >= 1; i--)
        {
            stringstream ss;
            for (j = 0; j <= number - i; j++)
            {
                ss << "·" ;
            }
            k = 0;
            while (k != (2 * i - 1))
            {
                if (k == 0 || k == 2 * i - 2)
                    ss << (char)(ch + i - 1);
                else
                    ss << "·";
                k++;
            }
            for (int z = 0; z < number - i + 1; z++) ss << "·" ;
            diamante.push_back(ss.str());
        }
    }
    void imprimir() {for(auto i: diamante) cout << i<<endl;}
};

int main() {
    Diamante a1=Diamante('E');
    a1.imprimir();
    a1.setSize('G');
    a1.imprimir();
    return 0;
}