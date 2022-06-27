#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

template <typename T>
std::string to_string(const T & x) {
    std::ostringstream os;
    os << x;
    return os.str();
}
template<typename C, typename U = typename C::value_type>
std::string to_string(const C & x,bool isCont) { //Para evitar la ambiguaedad en la sobrecarga
    std::stringstream os;
    for(auto i:x) os << i <<" ";
    return os.str();
}

int main()
{
    //Prueba con diferentes contendores 
    std::vector<int> v = {1,2,3};
    std::vector<float> v1 = {1.3,2.4,3.3,23.4,24.1,673.2};
    std::list<float> l1(v1.begin(), v1.end());
    //Tipos
    std::cout << to_string(12453) << std::endl;
    std::cout << to_string(12.453) << std::endl;
    //Contenedores
    std::cout << to_string(v,true) << std::endl;
    std::cout << to_string(v1,true) << std::endl;
    std::cout << to_string(l1,true) << std::endl;
    return 0;
}