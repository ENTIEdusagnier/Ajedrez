#define NUM_FILAS 9
#define NUM_COLUMNAS 9

#define SIN_NADA '*'
#define ESPACIO ' '
#include <iostream>

using namespace std;

void crear_tabla(char mapa[NUM_FILAS][NUM_COLUMNAS]) {


	for (short i = 0; i < NUM_FILAS; i++) {
		for (short j = 0; j < NUM_COLUMNAS; j++) {

			if (i == 0 && j != 0) {
				// De esta manera me permite convertir el int en char.
				mapa[i][j] = '0' + j;
			}
			else if (j == 0 && i != 0) {
				mapa[i][j] = '0' + i;
			}
			else {
				mapa[i][j] = SIN_NADA;
			}

		}
	}
	mapa[0][0] = ESPACIO;

}
void poner_piezas(char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	const char piezas_minus[8] = { 't', 'h', 'b', 'q', 'k', 'b', 'h', 't' };
	const char peones_minus[8] = { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' };
	const char piezas_mayus[8] = { 'T', 'H', 'B', 'Q', 'K', 'B', 'H', 'T' };
	const char peones_mayus[8] = { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' };


	for (int i = 0; i < NUM_FILAS; i++) {
		for (int j = 0; j < NUM_COLUMNAS; j++) {

			if (i == 7 && j != 0) {
				mapa[i][j] = peones_mayus[j - 1];
			}
			if (i == 8 && j != 0) {
				mapa[i][j] = piezas_mayus[j - 1];
			}
			if (i == 1 && j != 0) {
				mapa[i][j] = piezas_minus[j - 1];
			}
			if (i == 2 && j != 0) {
				mapa[i][j] = peones_minus[j - 1];
			}
		}
	}


}

void sacar_mapa(char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	
	for (short i = 0; i < NUM_FILAS; i++) {
		for (short j = 0; j < NUM_COLUMNAS; j++) {

			cout << mapa[i][j] << ESPACIO;


		}
		cout <<endl;
	}
}