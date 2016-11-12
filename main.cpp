#include <iostream>
#include <string>
#include "Tablero.h"
using namespace std;
int main(){
	bool valid=false, finish=false, lleno=false;
	int cont=1, jugador=0, ganador=0;
	int i=0,j=0,k=0,l=0;
	Tablero* tablerin = new Tablero();
	do{
		if(cont%2==0){
			jugador=2;
		}else{
			jugador=1;
		}
		tablerin-> imprimirTablero();
		lleno = tablerin->Lleno();
		if(!lleno){
			do{
				cout<<"Ingrese [i] de su pieza:"<<endl;
				cin>>i;
				cout<<"Ingrese [j] de su pieza:"<<endl;
				cin>>j;
				cout<<"Ingrese [i] de su pieza en donde lo va a mover:"<<endl;
				cin>>k;
				cout<<"Ingrese [j] de su pieza en donde lo va a mover:"<<endl;
				cin>>l;
				valid = tablerin->Verificacion(i,j,k,l,jugador);
			}while(!valid);
			tablerin->(k, l,jugador);
		}else{
			ganador = tablerin->GanadorPorTotal();
			finish = true;
		}
		cont++;
	}while(!finish);
	tablerin->deleteAll();
	return 0;
}