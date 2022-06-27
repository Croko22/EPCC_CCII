#include <iostream>
#include <array>
#include <utility>

template<typename C, typename U = typename C::value_type>
U sumaRango(const C & x,int ini, int fin){//Solo retornar la suma
    U s{};
    for(auto i=x.begin()+ini;i<x.begin()+fin+1;i++) s+=*i;
    return s;
}
template<typename C, typename U = typename C::value_type> //Par para retornar valores
std::pair<U,U> sumaRango(const C & x,int ini, int fin,U iOp){
    U s{iOp};
    for(auto i=x.begin()+ini;i<x.begin()+fin;i++) s+=*i;
    return std::make_pair(iOp,s);
}

int main()
{
    std::array<int, 7> a = {1,2,3,4,5,6,7};
    //Indice empieza en 0
    std::cout<<"ARRAY 1\n";
    std::cout<<"- Suma total: "<<sumaRango(a,2,5)<<std::endl; //Del 3 al 6 sin val inicial
    std::cout<<"- Valor inicial: "<<sumaRango(a,1,6,7).first
    <<" | Suma total: "<<sumaRango(a,1,6,7).second<<std::endl; //Del 2 al 6 iniciando en 7
    
    //Pruba con otro tipo
    std::cout<<"ARRAY 2\n";
    std::array<float, 5> a1 = {1.1,2.2,4.73,6.2,7.2};
    std::cout<<"- Suma total: "<<sumaRango(a1,0,3)<<std::endl; 
    std::cout<<"- Valor inicial: "<<sumaRango(a1,1,4,2.1).first
    <<" | Suma total: "<<sumaRango(a1,1,4,2.1).second<<std::endl; 
    return 0;
}