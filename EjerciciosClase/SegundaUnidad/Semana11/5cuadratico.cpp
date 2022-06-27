#include <iostream>

// Función Cuadratica
class Cuadratica {
private:
    double a, b, c;
public:
    explicit Cuadratica(double aa=0, double bb=0, double cc=0)
    : a{aa}, b{bb}, c{cc}
    { }
    //Constructor copia
    Cuadratica(const Cuadratica& p1){
        a = p1.a;
        b = p1.b;
        c = p1.c;
    }
    //Operador asignacion 
    Cuadratica operator=(const Cuadratica& p1){
        return Cuadratica(p1.a,p1.b,p1.c);
    }

    double operator()(double x) const {
        return a * x * x + b * x + c;
    }
};

int main() {
    Cuadratica f{2, 1,4};  // Representa la función 2x^2 + 1x + 4.
    Cuadratica g{-1, 0,2}; // Representa la función -x + 2.
    Cuadratica k= Cuadratica(f);
    k = f;

    double f_0 = f(0);
    double f_1 = f(1);
    std::cout << f_0 << std::endl;
    std::cout << f_1 << std::endl;

    double g_0 = g(0);
    std::cout << g_0 << std::endl;
}