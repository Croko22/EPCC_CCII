#include <bits/stdc++.h>
using namespace std;

class Tablero{
private:
	string t{string(64,'_')}; //Tablero en un string
	pair<int,int> rB;//Cordenadas de fichas con pairs de enteros
	pair<int,int> rN;
public:
	Tablero(pair<int,int> _rB,pair<int,int> _rN){
		rB = _rB; rN = _rN;//Setear cordenadas y posicionar
		t[rB.first+rB.second*8] = 'B';
		t[rN.first+rN.second*8] = 'N';
	}
	//Movimientos: Primero se limpia el espacio ocupado, actualizar cord y luego se reubica
	void moverRB(pair<int,int> _rB){t[rB.first+rB.second*8] = '_';rB = _rB;t[rB.first+rB.second*8] = 'B';}
	void moverRN(pair<int,int> _rN){t[rN.first+rN.second*8] = '_';rN = _rN;t[rN.first+rN.second*8] = 'N';}

	void imprimirT(){//Imprimir el string en 8x8
		for(int j=0; j<8;j++){
			for(int i=0; i<8;i++) cout << t[i+j*8]<<" ";
			cout<<endl;
		}//Notificar si las reinas se pueden atacar
		(areAttackable()) ?cout<<"Se pueden atacar"<<endl:cout<<"No se pueden atacar"<<endl;
	}
	bool areAttackable(){//Comprobar igualdad filas o col o en diagonal 
		if(rB.first == rN.first || rB.second == rN.second || abs(rB.first-rN.first) == abs(rB.second-rN.second)) return true;
		else return false;
	}
};

int main(){
	Tablero t1 = Tablero(make_pair(1,1),make_pair(4,5));
	t1.imprimirT();
	t1.moverRB(make_pair(2,3)); t1.moverRN(make_pair(5,6));
	t1.imprimirT();
	return 0;
}