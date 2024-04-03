#include "General.h"




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