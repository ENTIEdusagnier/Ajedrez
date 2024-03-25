#define NUM_FILAS 9
#define NUM_COLUMNAS 9

#define SIN_NADA '*'
#define ESPACIO ' '


#include <iostream>
#include <thread>
#include <chrono>

//Permite no utilizar std::
using namespace std;


void meter_piezas() {




}

void crear_tabla(char mapa[NUM_FILAS][NUM_COLUMNAS]) {


	for (int i = 0; i < NUM_FILAS; i++) {
		for (int j = 0; j < NUM_COLUMNAS; j++) {

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

	char piezas_mayus[] = { 'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T' };
	char peones_mayus[] = { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P' };
	char piezas_minus[] = { 't', 'c', 'a', 'd', 'r', 'a', 'c', 't' };
	char peones_minus[] = { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p' };

	for (int i = 0; i < NUM_FILAS; i++) {
		for (int j = 0; j < NUM_COLUMNAS; j++) {

			if (i == 7 && j != 0){
				mapa[i][j] = peones_mayus[j - 1];
			}
			if (i == 8 && j != 0){
				mapa[i][j] = piezas_mayus[j - 1];
			}
			if (i == 1 && j != 0){
				mapa[i][j] = piezas_minus[j - 1];
			}
			if (i == 2 && j != 0) {
				mapa[i][j] = peones_minus[j - 1];
			}
		}
	}


}

void sacar_mapa(char mapa[NUM_FILAS][NUM_COLUMNAS]) {




	for (int i = 0; i < NUM_FILAS; i++) {
		for (int j = 0; j < NUM_COLUMNAS; j++) {

			cout << mapa[i][j] << ESPACIO;


		}
		cout << endl;
	}
}

void main() {

	char mapa[NUM_FILAS][NUM_COLUMNAS];
	crear_tabla(mapa);
	poner_piezas(mapa);
	sacar_mapa(mapa);


}

