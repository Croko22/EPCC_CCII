#include <bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> rand_ascii('A','Z');
uniform_int_distribution<> rand_int(1,5);

class Ficha{
private:
	char letra;
	int valor;
public:
	Ficha(){}
	Ficha(char _letra, int _valor){letra=_letra; valor=_valor;}
	void imprimir(Ficha){
		cout<<"Letra: "<<letra<<" <|> Valor: "<<valor<<endl;
	}
};

class Scrabble{
private:
	string nombre;
	vector<Ficha> fichas;
public:
	Scrabble(string _nombre){nombre=_nombre;}
	void gFichas(){ //Llenar las fichas del jugador aleartoriamente
		fichas.reserve(7);
		for(int i=7; i;i--)
			fichas.push_back(Ficha(char(rand_ascii(gen)),rand_int(gen)));
	}
	void mostrarFichas(){
		cout<<"El jugador:"<<nombre<<endl;
		for(Ficha i: fichas) i.imprimir(i); 
	}
};

int main()
{
	//Crear Jugadores	
	Scrabble j1 = Scrabble("Felipe");
	j1.gFichas();
	j1.mostrarFichas();

	Scrabble j2 = Scrabble("Wallace");
	j2.gFichas();
	j2.mostrarFichas();
	
	return 0;
}