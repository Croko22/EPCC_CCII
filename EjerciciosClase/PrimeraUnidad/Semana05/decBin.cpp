#include<bits/stdc++.h>
using namespace std;
//CAMBIAR LA STRING POR UN VECTOR
void decBin(int x, vector<int> & bin_num)
{
    if (x <= 1){
        bin_num.push_back(x+0); 
    }
    else {
        decBin(x / 2, bin_num);
        if(x%2)
          bin_num.push_back(1);
        else
          bin_num.push_back(0);
    }
}

int main()
{
    vector<int> bin_num{};
    decBin(101, bin_num);
     
    for(auto i:bin_num) cout<<i;
    return 0;
}