#include <iostream>
using namespace std;
void countDown(int n){
	if(n==0){
		cout<<"0Lastoff!\n";
	} else {
		cout<<n<<"\n";
		countDown(n-1);
	}

}

void countUp(int n){
	if(n!=0){
       countUp(n-1);
       cout<<n<<"\n";
    } else{
    	cout<<"0Firstoff!\n";
    }
}

int main()
{
	cout<<"Descendente"<<endl;
	countDown(8);
	cout<<"Ascendente"<<endl;
	countUp(8);
	return 0;
}