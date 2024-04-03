#include "General.h"

bool verificar_horse_B(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
	{
		system("cls");
		cout << "Estas intentando colocar el caballo en una pieza propia" << endl;
		return false;
	}
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N)
	{
		cout << "Caballo mata." << endl;
		return true;
	}
	if (mapa[fila_destino][columna_destino] == SIN_NADA)
	{
		return true;
	}


}

bool verificar_horse_N(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {


	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && mapa[fila_destino][columna_destino] <= CHAR_FIN_N)
	{
		system("cls");
		cout << "Estas intentando colocar el caballo en una pieza propia" << endl;
		return false;
	}
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
	{
		cout << "Caballo mata." << endl;
		return true;
	}
	if (mapa[fila_destino][columna_destino] == SIN_NADA)
	{
		return true;
	}


}