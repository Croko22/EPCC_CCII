// • Dos palabras son anagramas si contienen las mismas
// letras y el mismo número de cada letra.
// • Por ejemplo, stop es un anagrama de pots, Alan Smithee
// es un anagrama de The alias men
// • Escriba una función anagram que tome dos strings y
// verifique si son anagramas entre sí.
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string limpiarP(string word ){
  string temp{};
    for (int i = 0; i < word.size(); ++i) {
        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
            temp = temp + word[i];
        }
    }
    word = temp;
    return word;
}

bool anagram(string a,string b)
{
	a = limpiarP(a);
	b = limpiarP(b);

	for_each(a.begin(), a.end(), [](char & c) {
        c = ::tolower(c);
    });
    for_each(b.begin(), b.end(), [](char & c) {
        c = ::tolower(c);
    });

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a==b;
}

int main()
{
  string word1{},word2{};
  getline(cin,word1);
  getline(cin,word2);
  
  if(anagram(word1,word2)) cout<<word1<<" y "<<word2<<" son anagramas."<<endl;
  else cout<<"No son anagramas"<<endl;
  return 0;
}