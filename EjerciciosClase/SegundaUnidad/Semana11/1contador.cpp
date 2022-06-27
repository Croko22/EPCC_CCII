#include <iostream>
using namespace std;

class Contador{
private:
	int c;
	int nCont;//Numero del contador
	static int cCont;//Cantidad de contadores
public:
	explicit Contador(int cc=0)
    : c{cc}
    {nCont = ++cCont;}
	~Contador(){--cCont;}
	//Sobrecarga de operadores ++
	Contador& operator++(){
		c++;
		return *this;
	}
	Contador operator++(int){
	   Contador temp = *this;
	   ++*this;
	   return temp;
	}
	//Valor del contador y cantidad de contadores
	int valor(){return c;}
	int cantCont(){return cCont;}
};

int Contador::cCont;//Llamar al static
int main(){
    Contador c1{1};
    cout <<"Cantidad de contadores: " << c1.cantCont()<<endl;
    Contador c2{2};
    Contador c3{3};
    ++c1;
    ++c1;
    c2++;
    cout <<"Contador 1: "<< c1.valor()<<endl;
    cout <<"Contador 2: " << c2.valor()<<endl;
    cout <<"Contador 3: " << c3.valor()<<endl;
    cout <<"Cantidad de contadores: " << c2.cantCont()<<endl;
    return 0;
}