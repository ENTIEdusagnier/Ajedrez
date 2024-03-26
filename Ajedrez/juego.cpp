#include <iostream>
#include "mapa.h"
#include "game_logic.h"

#include <windows.h> // Para hacer un Sleep para poder dejar un tiempo y borrar la terminal. (Sacado de mi proyecto hundir la flota).

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
		cout << "El turno es de: " << turno << endl;
		sacar_mapa(mapa);
		if (posiciones_user(mapa, turno)) 
		{
			turno = cambiar_turno(turno);
			system("cls");
			
		}
		

		if (jaque_mate())
		{
			cout << "NADA";
		}
	}
	
}