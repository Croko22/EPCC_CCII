#include <bits/stdc++.h>
using namespace std;

bool primo(int numero) {
  if (numero == 0 || numero == 1 || numero == 4) return false;
  for (int x = 2; x < numero / 2; x++) {
    if (numero % x == 0) return false;
  }
  return true;
}

bool arePrime(vector<int> v)
{
    bool d{true};
    for(int i:v){
        if(!primo(i)) d=false; 
    }
    return d;
}
 
bool arePrimeFactors(int n, vector<int> v)
{
    int p{1};
    for(int i:v){
        p*=i;
    }
    return arePrime(v) && (p==n);
}

int main()
{
    int n{};
    vector<int> v{2,3,5};
    cout<<"Ingrese n: ";cin>>n;
    if(arePrimeFactors(n,v)) cout<<"Son primos y su producto es "<<n<<endl;
    else cout<<"No son primos ni su producto es "<<n<<endl;
    return 0;
}