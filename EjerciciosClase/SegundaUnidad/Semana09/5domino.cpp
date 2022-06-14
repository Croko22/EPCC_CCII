#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Domino {
private:
	vector<pair<int, int>> Fichas;//Fichas ingresadas
	vector<vector<pair<int, int>>> Soluciones;//Soluciones generadas
public:
	Domino() {}
	void iFicha(pair<int, int> x) {Fichas.push_back(x);}
	void mFichas() {for (auto i : Fichas) cout << "[" << i.first << "|" << i.second << "]" << endl;}
	void genSol() {
		bool isSol = true;
		//Falta cambiar el orden de la ficha
		do {
			for (int i = 0; i < Fichas.size() - 1; i++) {
				if (Fichas.at(i).second != Fichas.at(i + 1).first) {isSol = false; break;}
			}
			if(Fichas.front().first != Fichas.back().second) {isSol = false;}
			if (isSol) {Soluciones.push_back(Fichas);} //Se cumplen las condiciones
			isSol = true;//Reseteo para sgte ficha
		} while (next_permutation(Fichas.begin(), Fichas.end())); //Permutar las fichas
	}
	void imprimirSol() { //Iterar el contenido de los vectores
		cout << "SOLUCIONES:" << endl;
		if (Soluciones.size() > 0) {
			for (auto j : Soluciones) {
				cout << "SOL:" << endl;
				for (auto i : j) cout << "[" << i.first << "|" << i.second << "]" << endl;
			}
		}else cout << "No hay Soluciones"<<endl;
	}
};

main() {
	Domino d = Domino();
	d.iFicha(make_pair(1, 2));
	d.iFicha(make_pair(2, 3));
	d.iFicha(make_pair(3, 1));
	cout<<"Fichas"<<endl;
	d.mFichas();
	d.genSol();
	d.imprimirSol();

	cout<<"Fichas"<<endl;
	Domino d1 = Domino();
	d1.iFicha(make_pair(1, 2));
	d1.iFicha(make_pair(4, 1));
	d1.iFicha(make_pair(2, 3));
	d1.mFichas();
	d1.genSol();
	d1.imprimirSol();
	return 0;
}