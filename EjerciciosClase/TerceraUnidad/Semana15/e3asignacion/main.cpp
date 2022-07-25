#include <iostream>
#include "LinkedList.h"

int main(){
	LinkedList* l1 = new LinkedList;
	LinkedList* l2 = new LinkedList;

	//ASIGNAR VALORES PARA DIFERENCIAR LAS LISTAS
	for (int i = 0; i <= 7; i++){
		(i < 4) ? l1->insert(i) : l2->insert(i);
	}

	//LISTAS 
	std::cout << "Lista 1: " << *l1 << std::endl;
	std::cout << "Lista 2: " << *l2 << std::endl << std::endl;
	
	l1 = l2;

	//LISTAS LUEGO DE LA OPERACION
	std::cout << "UPDATE (Lista 1 = Lista 2)" << std::endl;
	std::cout << "Lista 1: " << *l1 << std::endl;
	std::cout << "Lista 2: " << *l2 << std::endl << std::endl;
	
	delete l1, l2;
}
