#include "Tablero.h"

Tablero::Tablero(){
	for (int i = 0; i < 11; i++){
		table[i] = new char[11];
	}
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if(i==0 && j==0 || i==10 && j==10){
				table[i][j] = '+';
			}else if(i==10 && j==0 || i==0 && j==10){
				table[i][j] = '#';
			}else{
				table[i][j] = '-';
			}
		}
	}
}
void Tablero::imprimirTablero(){
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			cout<<table[i][j]<<" ";
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
		for (int j = 0; j < 11; ++j)
		{
			if(i==k && j==l){
				table[i][j] = pieza;
				if(table[k+1][l] == comer && k+1<11|| table[k-1][l] == comer && k-1>=0|| table[k][l-1] == comer && l-1>=0 || table[k][l+1] == comer && l+1<11|| table[k-1][l-1] == comer && k-1>=0|| table[k+1][l-1] == comer && k+1<11 && l-1>=0|| table[k+1][l+1] == comer && k+1<11){
					table[i][j] = pieza;
				}//Pone la pieza
			}
		}
	}
}//fin mover
bool Tablero::Verificacion(int i, int j, int k, int l, int jugador){
	char pieza='', comer='';
	int mayor1=0, menor1=0, menor2=0, mayor2=0;
	bool valid1 = false, valid2 = false, valid3 = false;
	if(jugador == 1){
		pieza = '+'
		comer = '#'
	}else{
		pieza = '#';
		comer = '+'
	}
	if(table[i][j] == pieza){//Verifica si es la pieza que es del jugador
		if(l>=0 && k<11 && l<11 && k>=11){//Verifica si no sobrepasan la matriz
			if(i>k){//Verifica el mayor de i
				mayor1 = i;
				menor1 = k;
				valid1 = true;
			} else if(k<i){
				mayor1 = k;
				menor1 = i;
				valid1 = true;
			} else {
				valid1 = false;
			}
			if(j>l){//Verifica el mayor de j
				mayor2 = j;
				menor2 = l;
				valid1 = true;
			} else if(l>j) {
				mayor2 = l;
				menor2 = j;
				valid1 = true;
			} else {
				valid1 = false;
			}
			if(valid1){//Si no es igual
				if(mayor1-menor1<=2 && mayor2-menor2<=2){
					valid2 = true;
				}else{
					valid2 = false;
				}
				if(valid2){
					if(table[k][l] != pieza && table[k][l] != comer){
						valid3=true;
					} else {
						valid3=false;
					}
				}
			}
		} else {
			valid3 = false;
		}
	}else{
		valid3 = false;
	}
	return valid3;
}
bool Tablero::Lleno(){
	int contador=0;
	bool lleno=false;
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if(table[i][j]=='#' || table[i][j] == '+'){
				contador++;
			}
		}
	}
	if(contador==121){
		lleno=true;
	}
	return lleno;
}
int Tablero::GanadorDeDiferencia(){
	int contadorMas=0, contadorNumeral=0, ganador;
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if(table[i][j] == '#'){
				contadorNumeral++;
			}
			if(table[i][j] == '+'){
				contadorMas++;
			}
		}
	}
	if(contadorMas==0){
		ganador=2;
	}
	if(contadorNumeral==0){
		ganador=1;
	}
	if(contadorNumeral!=0 && contadorMas!=0){
		ganador=0;
	}
	return ganador;
}

int Tablero::GanadorPorTotal(){
	int contadorMas=0, contadorNumeral=0, ganador=0;
	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if(table[i][j] == '#'){
				contadorNumeral++;
			}
			if(table[i][j] == '+'){
				contadorMas++;
			}
		}
	}
	if(contadorMas>contadorNumeral){
		ganador=1;
	}else{
		ganador=2;
	}
	return ganador;
}