#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

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

int main()
{
  map<string,int> counts{};
  string word{};
  while (cin >> word){
    //Probar con regex para ver si borra
    word = limpiarP(word);
    ++counts[word];
  }
  for (auto& t : counts){
        cout << t.first << " - " << t.second<< endl;
  }
  cout<<"/////////"<<endl;
  palabraM(counts);
  return 0;
}