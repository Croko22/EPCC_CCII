#include <iostream>
#include <map>
#include <string>
using namespace std;
// Your task is to write a program that reads words and counts the frequency of each unique word. 
// A word is a string of nonspace characters separated by white space.

int main(int argc, char const *argv[])
{
	map<string,int> counts{};
	string word{};
	while (cin >> word) ++counts[word];


	for (auto& t : counts){
        cout << t.first << " - " << t.second<< endl;
     }
	return 0;
}