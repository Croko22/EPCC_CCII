#include <bits/stdc++.h>
using namespace std;
 
bool areFactors(int n, vector<int> v)
{
    bool d{true};
    for(int i:v){
        if(n%i!=0) d=false; 
    }
    return d;
}
 
int main()
{
    int n{};
    vector<int> v{1,2,3,4,5};
    cout<<"Ingrese n: ";cin>>n;
    if(areFactors(n,v)) cout<<"Son factores entre si"<<endl;
    else cout<<"No son factores entre si"<<endl;
    return 0;
}