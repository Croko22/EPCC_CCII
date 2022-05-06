#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{	
	int s{};
	cout<<"Enter the number of seconds to convert: ";cin>>s;
	cout<<s<<" seconds = "<<s/3600<<" hours, "<<s%3600 /60<<" minutes, and "<<s%60<<" seconds";
	return 0;
}