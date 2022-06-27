#include <iostream>

class Racional{
private:
    int x;
    int y;
public:
    explicit Racional(int xx=0, int yy=1)
    : x{xx}, y{yy}
    {redux();}
    ~Racional(){}
    //Constructor copia
    Racional(const Racional& p1){
        x = p1.x;
        y = p1.y;
    }
    //Operador asignacion 
    Racional operator=(const Racional& p1){return Racional(p1.x,p1.y);}
    //Extraccion de x y
    int num()const{return x;}
    int den()const{return y;}
    void asignar(const int xx=0,const int yy=1){x=xx;y=yy;}
    //Operadores +=,-=,*=,/=
    Racional& operator+=(const Racional& r1){
        x *=r1.y; 
        x += r1.x*y;
        y *= r1.y;
        return *this;
    }
    Racional& operator-=(const Racional& r1){
        x *=r1.y; 
        x -= r1.x*y;
        y -= r1.y;
        return *this;
    }
    Racional& operator*=(const Racional& r1){
        x *= r1.x;
        y *= r1.y;
        return *this;
    }
    Racional& operator/=(const Racional& r1){
        x /= r1.x;
        y /= r1.y;
        return *this;
    }

    //e) mejor aproximacion
    double bestAprox(){return (double)x/y;}

    //Reducir la fraccion
    void redux(){ 
      int t =  x>y ? x : y , div = 1; //Maximo divisor
      for(int i=1; i<=t;i++) if(x%i==0 && y%i==0) div=i; 
      x/=div; y/=div; //Divdirlos
    }
};
int num(const Racional& c) {return c.num();}
int den(const Racional& c) {return c.den();}
//Mostrar la fraccion
std::ostream& operator<<(std::ostream& os, Racional& r1){
    return os<<r1.num()<<"/"<<r1.den();
}
//Operadores +,-,*,/
inline Racional operator+( const Racional& c1, const Racional& c2) {
    return Racional(num(c1)*den(c2) + num(c2)*den(c1),den(c1) * den(c2));
}
inline Racional operator-( const Racional& c1, const Racional& c2) {
    return Racional(num(c1)*den(c2) - num(c2)*den(c1),den(c1) * den(c2));
}
inline Racional operator*( const Racional& c1, const Racional& c2) {
    return Racional(num(c1) * num(c2),den(c1) * den(c2));
}
inline Racional operator/( const Racional& c1, const Racional& c2) {
    return Racional(num(c1) / num(c2),den(c1) / den(c2));
}
//Operador >>
std::istream& operator>>(std::istream& is, Racional& c) {
    int x{0},y{1};
    std::cout << "Numerador: ";
    is >> x;
    std::cout << "Denomador: ";
    is >> y;
    c.asignar(x,y);
    return is;
}

int main()
{
    Racional r1= Racional(88,77);   
    Racional r2= Racional(2,3);   
    Racional r3=r2+r2;
    r2+=r1;
    std::cout<<r1<<" "<<r1.bestAprox()<<std::endl;
    std::cout<<r2<<" "<<r2.bestAprox()<<std::endl;
    std::cout<<r3<<" "<<r3.bestAprox()<<std::endl;
    Racional rr;
    std::cin>>rr;
    std::cout<<rr<<std::endl;
    return 0;
}