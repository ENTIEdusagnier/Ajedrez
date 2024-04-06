#include "General.h"


bool verifica_derecha_abajo(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	//Hago un for desde la posicion origen + 1 hasta antes del destino para verificar que no hay nada entre el desplacamiento. (El mas uno es para que no detecte la letra donde esta la ficha)
	//PD: puedes ver en los commits que hacia doble bucle pero vi por interent que podias hacer dos variables en un mismo for.

	for (short fila = fila_origen + 1, columna = columna_origen + 1; fila < fila_destino && columna < columna_destino; fila++, columna++)
	{
		if (mapa[fila][columna] >= CHAR_EMPIEZA_B) {
			cout << "Estas pasando por encima de una pieza" << endl;
			return false;
		}
	}
	if ((turno == "blancas" && mapa[fila_destino][fila_destino] >= CHAR_EMPIEZA_N)
		|| (turno == "negras" && mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
		|| mapa[fila_destino][fila_destino] == SIN_NADA) {

		cout << "Ficha puesta" << endl;
		return true;
	}

}

bool verifica_iquierda_arriba(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	for (short fila = fila_destino + 1, columna = columna_destino + 1; fila < fila_origen && columna < columna_origen; fila++, columna++)
	{
		if (mapa[fila][columna] >= CHAR_EMPIEZA_B)
		{
			cout << "Estas pasando por encima de una pieza" << endl;
			return false;
		}

	}
	if ((turno == "blancas" && mapa[fila_destino][fila_destino] >= CHAR_EMPIEZA_N)
		|| (turno == "negras" && mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
		|| mapa[fila_destino][fila_destino] == SIN_NADA) {

		cout << "Ficha puesta" << endl;
		return true;
	}
}

bool verifica_derecha_arriba(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	for (short fila = fila_origen - 1, columna = columna_origen + 1; fila > fila_destino && columna < columna_destino; fila--, columna++)
	{
		if (mapa[fila][columna] >= CHAR_EMPIEZA_B)
		{
			cout << "Estas pasando por encima de una pieza" << endl;
			return false;
		}
	}
	if ((turno == "blancas" && mapa[fila_destino][fila_destino] >= CHAR_EMPIEZA_N)
		|| (turno == "negras" && mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
		|| mapa[fila_destino][fila_destino] == SIN_NADA) {

		cout << "Ficha puesta" << endl;
		return true;
	}
}


bool verifica_iquierda_abajo(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	for (short fila = fila_origen + 1, columna = columna_origen - 1; fila < fila_destino && columna > columna_destino; fila++, columna--)
	{


		if (mapa[fila][columna] >= CHAR_EMPIEZA_B)
		{
			cout << "Estas pasando por encima de una pieza" << endl;
			return false;
		}

	}
	if ((turno == "blancas" && mapa[fila_destino][fila_destino] >= CHAR_EMPIEZA_N)
		|| (turno == "negras" && mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
		|| mapa[fila_destino][fila_destino] == SIN_NADA) {

		cout << "Ficha puesta" << endl;
		return true;
	}
}

bool verifica_todo_alfil(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	//Mira si el movimiento es hacia arriba la izquierda y verifica si es en diagonal
	bool es_movimiento_iquierda_arriba = (fila_origen - fila_destino == columna_origen - columna_destino && fila_destino < fila_origen && columna_destino < columna_origen);
	//Mira si el movimiento es hacia arriba la derecha y verifica si es en diagonal
	bool es_movimiento_derecha_arriba = (fila_origen - fila_destino == columna_destino - columna_origen && fila_destino < fila_origen && columna_destino > columna_origen);
	//Mira si el movimiento es hacia abajo la izquierda y verifica si es en diagonal
	bool es_movimiento_iquierda_abajo = (fila_destino - fila_origen == columna_origen - columna_destino && fila_destino > fila_origen && columna_destino < columna_origen);
	//Mira si el movimiento es hacia abajo la derecha y verifica si es en diagonal
	bool es_movimiento_derecha_abajo = (fila_destino - fila_origen == columna_destino - columna_origen && fila_destino > fila_origen && columna_destino > columna_origen);

	bool alfil_correcto = false;

	//Si no esta bien el movimiento dara error y retorna false.
	if (!es_movimiento_iquierda_arriba && !es_movimiento_derecha_arriba && !es_movimiento_iquierda_abajo && !es_movimiento_derecha_abajo)
	{
		cout << "El alfil no puede hacer este movimiento." << endl;
		return false;
	}
	else
	{
		//Verificamientos de los posibles movimientos en las direciones.
		if (es_movimiento_derecha_abajo)
		{
			alfil_correcto = verifica_derecha_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
		}
		if (es_movimiento_iquierda_arriba)
		{
			alfil_correcto = verifica_iquierda_arriba(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);

		}
		if (es_movimiento_derecha_arriba)
		{
			alfil_correcto = verifica_derecha_arriba(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);

		}
		if (es_movimiento_iquierda_abajo)
		{
			alfil_correcto = verifica_iquierda_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
		}
	}

	if (alfil_correcto)
	{
		return true;
	}
	else
	{
		return false;
	}

}