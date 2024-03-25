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

char crear_tabla() {

	char mapa[NUM_FILAS][NUM_COLUMNAS];
	for (int i = 0; i < NUM_FILAS; i++)
	{
		for (int j = 0; j < NUM_COLUMNAS; j++) {

			if (i == 0 && j != 0)
			{
				mapa[i][j] = '0' + j; // De esta manera me permite convertir el int en char.
			}
			else if (j == 0 && i != 0)
			{
				mapa[i][j] = '0' + i;
			}
			else
			{
				mapa[i][j] = SIN_NADA;
			}

		}
	}
	mapa[0][0] = ESPACIO;
}

void sacar_mapa() {








	for (int i = 0; i < NUM_FILAS; i++) {
		for (int j = 0; j < NUM_COLUMNAS; j++) {

			cout << mapa[i][j] << ESPACIO;


		}
		cout << endl;
	}
}

