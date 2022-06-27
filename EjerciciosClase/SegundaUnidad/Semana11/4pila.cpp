#include <iostream>
#include <stack>

template<typename T>
class Pila{
private:
	std::stack<T> pila;
	int s;
public:
	//a)Constructor y b)destructor
	Pila(){};
	explicit Pila(int ss=10)
    : s{ss} 
    { }
	~Pila(){};
	//Operacionnes de la pila
	void top(){std::cout<<pila.top()<<std::endl;}
	T pop(){T temp{pila.top()};pila.pop();return temp;}
	void push(T dato){
		if(!full()) pila.push(dato);	
		else std::cout<<"Pila llena"<<std::endl;
	}
	void clear(){while (!empty()) pila.pop();}

	//Verificadores de espacio
	int size(){return pila.size();}
	bool full(){return pila.size() >= s;}
	bool empty(){return pila.empty();}

	//MOSTRAR DATOS
	void print(){
    	std::stack<T> temp;
    	if (pila.empty()) std::cout <<"Esta vacia"<<std::endl;
	    while (!pila.empty()){
	        temp.push(pila.top());
	        pila.pop();
	    }  
	    while (!temp.empty()){
	        T t = temp.top();
	        std::cout << t << " ";
	        temp.pop();
	        pila.push(t); 
	    }
	    std::cout<<std::endl;
	}
};

int main(){
	Pila<int> p{2};
	p.push(5);
	p.push(5);
	p.push(5);
	p.print();
	p.pop();
	p.print();
	p.clear();
	p.print();
	//Prueba con otro tipo	
	Pila<float> p1{3};
	p1.push(2.5);
	p1.push(2.25);
	p1.print();
	return 0;
}