#ifndef TABLERO_H
#define TABLERO_H
#include <string>
using std::string;

class Metodos{
	private:
		char** table;
	public:
		void CrearTablero();
		void imprimirTablero();

};