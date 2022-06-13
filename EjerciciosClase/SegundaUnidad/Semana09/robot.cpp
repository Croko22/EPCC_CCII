#include <bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> rand_ascii('A','Z');
uniform_int_distribution<> rand_int(0,9);

class Robot{
private:
	string nombre;
public:
	Robot(){nombre=genNombre();}
	void resetear(){nombre = genNombre();}

	string getNombre(){return nombre;};
	string genNombre(){ //676 000 posibles combinaciones
		nombre="";
		nombre+= char(rand_ascii(gen));
		nombre+= char(rand_ascii(gen));
		nombre+=to_string(rand_int(gen))+to_string(rand_int(gen))+to_string(rand_int(gen));
		return nombre;
	}

	void imprimir(){
		cout<<"Nombre: "<<nombre<<endl;
	}
};

//Verificar la lista de ROBOTS
void vNombres(vector<Robot> r)
{
	for (int i = 0; i < r.size(); i++)
	{
		for (int j = i+1; j < r.size(); j++)
		{
			if (r.at(i).getNombre() == r.at(j).getNombre()){
				cout<<"Reseteando nombre repetido"; r.at(j).resetear();
			}
		}
	}
	cout<<"No se encontraron repetidos"<<endl;
}

int main()
{
	int n;
	cout<<"Cantidad de robots:\n";cin>>n;
	vector<Robot> rList(n);
	//ROBOTS GENERADOS
	cout<<"Robots Generados"<<endl; 
	for(Robot i:rList) i.imprimir();
	vNombres(rList);

	//RESETEO
	for(Robot & i:rList) i.resetear();
	cout<<"Robots Reseteados"<<endl;
	for(Robot i:rList) i.imprimir();
	vNombres(rList);

	return 0;
}