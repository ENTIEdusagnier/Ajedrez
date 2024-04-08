#include "General.h"



bool verifica_movimiento(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	//Solo verifica que no haya errores.
	bool es_turno_blancas = (turno == "blancas");
	const short fila_inicial_blancas = 7;
	const short fila_inicial_negras = 2;
	bool es_fila_inicial_blancas = (fila_origen == fila_inicial_blancas);
	bool es_fila_inicial_negras = (fila_origen == fila_inicial_negras);

	if (es_turno_blancas) {

		if (es_fila_inicial_blancas) {
			//Verifica que el movimiento vertical del peon es correcto.
			if (fila_destino != fila_origen - 1 && fila_destino != fila_origen - 2) {
				system("cls");
				cout << "Estas intentando mover el peon en una direcion no posible (1)" << endl;
				return false;
			}
		}
		//Si no es fila inicial
		if (!es_fila_inicial_blancas) {
			// Y l movimiento no es igual a 1 es error.
			if (fila_destino != fila_origen - 1) {
				system("cls");
				cout << "Estas intentando mover el peon en una direcion no posible (2)" << endl;
				return false;
			}
		}
		//Si para por encima de alguna ficha es Error.
		for (short i = fila_destino; i < fila_origen; i++) {

			if (mapa[i][columna_origen] != SIN_NADA) {
				system("cls");
				cout << "Estas pasando por encima de una pieza" << endl;
				return false;
			}
		}

	}
	//Turno de negras
	else
	{
		if (es_fila_inicial_negras) {
			//Verifica que el movimiento vertical del peon es correcto.
			if (fila_destino != fila_origen + 1 && fila_destino != fila_origen + 2) {
				system("cls");
				cout << "Estas intentando mover el peon en una direcion no posible 1" << endl;
				return false;
			}
		}
		if (!es_fila_inicial_negras) {

			if (fila_destino != fila_origen + 1) {
				system("cls");
				cout << "Estas intentando mover el peon en una direcion no posible 2" << endl;
				return false;
			}
		}

		for (short i = fila_origen + 1; i <= fila_destino; i++) {

			if (mapa[i][columna_origen] != SIN_NADA) {
				system("cls");
				cout << "Estas pasando por encima de una pieza" << endl;
				return false;
			}
		}
	}


}
bool verifica_movimiento_lateral(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	bool turno_blancas = (turno == "blancas");

	if (turno_blancas)
	{
		//Si el movimiento no es igual a 1 movimiento diagonal ERROR.
		if ((fila_destino != fila_origen + 1 && fila_destino != fila_origen - 1)
			|| (columna_destino != columna_origen + 1 && columna_destino != columna_origen - 1)) {
			system("cls");
			cout << "El movimiento no lateral no puede exceder 1" << endl;
			return false;
		}
		//Si el movimiento no es igual a nada y es igual a una ficha oponente mata.
		if (mapa[fila_destino][columna_destino] != SIN_NADA && (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N)) {
			// El peon mata una ficha del oponente
			cout << "El peon mata." << endl;
			return true;
		}
		else
		{
			system("cls");
			// El peon pasa de largo sin capturar una ficha
			cout << "El peon pasa de largo y por encima de otra ficha." << endl;
			return false;
		}
	}
	else
	{
		if  ((fila_destino != fila_origen + 1 && fila_destino != fila_origen - 1)
			|| (columna_destino != columna_origen + 1 && columna_destino != columna_origen - 1)) {
			system("cls");
			cout << "El movimiento no lateral no puede exceder 1" << endl;
			return false;
		}
		if (mapa[fila_destino][columna_destino] != SIN_NADA && (mapa[fila_destino][columna_destino] <= CHAR_FIN_B && mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B)) {
			// El peon mata una ficha del oponente
			cout << "El peon mata." << endl;
			return true;
		}
		else
		{
			system("cls");
			// El peon pasa de largo sin capturar una ficha
			cout << "El peon pasa de largo y por encima de otra ficha." << endl;
			return false;
		}
	}



	
}

bool peon_a_reina(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	//Si la ficha es peon
	if (mapa[fila_origen][columna_origen] == 'P' || mapa[fila_origen][columna_origen] == 'p')
	{
		// Y su fila destino es igual al final.
		if (fila_destino == 1 || fila_destino == 8) {

			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		return false;
	}

}


