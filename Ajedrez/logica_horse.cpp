#include "General.h"

bool verificar_horse_B(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {

	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
	{
		system("cls");
		cout << "Estas intentando colocar el caballo en una pieza propia" << endl;
		return false;
	}
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N)
	{
		cout << "Caballo mata." << endl;
		return true;
	}
	if (mapa[fila_destino][columna_destino] == SIN_NADA)
	{
		return true;
	}


}

bool verificar_horse_N(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]) {


	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && mapa[fila_destino][columna_destino] <= CHAR_FIN_N)
	{
		system("cls");
		cout << "Estas intentando colocar el caballo en una pieza propia" << endl;
		return false;
	}
	if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
	{
		cout << "Caballo mata." << endl;
		return true;
	}
	if (mapa[fila_destino][columna_destino] == SIN_NADA)
	{
		return true;
	}


}

bool verifica_todo_horse(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	bool turno_blancas = (turno == "blancas");
	bool caballo_correcto = false;

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
		if (turno_blancas)
		{
			caballo_correcto = verificar_horse_B(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

		}
		else
		{
			caballo_correcto = verificar_horse_N(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
		}
	}

	if (caballo_correcto)
	{
		return true;
	}
	else
	{
		return false;
	}

}