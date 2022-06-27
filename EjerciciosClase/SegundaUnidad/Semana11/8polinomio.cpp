#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

template <class T>
class Polinomio {
private:
    std::vector<T> c;//Coeficientes
public:
    explicit Polinomio(std::vector<T> tt = {})
    : c{tt}
    { }
    std::vector<T> coef() const { return c;}
    //Constructor que recibe el grado
    Polinomio(int g){
        c.resize(g);
    }
    ~Polinomio(){}
    //Calcular el polinomio
    T operator()(T x) const {
        T temp{};
        int s=c.size()-1;
        for(auto i:c){
            temp+=i*pow(x,s); 
            s--;
        }
        return temp;
    }
};
template <class T>
std::vector<T> coef(const Polinomio<T>& c){ return c.coef();}
template <class T>
std::ostream& operator<<(std::ostream& os, const Polinomio<T>& c) {
    std::vector<T> temp = coef(c);
    int s=temp.size()-1;
    for(auto i:temp){
        s==1 ? os<<i<<"*x + " : s==0 ? os<<i : os<<i<<"*x^"<<s<<" + "; //Evitar el '+' sobrante
        s--;
    }
    return os;
}
//Operadores de suma y resta
template <class T>
inline Polinomio<T> operator+( const Polinomio<T>& c1, const Polinomio<T>& c2) {
    std::vector<T> a = coef(c1);
    std::vector<T> b = coef(c2);//Operar de acuerdo al tamaño
    if(a.size() < b.size()){
        int s = b.size()-1;
        for(int i=a.size()-1;i>=0; i--){
            b.at(s) += a.at(i);
            s--;
        }
        return Polinomio<T>{b};
    }else{
        int s = a.size()-1;
        for(int i=b.size()-1;i>=0; i--){
            a.at(s) += b.at(i);
            s--;
        }
        return Polinomio<T>{a};
    }
}
template <class T>
inline Polinomio<T> operator-( const Polinomio<T>& c1, const Polinomio<T>& c2) {
    std::vector<T> a = coef(c1);
    std::vector<T> b = coef(c2);
    if(a.size() < b.size()){
        int s = b.size()-1;
        for(int i=a.size()-1;i>=0; i--){
            b.at(s) -= a.at(i);
            s--;
        }
        return Polinomio<T>{b};
    }else{
        int s = a.size()-1;
        for(int i=b.size()-1;i>=0; i--){
            a.at(s) -= b.at(i);
            s--;
        }
        return Polinomio<T>{a};
    }
}

int main() {
    std::vector<double> v{1.2,3.2}; 
    std::vector<int> v1{-1,0,2,4,6,23}; 
    std::vector<int> v2{-2,1,2,23}; 
    Polinomio<double>f{v};  // Representa la función 1.2x + 3.2
    Polinomio<int>g{v1}; 
    Polinomio<int>h{v2};

    std::cout <<"POLINOMIOS\n";
    std::cout << "f = " << f << std::endl;
    std::cout << "g = "<< g << std::endl;
    std::cout << "h = "<< h << std::endl;

    std::cout <<"OPERACIONES\n";
    Polinomio<int>k=g+h;
    std::cout << "g+h = "<< k << std::endl;

    Polinomio<double>w=f+f;
    std::cout << "f+f = "<< w << std::endl;

    Polinomio<int>z=g-h;
    std::cout << "g-h = "<< z << std::endl;

    std::cout <<"RESOLUCIONES\n";
    double f_0 = f(0);
    double f_1 = f(1);
    std::cout << "f(0) = " << f_0 << std::endl;
    std::cout << "f(1) = "<< f_1 << std::endl;

    double g_0 = g(0);
    double g_1 = g(1);
    std::cout << "g(0) = "<< g_0 <<std::endl;
    std::cout << "g(1) = "<< g_1 <<std::endl;
}