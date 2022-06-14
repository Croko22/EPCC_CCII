#include <bits/stdc++.h>
using namespace std;

template <class T>
class Hist {
private:
	vector<T> x;//Vector de datos a procesar
	int nIntervalos;
	vector<int> intervalos;
public:
	Hist(vector<T> x, int i) {
		this->x = x;
		nIntervalos = i;
		crearIntervalos();
	}
	void setNIntervalos(int i) { nIntervalos = i; crearIntervalos();} //Cambiar n de intervalos
	void histograma(){
		//Generado a partir de los intervalos y el vector de datos
		for(auto i=intervalos.begin();i<intervalos.end()-1;i++){
			int c{};
			for(auto j:x){
				if(j>=*i && j<*(i+1)){c++;} //Condicion si se encuentra en el intervalo
			}
			cout <<"["<< *i<<","<<*(i+1)<<"]:\t"<<string(c,'*')<<endl; //Imprime el histograma
		}
	}
	void crearIntervalos(){
		intervalos.clear();//Limpia el vector de intervalos
		sort(x.begin(), x.end());//Ordena datos
		int gap{(x.back()-x.front()+1)/nIntervalos};//Extrae el tamaño del intervalo
		for(int i=x.front(); i<=x.back()+gap;i+=gap) intervalos.push_back(i);//Llena el vector
		cout<<"Intervalos generados:";
		for(auto i:intervalos) cout<<i<<" ";
		cout<<endl;
	}
};

int main()
{
	vector<int> array{10, 2, 9, 7, 5, 6, 1, 8, 8, 4};
	Hist<int> a= Hist(array,5);
	//Resultado deseado 2 1 2 3 2
	a.histograma();
	a.setNIntervalos(2);
	a.histograma();
	return 0;
}