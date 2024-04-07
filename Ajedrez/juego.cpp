#include "General.h"

void juego_acabado(string turno) {

	cout << "Ha Ganada el Jugador de las fichas " << turno << endl;

}




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

		short fila_origen, columna_origen, fila_destino, columna_destino;
		bool posicion_correcta = false;

		while (!posicion_correcta)
		{

			cout << "Posicion de la pieza que quieres mover" << endl;

			cout << "Fila donde esta la pieza" << endl;
			cin >> fila_origen;

			cout << "Columna donde esta la pieza" << endl;
			cin >> columna_origen;

			cout << "Posicion donde quieres mover la pieza" << endl;

			cout << "Fila donde quieres moverla" << endl;
			cin >> fila_destino;

			cout << "Columna donde quieres moverla" << endl;
			cin >> columna_destino;

			if (movimiento_correcto(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno))
			{
				cout << "moviminento correcto" << endl;
				posicion_correcta = true;

				if (mapa[fila_destino][columna_destino] == REY_BLANCO || mapa[fila_destino][columna_destino] == REY_NEGRO)
				{
					mover_ficha(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
					Sleep(1000);
					system("cls");

					juego_activo = false;
					juego_acabado(turno);

				}
				else
				{
					mover_ficha(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
					Sleep(1000);
					system("cls");

					turno = cambiar_turno(turno);
				}
			}
			else
			{
				system("cls");
				cout << "moviminento incorrecto" << endl;
				cout << "El turno es de: " << turno << endl;
				sacar_mapa(mapa);

			}
		}

	}

}