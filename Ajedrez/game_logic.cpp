#include <iostream>
#include "mapa.h"

#define SIN_NADA '*'
#define ESPACIO ' '

#define NUM_FILAS 9
#define NUM_COLUMNAS 9

using namespace std;

bool moviminento_correcto(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	if (fila_origen < 0 || fila_origen >= NUM_FILAS || columna_origen < 0 || columna_origen >= NUM_COLUMNAS || fila_destino < 0 || fila_destino >= NUM_FILAS || columna_destino < 0 || columna_destino >= NUM_COLUMNAS)
	{
		cout << "Posicion insertada no esta dentro del tablero" << endl;
		return false;
	}
	if (mapa[fila_origen][columna_origen] == SIN_NADA)
	{
		cout << "Posicion insertada no hay nada" << endl;
		return false;
	}
	if (turno == "blancas" && mapa[fila_origen][columna_origen] >= 'A' && mapa[fila_origen][columna_origen] <= 'Z')
	{
		cout << "Estas intentando cambiar una ficha que no te pertenece" << endl;
		return false;
	}
	if (turno == "negras" && mapa[fila_origen][columna_origen] >= 'a' && mapa[fila_origen][columna_origen] <= 'z')
	{
		cout << "Estas intentando cambiar una ficha que no te pertenece" << endl;
		return false;
	}
	else
	{
		return true;
	}



}
void mover_ficha(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	char ficha_a_mover = mapa[fila_origen][columna_origen];

	mapa[fila_origen][columna_origen] = SIN_NADA;
	mapa[fila_destino][columna_destino] = ficha_a_mover;
	system("cls");
	sacar_mapa(mapa);

}

void posiciones_user(char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	short fila_origen, columna_origen, fila_destino, columna_destino;
	bool posicion_correcta = false;

	while (!posicion_correcta)
	{

		cout << "Posicion de la pieza que quieres mover" << endl;

		cout << "Fila donde esta la pieza" << endl;
		cin >> fila_origen;

		cout << "Columna donde esta la pieza" << endl;
		cin >> columna_origen;

		cout << "Posicion donde quieres mover la pieza" << endl;

		cout << "Fila donde quieres moverla" << endl;
		cin >> fila_destino;

		cout << "Columna donde quieres moverla" << endl;
		cin >> columna_destino;

		if (moviminento_correcto(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno))
		{
			cout << "moviminento correcto" << endl;
			posicion_correcta = true;
			mover_ficha(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
		}
		else
		{
			cout << "moviminento incorrecto" << endl;
		}
	}

}
string cambiar_turno(string turno) {

	if (turno == "blancas")
	{
		return "negras";
	}
	else
	{
		return "blancas";
	}
}

bool jaque_mate() {

	return false;

}
