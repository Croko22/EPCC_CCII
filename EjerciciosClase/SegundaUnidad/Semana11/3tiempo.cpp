#include <iostream>

class Tiempo {
private:
    int h,m,s;
public:
    explicit Tiempo(int hh=0, int mm=0, int ss=0)
    : h{hh}, m{mm}, s{ss}
    { }
    double horas() const {
        return h;
    }
    double min() const {
        return m;
    }
    double seg() const {
        return s;
    }
    void asignar(const int hh=0, const int mm=0, const int ss=0) {
        h = hh;
        m = mm;
        s = ss;
    }
};

double horas(const Tiempo& c) {return c.horas();}
double min(const Tiempo& c) {return c.min();}
double seg(const Tiempo& c) {return c.seg();}

std::ostream& operator<<(std::ostream& os, const Tiempo& c) {
    (horas(c)<=9)? os<<"0"<<horas(c) : os<<horas(c);
    (min(c)<=9)? os<<":0"<<min(c) : os<<":"<<min(c);
    (seg(c)<=9)? os<<":0"<<seg(c) : os<<":"<<seg(c);
    (horas(c)>=12)? os<<" pm" : os<<" am"; //am o pm
    return os;
}
//Suma y Resta de tiempos
inline Tiempo operator+( const Tiempo& c1, const Tiempo& c2) {
    int temp = horas(c1)*3600 + min(c1)*60 + seg(c1) + horas(c2)*3600 + min(c2)*60 + seg(c2);
    return Tiempo(temp/3600, temp%3600 / 60, temp % 60);
}
inline Tiempo operator-( const Tiempo& c1, const Tiempo& c2) {
    int temp = (horas(c1)*3600 + min(c1)*60 + seg(c1)) - (horas(c2)*3600 + min(c2)*60 + seg(c2));
    return Tiempo(temp/3600, temp%3600 / 60, temp % 60);
}
//Operadores == y !=
inline bool operator==( const Tiempo& c1, const Tiempo& c2) {
    return horas(c1) == horas(c2) && min(c1) == min(c2) && seg(c1) == seg(c2);
}
inline bool operator!=( const Tiempo& c1, const Tiempo& c2) {return !(c1==c2);} //Negamos ==
//Operadores <,>,<=,>=
inline bool operator<( const Tiempo& c1, const Tiempo& c2) {
    return (3600*horas(c1) + 60*min(c1) + seg(c1)) < (3600*horas(c2) + 60*min(c2) + seg(c2));
}
inline bool operator>( const Tiempo& c1, const Tiempo& c2){return c2<c1;}
inline bool operator<=( const Tiempo& c1, const Tiempo& c2){return !(c1>c2);}
inline bool operator>=( const Tiempo& c1, const Tiempo& c2){return !(c1<c2);}

int main() {
    Tiempo cx; std::cout << cx << std::endl;
    Tiempo t1{12,45,30}, t2{0,30,35}, t7{1,1,1};
    
    std::cout << "t1 + t2 is " << t1 + t2 << std::endl;
    std::cout << "t1 - t7 is " << t1 - t7 << std::endl;

    t1 == t7 ? std::cout << "Son iguales\n" : std::cout << "No son iguales\n";
    t1 != t7 ? std::cout << "Son diferentes\n" : std::cout << "No son diferentes\n";

    t7 < t1 ? std::cout << "Es menor\n" : std::cout << "No es menor\n";
    t7 > t1 ? std::cout << "Es mayor\n" : std::cout << "No es mayor\n";

    t2 >= t1 ? std::cout << "Es mayor o igual\n" : std::cout << "No es mayor o igual\n";
    t7 <= t1 ? std::cout << "Es menor o igual\n" : std::cout << "No es menor o igual\n";
}