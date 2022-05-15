#include <iostream>
#include <map>
#include <algorithm>
#include <regex>
using namespace std;

// • Reescriba el ejercicio del conteo de palabras. Imprima las
// palabras en forma alineada.
// – Escriba una función que encuentre la palabra más grande.
// – Una función para limpiar caracteres que no sean
// alfabéticos.

bool cmp(pair<string, int>& a,pair<string, int>& b)
{
    return a.first.size() > b.first.size();
}

void palabraM(map<string, int>& M)
{
    vector<pair<string, int> > A;

    for (auto& it : M) {
        A.push_back(it);
    }
  
    sort(A.begin(), A.end(), cmp);

    cout<<"Max element: "<<A.front().first;
}

int main()
{
  map<string,int> counts{};
  string word{};
  while (cin >> word){
    //Probar con regex para ver si borra
    ++counts[word];
  }
  for (auto& t : counts){
        cout << t.first << " - " << t.second<< endl;
  }
  cout<<"/////////"<<endl;
  palabraM(counts);
  return 0;
}