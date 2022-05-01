#include <iostream>

using namespace std;

int main()
{
    cout<<"   *|";
    for (int i=1;i<=10;i++)
    {
        cout<<"\t"<<i;
    }

    cout<<"\n----+"<<string(77, '-')<<endl;
    for (int j=1;j<=10;j++)
    {
        cout<<"  "<<j<<" |\t";
        for (int i=1;i<=10;i++)
        {
            cout<<i*j<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
