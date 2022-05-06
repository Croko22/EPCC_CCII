#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	double t{};
	cout<<"Enter a temperature in Cesius: ";cin>>t;
	printf("%.1lf C = %.1lf F",t,(t*9/5) + 32);
	return 0;
}