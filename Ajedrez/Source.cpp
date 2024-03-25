#include <iostream>
#include "mapa.h"

//Permite no utilizar std::
using namespace std;


void main() {

	char mapa[NUM_FILAS][NUM_COLUMNAS];
	crear_tabla(mapa);
	poner_piezas(mapa);
	sacar_mapa(mapa);


}

