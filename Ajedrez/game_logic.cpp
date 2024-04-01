#include <iostream>
#include <windows.h>
#include "mapa.h"
#include "movimientos_peon.h"
#include "logica_torre.h"

#define SIN_NADA '*'
#define ESPACIO ' '

#define NUM_FILAS 9
#define NUM_COLUMNAS 9
#define REINA_BLANCA 'Q'
#define REINA_NEGRA 'q'

using namespace std;


bool logica_peon(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {


	bool peon_correcto = false;

	bool movimiento_lateral = (columna_origen != columna_destino);

	if (movimiento_lateral) {
		peon_correcto = verifica_movimiento_lateral(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
	}
	else {
		peon_correcto = verifica_movimiento(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
	}


	if (peon_correcto) {
		return true;
	}
	else {
		return false;
	}
}



bool logica_torre(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	bool es_turno_blancas = (turno == "blancas");

	bool es_movimiento_vertical = (fila_origen != fila_destino && columna_origen == columna_destino);
	bool es_movimiento_lateral = (fila_origen == fila_destino && columna_origen != columna_destino);

	//Me indica el la direcion veritcal (arriba o abajo) la qual quiere que se mueva la torre. Para poder hacer diferentes if's.
	bool tipo_movimiento_vertical = (fila_destino < fila_origen); //Arriba (Blancas) Abajo (Negras)
	bool tipo_movimineto_lateral = (columna_destino > columna_origen); //Derecha (Blancas) Izquierda (Negras)

	bool torre_correcta = false;

	if (!es_movimiento_lateral && !es_movimiento_vertical)
	{
		cout << "No puedes mover la torre en diagonal" << endl;
		return false;
	}

	if (es_turno_blancas)
	{
		if (es_movimiento_vertical)
		{
			if (tipo_movimiento_vertical) //arriba
			{
				torre_correcta = verifica_movimiento_vertical_B(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

			}
			else //Abajo 
			{
				torre_correcta = verifica_movimiento_vertical_B_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
		}
		else //Lateral
		{
			if (tipo_movimineto_lateral) //Derecha
			{
				torre_correcta = verifica_movimiento_Lateral_B(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
			else //Izquierda
			{
				torre_correcta = verifica_movimiento_Lateral_B_izquierda(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
		}

	}
	else //Negras
	{
		if (es_movimiento_vertical)
		{
			if (tipo_movimiento_vertical) // Abajo
			{
				torre_correcta = verifica_movimiento_vertical_N(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
			else
			{
				torre_correcta = verifica_movimiento_vertical_N_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
		}
		else
		{
			if (tipo_movimineto_lateral) //Izquierda
			{
				torre_correcta = verifica_movimiento_Lateral_N(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
			else
			{
				torre_correcta = verifica_movimiento_Lateral_N_izquierda(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
		}
	}

	if (!torre_correcta)
	{
		return false;
	}
	else
	{
		return true;
	}

}


bool logica_horse(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	bool es_turno_blancas = (turno == "blancas");

	//Verifica si los movimientos verticales y inferiores del caballo es hacia la derecha o izquierda
	bool es_movimiento_vertical_derecha = ((fila_origen - fila_destino == 2) && (columna_destino - columna_origen == 1));
	bool es_movimiento_vertical_izquierda = ((fila_origen - fila_destino == 2) && (columna_origen - columna_destino == 1));
	bool es_movimineto_inferior_derecha = ((fila_destino - fila_origen == 2) && (columna_destino - columna_origen == 1));
	bool es_movimineto_inferior_izquierda = ((fila_destino - fila_origen == 2) && (columna_origen - columna_destino == 1));

	//Verifica los movimientos hacia un lado y luego arriba o abajo
	bool es_movimiento_derecha_arriba = ((fila_origen - fila_destino == 1) && (columna_destino - columna_origen == 2));
	bool es_movimiento_derecha_abajo = ((fila_destino - fila_origen == 1) && (columna_destino - columna_origen == 2));
	bool es_movimiento_izquierda_arriba = ((fila_origen - fila_destino == 1) && (columna_origen - columna_destino == 2));
	bool es_movimiento_izquierda_abajo = ((fila_destino - fila_origen == 1) && (columna_origen - columna_destino == 2));

	//Si ninguno es true significa que el usuario ha puesto un numero unas cordenadas que no funionan con la logica.
	if (!es_movimiento_vertical_derecha && !es_movimiento_vertical_izquierda && !es_movimineto_inferior_derecha && !es_movimineto_inferior_izquierda
		&& !es_movimiento_derecha_arriba && !es_movimiento_derecha_abajo && !es_movimiento_izquierda_arriba && !es_movimiento_izquierda_abajo)
	{
		cout << "Caballo no puede hacer ese movimiento" << endl;
		return false;
	}
	else
	{
		if (es_turno_blancas)
		{

			if (mapa[fila_destino][columna_destino] >= 'A' && mapa[fila_destino][columna_destino] <= 'Z')
			{
				system("cls");
				cout << "Estas intentando colocar el caballo en una pieza propia" << endl;
				return false;
			}
			if (mapa[fila_destino][columna_destino] >= 'a')
			{
				cout << "Caballo mata." << endl;
				return true;
			}
			if (mapa[fila_destino][columna_destino] == SIN_NADA)
			{
				return true;
			}
		}
		else
		{
			if (mapa[fila_destino][columna_destino] >= 'a' && mapa[fila_destino][columna_destino] <= 'z')
			{
				system("cls");
				cout << "Estas intentando colocar el caballo en una pieza propia" << endl;
				return false;
			}
			if (mapa[fila_destino][columna_destino] >= 'A' && mapa[fila_destino][columna_destino] <= 'Z')
			{
				cout << "Caballo mata." << endl;
				return true;
			}
			if (mapa[fila_destino][columna_destino] == SIN_NADA)
			{
				return true;
			}
		}
	}





}

bool logica_alfil(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	bool es_turno_blancas = (turno == "blancas");

	//Mira si el movimiento es hacia arriba la izquierda y verifica si es en diagonal
	bool es_movimiento_iquierda_arriba = (fila_origen - fila_destino == columna_origen - columna_destino && fila_destino < fila_origen && columna_destino < columna_origen);
	//Mira si el movimiento es hacia arriba la derecha y verifica si es en diagonal
	bool es_movimiento_derecha_arriba = (fila_origen - fila_destino == columna_destino - columna_origen && fila_destino < fila_origen && columna_destino > columna_origen);
	//Mira si el movimiento es hacia abajo la izquierda y verifica si es en diagonal
	bool es_movimiento_iquierda_abajo = (fila_destino - fila_origen == columna_origen - columna_destino && fila_destino > fila_origen && columna_destino < columna_origen);
	//Mira si el movimiento es hacia abajo la derecha y verifica si es en diagonal
	bool es_movimiento_derecha_abajo = (fila_destino - fila_origen == columna_destino - columna_origen && fila_destino > fila_origen && columna_destino > columna_origen);

	//Si no esta bien el movimiento dara error y retorna false.
	if (!es_movimiento_iquierda_arriba && !es_movimiento_derecha_arriba && !es_movimiento_iquierda_abajo && !es_movimiento_derecha_abajo)
	{
		cout << "El alfil no puede hacer este movimiento." << endl;
		return false;
	}
	else
	{

		if (es_turno_blancas)
		{
			if (es_movimiento_derecha_abajo)
			{
				//Hago un for desde la posicion origen + 1 hasta antes del destino para verificar que no hay nada entre el desplacamiento. (El mas uno es para que no detecte la letra donde esta la ficha)
				for (short i = fila_origen + 1; i < fila_destino; i++)
				{
					for (short y = columna_origen + 1; y < columna_destino; y++)
					{
						if (mapa[i][y] >= 'A')
						{
							cout << "Estas pasando por encima de una pieza" << endl;
							return false;
						}
					}
				}
				if (mapa[fila_destino][fila_destino] >= 'a' || mapa[fila_destino][fila_destino] == SIN_NADA)
				{
					cout << "Ficha puesta" << endl;
					return true;
				}
			}
			if (es_movimiento_iquierda_arriba)
			{
				for (short i = fila_destino + 1; i < fila_origen; i++)
				{
					for (short y = columna_destino + 1; y < fila_origen; y++)
					{
						if (mapa[i][y] >= 'A')
						{
							cout << "Estas pasando por encima de una pieza" << endl;
							return false;
						}
					}
				}
				if (mapa[fila_destino][fila_destino] >= 'a' || mapa[fila_destino][fila_destino] == SIN_NADA)
				{
					cout << "Ficha puesta" << endl;
					return true;
				}

			}
			//Falta hacer la logica correcta
			if (es_movimiento_derecha_arriba)
			{
				for (short i = fila_destino + 1; i < fila_origen; i++)
				{
					for (short y = columna_destino + 1; y < columna_origen; y++)
					{
						if (mapa[i][y] >= 'A')
						{
							cout << "Estas pasando por encima de una pieza" << endl;
							return false;
						}
					}
				}
				if (mapa[fila_destino][fila_destino] >= 'a' || mapa[fila_destino][fila_destino] == SIN_NADA)
				{
					cout << "Ficha puesta" << endl;
					return true;
				}
			}


			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
		return true;
	}



}

bool movimiento_correcto(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	//Verificamos que no pone unos numeros fuera del tablero
	if (fila_origen < 0 || fila_origen >= NUM_FILAS || columna_origen < 0 || columna_origen >= NUM_COLUMNAS || fila_destino < 0
		|| fila_destino >= NUM_FILAS || columna_destino < 0 || columna_destino >= NUM_COLUMNAS)
	{
		system("cls");
		cout << "Posicion insertada no esta dentro del tablero" << endl;
		return false;
	}
	//Verificamos que no ponga una posición donde no hay ficha
	if (mapa[fila_origen][columna_origen] == SIN_NADA)
	{
		system("cls");
		cout << "Posicion insertada no hay nada" << endl;
		return false;
	}
	//Verificamos que si esta el turno de las blancas (Mayusculas) no intente mover una ficha del jugador de negras (minusculas)
	if (turno == "blancas" && mapa[fila_origen][columna_origen] >= 'a' && mapa[fila_origen][columna_origen] <= 'z')
	{
		system("cls");
		cout << "Estas intentando cambiar una ficha que no te pertenece" << endl;
		return false;
	}
	//Verificamos lo mismo con el jugador de las negras.
	if (turno == "negras" && mapa[fila_origen][columna_origen] >= 'A' && mapa[fila_origen][columna_origen] <= 'Z')
	{
		system("cls");
		cout << "Estas intentando cambiar una ficha que no te pertenece" << endl;
		return false;
	}
	//Verifico que el peon (sea el turno de quien sea) se mueva hacia arriba 1 o 2 cuadrados solo, y no se mueva por las columnas es decir lateralmente.

	else
	{
		bool resultado = false;
		switch (mapa[fila_origen][columna_origen])
		{
		case 'P':
		case 'p':
			resultado = logica_peon(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
			break;
		case 't':
		case 'T':
			resultado = logica_torre(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
			break;
		case 'H':
		case 'h':
			resultado = logica_horse(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
			break;
		case 'B':
		case 'b':
			resultado = logica_alfil(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
			break;
		}

		if (resultado)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



}




void mover_ficha(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	char ficha_a_mover = mapa[fila_origen][columna_origen];

	//Verifica si el peon correcto se combierte a dama o no.
	if (peon_a_reina(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno))
	{
		if (turno == "blancas")
		{
			mapa[fila_origen][columna_origen] = SIN_NADA;
			mapa[fila_destino][columna_destino] = REINA_BLANCA;
		}
		else
		{
			mapa[fila_origen][columna_origen] = SIN_NADA;
			mapa[fila_destino][columna_destino] = REINA_NEGRA;
		}

	}
	else {
		mapa[fila_origen][columna_origen] = SIN_NADA;
		mapa[fila_destino][columna_destino] = ficha_a_mover;
	}

}

string cambiar_turno(string turno) {

	if (turno == "blancas")
	{
		return "negras";
	}
	else
	{
		return "blancas";
	}
}

bool posiciones_user(char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

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
			mover_ficha(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
			Sleep(1000);
			return true;

		}
		else
		{
			system("cls");
			cout << "moviminento incorrecto" << endl;
			return false;
		}
	}

}


bool jaque_mate() {

	return false;

}
