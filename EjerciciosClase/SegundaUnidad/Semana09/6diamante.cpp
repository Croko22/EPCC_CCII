#include <bits/stdc++.h>
#include <sstream>
using namespace std;

class Diamante {
private:
    char size;
    vector<string> diamante;//Vector de strings (filas del diamante)
public:
    Diamante(char _size) {size = _size; genDiamante();}
    void setSize(char _size){size = _size; genDiamante();}//Cambiar tamaño luego generar de nuevo
    void genDiamante() {
        diamante.clear(); //Resetar el vector
        int number{1}, i, j, k = 0;
        
        if (size>'A'&&size<'Z') number = size - 'A'+1; //Validar tamaño del diamante
        
        char ch{'A'}; //Cadena para recorrer
        //Primera mitad
        for (i = 1; i <= number; i++){
            stringstream ss;
            for (j = 1; j <= number - i; j++)ss << "·";  //Puntos antes del char
            
            while (k != (2 * i - 1))
            {
                if (k == 0 || k == 2 * i - 2) //Condicion de pos
                    ss << (char)(ch + i - 1) ; //Inserta letra
                else
                    ss << "·" ;
                k++;
            }
            for (int z = 0; z < number - i; z++) ss << "·" ;
            k = 0;
            diamante.push_back(ss.str());//Ingreso de fila en un string
        }
        //Mitad de abajo (Similar a lo de arriba)
        number--;
        for (i = number; i >= 1; i--){
            stringstream ss;
            for (j = 0; j <= number - i; j++) ss << "·" ;
            
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
            diamante.push_back(ss.str());//Ingreso de fila en un string
        }
    }
    void imprimir() {for(auto i: diamante) cout << i<<endl;}//Imprimir las filas del diamante
};

int main() {
    Diamante a1=Diamante('E');
    a1.imprimir();
    a1.setSize('G');
    a1.imprimir();
    return 0;
}