#include <bits/stdc++.h>
using namespace std;

class Robot{
private:
	int x;
	int y;
	int dir;
	string dirT;
public:
	Robot(int _x, int _y){x=_x;y=_y;dir=90;dirT="Norte";}

	void mover(string c){
		for(char i:c){	
			if(i=='A'){
				if(dir%360==0) x++;
				if(dir%360==90) y++;
				if(dir%360==180) x--;
				if(dir%360==270) y--;
			}
			if(i=='D') dir+=270;
			if(i=='I') dir+=90;
			setDir();
		}
	}

	void setDir(){
		if(dir%360==0) dirT="Este";
		if(dir%360==90) dirT="Norte";
		if(dir%360==180) dirT="Oeste";
		if(dir%360==270) dirT="Sur";
	}
	
	void imprimir(){
		cout<<"Coordenadas: ("<<x<<","<<y<<") | Direccion: "<<dirT<<endl;
	}
};
int main()
{
	Robot r1 = Robot(7,3);
	r1.imprimir();
	r1.mover("DAAIAI");
	r1.imprimir();
	return 0;
}