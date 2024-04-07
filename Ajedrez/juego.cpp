#include "General.h"




void juego() {

	char mapa[NUM_FILAS][NUM_COLUMNAS];
	bool juego_activo = true;
	string turno = "blancas";

	crear_tabla(mapa);
	poner_piezas(mapa);

	//Este cout esta sacado de aqui https://gist.github.com/vivia11/fd4d8ef84b65a9ac7d0df132363beb6d
	cout << "   _____ _    _ ______  _____ _____ \n  / ____| |  | |  ____|/ ____/ ____| \n | |    | |__| | |__  | (___| (___  \n | |    |  __  |  __|  \\___  \\___ \\ \n | |____| |  | | |____ ____) |___) | \n  \\_____|_|  |_|______|_____/_____/ \n" << endl;

	while (juego_activo)
	{
		cout << "El turno es de: " << turno << endl;
		sacar_mapa(mapa);
		if (posiciones_user(mapa, turno))
		{
			//turno = cambiar_turno(turno);
			system("cls");
			
		}
		

	
	}
	
}