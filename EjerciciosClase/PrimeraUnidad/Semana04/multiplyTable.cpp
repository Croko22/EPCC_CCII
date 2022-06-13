#include <iostream>

using namespace std;

void tableHeader(int n1,int n2){
    cout<<"   *|";
    for (int i=n1;i<=n2;i++)
    {
        cout<<"\t"<<i;
    }
    cout<<"\n----+"<<string(((n2-n1)*5)-3, '-')<<endl;
}
void printNumber(int n1,int n2,int n){
    cout<<"  "<<n<<" |\t";
    for (int i=n1;i<=n2;i++){
            cout<<n*i<<"\t";
    }
    cout<<"\n";
}
void bodyTable(int n1,int n2){
    for (int j=n1;j<=n2;j++)
    {    
       printNumber(n1,n2,j); 
    }
}

int main()
{
    int n1{1},n2{10};
    tableHeader(n1,n2);
    bodyTable(n1,n2);
    return 0;
}
