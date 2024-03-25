#include <iostream>
#include "mapa.h"
#include "game_logic.h"

#define SIN_NADA '*'
#define ESPACIO ' '

#define NUM_FILAS 9
#define NUM_COLUMNAS 9

using namespace std;



void juego() {

	char mapa[NUM_FILAS][NUM_COLUMNAS];
	bool juego_activo = true;
	string turno = "blancas";

	crear_tabla(mapa);
	poner_piezas(mapa);

	while (juego_activo)
	{
		sacar_mapa(mapa);
		posiciones_user(mapa, turno);

		if (jaque_mate())
		{
			cout << "NADA";
		}
	}
	
}