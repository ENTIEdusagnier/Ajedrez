#include <iostream>
#include "mapa.h"

#define SIN_NADA '*'
#define ESPACIO ' '

#define NUM_FILAS 9
#define NUM_COLUMNAS 9

using namespace std;

bool logica_peon(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	if ((fila_destino != fila_origen - 2 && fila_destino != fila_origen - 1) || columna_origen != columna_destino)
	{
		cout << "Estas intentando mover el peon en una direcion no posible" << endl;
		return false;
	}
	else
	{
		return true;
	}

}
bool logica_torre(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	cout << "ola";
	return true;
}

bool moviminento_correcto(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	//Verificamos que no pone unos numeros fuera del tablero
	if (fila_origen < 0 || fila_origen >= NUM_FILAS || columna_origen < 0 || columna_origen >= NUM_COLUMNAS || fila_destino < 0 || fila_destino >= NUM_FILAS || columna_destino < 0 || columna_destino >= NUM_COLUMNAS)
	{
		cout << "Posicion insertada no esta dentro del tablero" << endl;
		return false;
	}
	//Verificamos que no ponga una posición donde no hay ficha
	if (mapa[fila_origen][columna_origen] == SIN_NADA)
	{
		cout << "Posicion insertada no hay nada" << endl;
		return false;
	}
	//Verificamos que si esta el turno de las blancas (Mayusculas) no intente mover una ficha del jugador de negras (minusculas)
	if (turno == "blancas" && mapa[fila_origen][columna_origen] >= 'a' && mapa[fila_origen][columna_origen] <= 'z')
	{
		cout << "Estas intentando cambiar una ficha que no te pertenece" << endl;
		return false;
	}
	//Verificamos lo mismo con el jugador de las negras.
	if (turno == "negras" && mapa[fila_origen][columna_origen] >= 'A' && mapa[fila_origen][columna_origen] <= 'Z')
	{
		cout << "Estas intentando cambiar una ficha que no te pertenece" << endl;
		return false;
	}
	//Verifico que el peon (sea el turno de quien sea) se mueva hacia arriba 1 o 2 cuadrados solo, y no se mueva por las columnas es decir lateralmente.

	else
	{
		bool resultado = false;
		switch (mapa[fila_origen][columna_origen])
		{
		case 'P':
		case 'p':
			resultado = logica_peon(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			break;
		case 't':
		case 'T':
			resultado = logica_torre(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			break;

		}

		if (resultado)
		{
			return true;
		}
		else
		{
			return false;
		}
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
