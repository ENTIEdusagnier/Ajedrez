#include "General.h"


//Verifica los movimientos de las blancas
//Verifica el vertical hacia arriba
bool verifica_movimiento_vertical_B(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = fila_destino; i < fila_origen; i++)
	{
		//Verifico que no haya ninguna ficha propia o enemiga durate el recorido
		if (mapa[i][columna_origen] <= CHAR_FIN_B && mapa[i][columna_origen] >= CHAR_EMPIEZA_B || mapa[i + 1][columna_origen] >= CHAR_EMPIEZA_N) {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	//Si la ficha final es enemiga y no ha pasado por encima de otra pieza se da por comida
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && !pieza_por_el_medio)
	{
		cout << "Pieza comida" << endl;
		return true;
	}
	//Si pasa por encima de una pieza se retorna falso
	if (pieza_por_el_medio)
	{
		return false;
	}
	else
	{
		return true;
	}

}
//Verifica el vertical hacia abajo
bool verifica_movimiento_vertical_B_abajo(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = fila_origen + 1; i <= fila_destino; i++)
	{
		if (mapa[i][columna_origen] <= CHAR_FIN_B && mapa[i][columna_origen] >= CHAR_EMPIEZA_B || mapa[i - 1][columna_origen] >= CHAR_EMPIEZA_N) {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
		if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && !pieza_por_el_medio)
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
//Verifica el lateral hacia derecha
bool verifica_movimiento_Lateral_B(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = columna_origen + 1; i <= columna_destino; i++)
	{
		if (mapa[fila_origen][i] <= CHAR_FIN_B && mapa[fila_origen][i] >= CHAR_EMPIEZA_B || mapa[fila_origen][i - 1] >= CHAR_EMPIEZA_N) {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && !pieza_por_el_medio)
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
//Verifica el lateral hacia izquierda
bool verifica_movimiento_Lateral_B_izquierda(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = columna_destino; i < columna_origen; i++)
	{
		if (mapa[fila_origen][i] <= CHAR_FIN_B && mapa[fila_origen][i] >= CHAR_EMPIEZA_B || mapa[fila_origen][i + 1] >= CHAR_EMPIEZA_N) {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && !pieza_por_el_medio)
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


//Verifica los movimientos de las negras
//Verifica el vertical hacia arriba
bool verifica_movimiento_vertical_N(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = fila_destino; i < fila_origen; i++)
	{
		if (mapa[i][columna_origen] <= CHAR_FIN_N && mapa[i][columna_origen] >= CHAR_EMPIEZA_N || mapa[i - 1][columna_origen] >= CHAR_EMPIEZA_B) {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
		if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B && !pieza_por_el_medio)
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
//Verifica el vertical hacia abajo
bool verifica_movimiento_vertical_N_abajo(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = fila_origen + 1; i <= fila_destino; i++)
	{
		if (mapa[i][columna_origen] <= CHAR_FIN_N && mapa[i][columna_origen] >= CHAR_EMPIEZA_N || mapa[i + 1][columna_origen] >= CHAR_EMPIEZA_B) {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B && !pieza_por_el_medio)
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
//Verifica el lateral hacia derecha
bool verifica_movimiento_Lateral_N(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = columna_origen + 1; i <= columna_destino; i++)
	{
		if (mapa[fila_origen][i] <= CHAR_FIN_B && mapa[fila_origen][i] >= CHAR_EMPIEZA_B || mapa[fila_origen][i + 1] >= CHAR_EMPIEZA_N) {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B && !pieza_por_el_medio)
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
//Verifica el lateral hacia izquierda
bool verifica_movimiento_Lateral_N_izquierda(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	bool pieza_por_el_medio = false;

	for (short i = columna_destino; i < columna_origen; i++)
	{
		if (mapa[fila_origen][i] <= CHAR_FIN_N && mapa[fila_origen][i] >= CHAR_EMPIEZA_N || mapa[fila_origen][i - 1] >= CHAR_EMPIEZA_B) {
			system("cls");
			cout << "Estas pasando por encima de una pieza" << endl;
			pieza_por_el_medio = true;
		}
	}
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B && !pieza_por_el_medio)
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



