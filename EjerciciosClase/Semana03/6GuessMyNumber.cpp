#include <iostream>
#include <random>
using namespace std;

int main(int argc, char const *argv[])
{
	std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, 100);  

    int n{},rn{distrib(gen)};


	cout<<"I'm thinking of a number between 1 and 100 (including both).\nCan you guess what it is?\n";
	cout<<"Type a number: ";cin>>n;

	
	cout<<"Your guess is: "<<n<<endl;
	cout<<"The number I was thinking of is:"<<rn<<endl;
	cout<<"You were off by: "<<abs(n-rn)<<endl;
	return 0;
}
