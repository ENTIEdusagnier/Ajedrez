#include <iostream>
#include <windows.h>


#define SIN_NADA '*'
#define ESPACIO ' '

#define NUM_FILAS 9
#define NUM_COLUMNAS 9

using namespace std;


bool verifica_movimiento_vertical_B(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = fila_destino; i < fila_origen; i++)
	{
		if (mapa[i][columna_origen] <= 'Z' && mapa[i][columna_origen] >= 'A' || mapa[i + 1][columna_origen] >= 'a') {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= 'a' && !pieza_por_el_medio)
	{
		cout << "Pieza comida" << endl;
		return true;
	}
	if (pieza_por_el_medio)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool verifica_movimiento_vertical_B_abajo(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = fila_origen + 1; i <= fila_destino; i++)
	{
		if (mapa[i][columna_origen] <= 'Z' && mapa[i][columna_origen] >= 'A' || mapa[i - 1][columna_origen] >= 'a') {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
		if (mapa[fila_destino][columna_destino] >= 'a' && !pieza_por_el_medio)
		{
			cout << "Pieza comida" << endl;
			return true;
		}
		if (pieza_por_el_medio)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

}

bool verifica_movimiento_Lateral_B(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = columna_origen + 1; i <= columna_destino; i++)
	{
		if (mapa[fila_origen][i] <= 'Z' && mapa[fila_origen][i] >= 'A' || mapa[fila_origen][i - 1] >= 'a') {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= 'a' && !pieza_por_el_medio)
	{
		cout << "Pieza comida" << endl;
		return true;
	}
	if (pieza_por_el_medio)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool verifica_movimiento_Lateral_B_izquierda(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = columna_destino; i < columna_origen; i++)
	{
		if (mapa[fila_origen][i] <= 'Z' && mapa[fila_origen][i] >= 'A' || mapa[fila_origen][i + 1] >= 'a') {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= 'a' && !pieza_por_el_medio)
	{
		cout << "Pieza comida" << endl;
		return true;
	}
	if (pieza_por_el_medio)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool verifica_movimiento_vertical_N(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = fila_destino; i < fila_origen; i++)
	{
		if (mapa[i][columna_origen] <= 'z' && mapa[i][columna_origen] >= 'a' || mapa[i - 1][columna_origen] >= 'A') {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
		if (mapa[fila_destino][columna_destino] >= 'A' && mapa[fila_destino][columna_destino] <= 'Z' && !pieza_por_el_medio)
		{
			cout << "Pieza comida" << endl;
			return true;
		}
		if (pieza_por_el_medio)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

}

bool verifica_movimiento_vertical_N_abajo(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = fila_origen + 1; i <= fila_destino; i++)
	{
		if (mapa[i][columna_origen] <= 'z' && mapa[i][columna_origen] >= 'a' || mapa[i + 1][columna_origen] >= 'A') {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= 'A' && mapa[fila_destino][columna_destino] <= 'Z' && !pieza_por_el_medio)
	{
		cout << "Pieza comida" << endl;
		return true;
	}
	if (pieza_por_el_medio)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool verifica_movimiento_Lateral_N(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = columna_origen + 1; i <= columna_destino; i++)
	{
		if (mapa[fila_origen][i] <= 'Z' && mapa[fila_origen][i] >= 'A' || mapa[fila_origen][i + 1] >= 'a') {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= 'A' && mapa[fila_destino][columna_destino] <= 'Z' && !pieza_por_el_medio)
	{
		cout << "Pieza comida" << endl;
		return true;
	}
	if (pieza_por_el_medio)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool verifica_movimiento_Lateral_N_izquierda(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = columna_destino; i < columna_origen; i++)
	{
		if (mapa[fila_origen][i] <= 'z' && mapa[fila_origen][i] >= 'a' || mapa[fila_origen][i - 1] >= 'A') {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= 'A' && mapa[fila_destino][columna_destino] <= 'Z' && !pieza_por_el_medio)
	{
		cout << "Pieza comida" << endl;
		return true;
	}
	if (pieza_por_el_medio)
	{
		return false;
	}
	else
	{
		return true;
	}

}



