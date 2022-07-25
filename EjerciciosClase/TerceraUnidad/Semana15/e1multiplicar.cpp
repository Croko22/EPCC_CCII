#include <iostream>

void multiplicar(int m[][3][3], int n) {
	int y = std::size(*m);
	int z = std::size(**m);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) m[i][j][k] *= n;
		}
	}
}

void printM(int x[][3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << "{ ";
			for (int k = 0; k < 3; k++) std::cout << x[i][j][k] << " ";
			std::cout << "}\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	int x[3][3][3] = { {{1,2,3},{4,5,6},{7,8,9}},{{11,12,13},{14,15,16},{17,18,19}},{{21,22,23},{24,25,26},{27,28,29}} };

	printM(x);//Antes
	multiplicar(x, 6);
	printM(x);//Despues
	return 0;
}