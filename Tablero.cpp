#include "Tablero.h"

Tablero::Tablero(){
	for (int i = 0; i < 11; i++){
		matriz[i] = new char[11];
	}
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if(i==0 && j==0 || i==10 && j==10){
				matriz[i][j] = '+';
			}else if(i==10 && j==0 || i==0 && j==10){
				matriz[i][j] = '#';
			}else{
				matriz[i][j] = ' ';
			}
		}
	}
}

void Tablero::CrearTablero(){
	matriz = new char*[11];
	
	return matriz;
}//fin CrearTablero
void Tablero::imprimirTablero(char** matriz){
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			cout<<matriz[i][j]<<" ";
		}
		cout<< endl;
	}
}
void Tablero::movimientoTablero(int k, int l, int jugador){
	char pieza='', comer='';
	if(jugador == 1){
		pieza = '+'
		comer = '#'
	}else{
		pieza = '#';
		comer = '+'
	}
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++i)
		{
			if(i==k && j==l){
				table[i][j] = pieza;
				if(table[k+1][l] == comer && k+1<11|| table[k-1][l] == comer && k-1>=0|| table[k][l-1] == comer && l-1>=0 || table[k][l+1] == comer && l+1<11|| table[k-1][l-1] == comer && k-1>=0|| table[k+1][l-1] == comer && k+1<11 && l-1>=0|| table[k+1][l+1] == comer && k+1<11){
					table[i][j] = pieza;
				}//
			}
		}
	}
}//fin mover
void Tablero::Verificacion(int i, int j, int k, int l, int jugador){
	char pieza='', comer='';
	int mayor1=0, menor1=0, menor2=0, mayor2=0;
	bool valid = false;
	if(jugador == 1){
		pieza = '+'
		comer = '#'
	}else{
		pieza = '#';
		comer = '+'
	}
	if(i>k){
		mayor1 = i;
		menor1 = k;
	} else if(k<i){
		mayor1 = k;
		menor1 = i;
	} else {

	}
		if(table[k][l] != comer){
			table[k][l];
		}
}