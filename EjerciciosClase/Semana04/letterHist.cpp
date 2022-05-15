#include <iostream>
#include <map>
using namespace std;

void letterHist(string str)
{
  map<char, int> M;

  for (int i = 0; str[i]; i++)
  {
    if (M.find(str[i]) == M.end())
      {
        M.insert(make_pair(str[i], 1));
      }
    else
      {
        M[str[i]]++;
      }
    }
 
    // Histograma
    for (auto& it : M) {
        cout << it.first << ' ' << string(it.second,'*') << '\n';
    }
}

int main()
{
  string word{};
  cin>>word;
  letterHist(word);
  return 0;
}