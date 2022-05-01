#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxProduct(const vector<int>& numbers){
    vector<int> products;
    for(int i=0;i<numbers.size()-1;i++){
        products.push_back(numbers[i]*numbers[i+1]);
    }
    return *max_element(products.begin(), products.end());;
}

int main()
{
    vector<int>numbers{8,3,100,2,5,2,33,1};
    cout<<MaxProduct(numbers);
    return 0;
}
