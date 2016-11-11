#ifndef TABLERO_H
#define TABLERO_H
#include <string>
using std::string;

class Metodos{
	private:
		char** table;
	public:
		Tablero();
		void imprimirTablero();
		void movimientoTablero(int, int, int);
		bool Verificacion(int, int, int, int, int);
		bool Lleno();
		int GanadorDeDiferencia();
		int GanadorPorTotal();
};