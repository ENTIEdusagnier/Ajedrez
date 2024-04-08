#include "General.h"

//Crearenis unos booleanos globales los cuales nos indicaran si los reyes o torres se han movido para el enroque.
bool rey_movido_enroque_B = false;
bool rey_movido_enroque_N = false;

bool torre_izquierda_movida_B = false;
bool torre_derecha_movida_B = false;

bool torre_izquierda_movida_N = false;
bool torre_derecha_movida_N = false;

bool logica_peon(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	//Creamos dos bool para la verificacion del movimiento del peon.
	bool peon_correcto = false;

	bool movimiento_lateral = (columna_origen != columna_destino);

	//Si el movimineto es lateral verificara la funcion lateral.
	if (movimiento_lateral) {
		peon_correcto = verifica_movimiento_lateral(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
	}
	else {
		peon_correcto = verifica_movimiento(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
	}

	//Si peon es correcto retornara true para mover la ficha.
	if (peon_correcto) {
		return true;
	}
	else {
		return false;
	}
}



bool logica_torre(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	//Verificamos todo tipo de movimineto de la torre.
	bool es_turno_blancas = (turno == "blancas");

	bool es_movimiento_vertical = (fila_origen != fila_destino && columna_origen == columna_destino);
	bool es_movimiento_lateral = (fila_origen == fila_destino && columna_origen != columna_destino);

	//Me indica el la direcion veritcal (arriba o abajo) la qual quiere que se mueva la torre. Para poder hacer diferentes if's.
	bool tipo_movimiento_vertical = (fila_destino < fila_origen);
	bool tipo_movimineto_lateral = (columna_destino > columna_origen);

	bool torre_correcta = false;
	//Si no es un movimiento veritcal o lateral significa que esta inteando mover de una manera no permitida.
	if (!es_movimiento_lateral && !es_movimiento_vertical)
	{
		cout << "No puedes mover la torre en diagonal" << endl;
		return false;
	}
	//Verificamos por turnos
	if (es_turno_blancas)
	{
		if (es_movimiento_vertical)
		{
			//arriba
			if (tipo_movimiento_vertical)
			{
				torre_correcta = verifica_movimiento_vertical_B(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

				//Sirve para saber si la torre se ha movido previaminete y que torre.
				if (torre_correcta && fila_origen == FILA_TORRE_IZQ_B && columna_origen == COLUM_TORRE_IZQ_B)
				{
					torre_izquierda_movida_B = true;
				}
				if (torre_correcta && fila_origen == FILA_TORRE_DER_B && columna_origen == COLUM_TORRE_DER_B)
				{
					torre_derecha_movida_B = true;
				}
			}
			else //Abajo 
			{
				//No verifica la torre blanca porque no puede como primer movimineto moverse hacia abajo
				torre_correcta = verifica_movimiento_vertical_B_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
		}
		//Lateral
		else
		{
			if (tipo_movimineto_lateral)
			{
				torre_correcta = verifica_movimiento_Lateral_B(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

				if (torre_correcta && fila_origen == FILA_TORRE_IZQ_B && columna_origen == COLUM_TORRE_IZQ_B)
				{
					torre_izquierda_movida_B = true;
				}
				if (torre_correcta && fila_origen == FILA_TORRE_DER_B && columna_origen == COLUM_TORRE_DER_B)
				{
					torre_derecha_movida_B = true;
				}
			}
			//Izquierda
			else
			{
				torre_correcta = verifica_movimiento_Lateral_B_izquierda(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

				if (torre_correcta && fila_origen == FILA_TORRE_IZQ_B && columna_origen == COLUM_TORRE_IZQ_B)
				{
					torre_izquierda_movida_B = true;
				}
				if (torre_correcta && fila_origen == FILA_TORRE_DER_B && columna_origen == COLUM_TORRE_DER_B)
				{
					torre_derecha_movida_B = true;
				}
			}
		}

	}
	//Negras
	else
	{
		if (es_movimiento_vertical)
		{
			if (tipo_movimiento_vertical)
			{
				torre_correcta = verifica_movimiento_vertical_N(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

			}
			else
			{
				torre_correcta = verifica_movimiento_vertical_N_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

				if (torre_correcta && fila_origen == FILA_TORRE_IZQ_N && columna_origen == COLUM_TORRE_IZQ_N)
				{
					torre_izquierda_movida_N = true;
				}
				if (torre_correcta && fila_origen == FILA_TORRE_DER_N && columna_origen == COLUM_TORRE_DER_N)
				{
					torre_derecha_movida_N = true;
				}
			}
		} 
		//Lateral
		else
		{
			if (tipo_movimineto_lateral)
			{
				torre_correcta = verifica_movimiento_Lateral_N(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

				if (torre_correcta && fila_origen == FILA_TORRE_IZQ_N && columna_origen == COLUM_TORRE_IZQ_N)
				{
					torre_izquierda_movida_N = true;
				}
				if (torre_correcta && fila_origen == FILA_TORRE_DER_N && columna_origen == COLUM_TORRE_DER_N)
				{
					torre_derecha_movida_N = true;
				}
			}
			else
			{
				torre_correcta = verifica_movimiento_Lateral_N_izquierda(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

				if (torre_correcta && fila_origen == FILA_TORRE_IZQ_N && columna_origen == COLUM_TORRE_IZQ_N)
				{
					torre_izquierda_movida_N = true;
				}
				if (torre_correcta && fila_origen == FILA_TORRE_DER_N && columna_origen == COLUM_TORRE_DER_N)
				{
					torre_derecha_movida_N = true;
				}
			}
		}
	}
	// Si torre es correcta retorna true para mover la torre.
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
	bool caballo_correcto = false;

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
			caballo_correcto = verificar_horse_B(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

		}
		else
		{
			caballo_correcto = verificar_horse_N(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
		}
	}
	//Verifica que el caballo sea correcto.
	if (!caballo_correcto)
	{
		return false;
	}
	else
	{
		return true;
	}



}

bool logica_alfil(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	//Mira si el movimiento es hacia arriba la izquierda y verifica si es en diagonal
	bool es_movimiento_iquierda_arriba = (fila_origen - fila_destino == columna_origen - columna_destino && fila_destino < fila_origen && columna_destino < columna_origen);
	//Mira si el movimiento es hacia arriba la derecha y verifica si es en diagonal
	bool es_movimiento_derecha_arriba = (fila_origen - fila_destino == columna_destino - columna_origen && fila_destino < fila_origen && columna_destino > columna_origen);
	//Mira si el movimiento es hacia abajo la izquierda y verifica si es en diagonal
	bool es_movimiento_iquierda_abajo = (fila_destino - fila_origen == columna_origen - columna_destino && fila_destino > fila_origen && columna_destino < columna_origen);
	//Mira si el movimiento es hacia abajo la derecha y verifica si es en diagonal
	bool es_movimiento_derecha_abajo = (fila_destino - fila_origen == columna_destino - columna_origen && fila_destino > fila_origen && columna_destino > columna_origen);

	bool alfil_correcto = false;

	//Si no esta bien el movimiento dara error y retorna false.
	if (!es_movimiento_iquierda_arriba && !es_movimiento_derecha_arriba && !es_movimiento_iquierda_abajo && !es_movimiento_derecha_abajo)
	{
		cout << "El alfil no puede hacer este movimiento." << endl;
		return false;
	}
	else
	{
		//Verificamientos de los posibles movimientos en las direciones.
		if (es_movimiento_derecha_abajo)
		{
			alfil_correcto = verifica_derecha_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
		}
		if (es_movimiento_iquierda_arriba)
		{
			alfil_correcto = verifica_iquierda_arriba(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);

		}
		if (es_movimiento_derecha_arriba)
		{
			alfil_correcto = verifica_derecha_arriba(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);

		}
		if (es_movimiento_iquierda_abajo)
		{
			alfil_correcto = verifica_iquierda_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
		}
	}

	if (!alfil_correcto)
	{
		return false;
	}
	else
	{
		return true;
	}

}


bool logica_reina(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	bool es_turno_blancas = (turno == "blancas");
	bool reina_correcto = false;

	//Cogemos la logica de alfil y torre y las combinamos para hacer la reina.

	//Movimientos diagonales
	bool es_movimiento_iquierda_arriba = (fila_origen - fila_destino == columna_origen - columna_destino && fila_destino < fila_origen && columna_destino < columna_origen);
	bool es_movimiento_derecha_arriba = (fila_origen - fila_destino == columna_destino - columna_origen && fila_destino < fila_origen && columna_destino > columna_origen);
	bool es_movimiento_iquierda_abajo = (fila_destino - fila_origen == columna_origen - columna_destino && fila_destino > fila_origen && columna_destino < columna_origen);
	bool es_movimiento_derecha_abajo = (fila_destino - fila_origen == columna_destino - columna_origen && fila_destino > fila_origen && columna_destino > columna_origen);

	//Movimientos rectos
	bool es_movimiento_vertical = (fila_origen != fila_destino && columna_origen == columna_destino);
	bool es_movimiento_lateral = (fila_origen == fila_destino && columna_origen != columna_destino);
	//Tipo del movimiento rectos
	bool tipo_movimiento_vertical = (fila_destino < fila_origen && columna_origen == columna_destino); 
	bool tipo_movimineto_lateral = (columna_destino > columna_origen && fila_origen == fila_destino);
	 
	//Si no es ningun movimiento significa que esta mal.
	if (!es_movimiento_iquierda_arriba && !es_movimiento_derecha_arriba && !es_movimiento_iquierda_abajo && !es_movimiento_derecha_abajo && !es_movimiento_lateral && !es_movimiento_vertical)
	{
		cout << "La reina no puede hacer este movimiento." << endl;
		return false;
	}


	//Verificamientos de los posibles movimientos en las direciones.
	if (es_movimiento_derecha_abajo)
	{
		reina_correcto = verifica_derecha_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
	}
	if (es_movimiento_iquierda_arriba)
	{
		reina_correcto = verifica_iquierda_arriba(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);

	}
	if (es_movimiento_derecha_arriba)
	{
		reina_correcto = verifica_derecha_arriba(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);

	}
	if (es_movimiento_iquierda_abajo)
	{
		reina_correcto = verifica_iquierda_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
	}


	if (es_turno_blancas)
	{
		if (es_movimiento_vertical)
		{
			//arriba
			if (tipo_movimiento_vertical)
			{
				reina_correcto = verifica_movimiento_vertical_B(fila_origen, columna_origen, fila_destino, columna_destino, mapa);

			}
			else //Abajo 
			{
				reina_correcto = verifica_movimiento_vertical_B_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
		}
		//Lateral
		if (es_movimiento_lateral)
		{
			if (tipo_movimineto_lateral)
			{
				reina_correcto = verifica_movimiento_Lateral_B(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
			//Izquierda
			else
			{
				reina_correcto = verifica_movimiento_Lateral_B_izquierda(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
		}

	}
	//Negras
	else
	{
		if (es_movimiento_vertical)
		{
			if (tipo_movimiento_vertical)
			{
				reina_correcto = verifica_movimiento_vertical_N(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
			else
			{
				reina_correcto = verifica_movimiento_vertical_N_abajo(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
		}
		if (es_movimiento_lateral)
		{
			if (tipo_movimineto_lateral)
			{
				reina_correcto = verifica_movimiento_Lateral_N(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
			else
			{
				reina_correcto = verifica_movimiento_Lateral_N_izquierda(fila_origen, columna_origen, fila_destino, columna_destino, mapa);
			}
		}
	}


	if (!reina_correcto)
	{
		return false;
	}
	else
	{
		return true;
	}

}

bool enroque(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno, bool es_enroque_derecha) {

	bool turno_blancas = (turno == "blancas");
	bool resultado = false;

	//Si no es derecha sera izquierda
	bool verificacion_enroque_derecha = (es_enroque_derecha);

	//Creamos una variable la cual almazenara la ficha encontrada en el mapa.
	short fila_origen_pieza, columna_origen_pieza;


	if (turno_blancas)
	{
		//Cambiamos el turno para la verificacion de si blancas quiere hacer enroque verifique las fichas negras
		string turno_cambiado_verificacion = cambiar_turno(turno);

		if (verificacion_enroque_derecha)
		{
			//Por cada posicion de la columna que haya entre el enroque verificara si alguna pieza puede acceder a esa posicion
			for (short columna = columna_origen; columna <= columna_destino; columna++)
			{
				//Sacamos el mapa y por cada pieza negra almacenaremos la posicion y la pasaremos por la logica.
				for (int i = 0; i < NUM_FILAS; i++) {
					for (int j = 0; j < NUM_COLUMNAS; j++) {

						if (mapa[i][j] >= CHAR_EMPIEZA_N && mapa[i][j] <= CHAR_FIN_N) {

							char pieza_oponente = mapa[i][j];
							//guardamos la posicion extraida para pasarla a la verificacion.
							fila_origen_pieza = i;
							columna_origen_pieza = j;

							switch (pieza_oponente)
							{

							case 'p':
								//Verificamos si puede llegar a alguna posicion del enroque
								resultado = logica_peon(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 't':
								resultado = logica_torre(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'h':
								resultado = logica_horse(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'b':
								resultado = logica_alfil(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'q':
								resultado = logica_reina(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'k':
								resultado = logica_rey(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							}

						}

					}
				}
			}
		}
		//Enroque hacia la izquierda
		else
		{
			for (short columna = columna_destino; columna <= columna_origen; columna++)
			{
				for (int i = 0; i < NUM_FILAS; i++) {
					for (int j = 0; j < NUM_COLUMNAS; j++) {

						if (mapa[i][j] >= CHAR_EMPIEZA_N && mapa[i][j] <= CHAR_FIN_N) {

							char pieza_oponente = mapa[i][j];

							fila_origen_pieza = i;
							columna_origen_pieza = j;

							switch (pieza_oponente)
							{

							case 'p':
								//Verificamos si puede llegar a alguna posicion del enroque
								resultado = logica_peon(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 't':
								resultado = logica_torre(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'h':
								resultado = logica_horse(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'b':
								resultado = logica_alfil(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'q':
								resultado = logica_reina(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'k':
								resultado = logica_rey(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							}

						}

					}
				}
			}
		}

	}
	//Turno Negras
	else
	{
		string turno_cambiado_verificacion = cambiar_turno(turno);

		if (verificacion_enroque_derecha)
		{
			for (short columna = columna_origen; columna <= columna_destino; columna++)
			{
				for (int i = 0; i < NUM_FILAS; i++) {
					for (int j = 0; j < NUM_COLUMNAS; j++) {

						if (mapa[i][j] >= CHAR_EMPIEZA_N && mapa[i][j] <= CHAR_FIN_N) {

							char pieza_oponente = mapa[i][j];

							fila_origen_pieza = i;
							columna_origen_pieza = j;

							switch (pieza_oponente)
							{

							case 'P':
								//Verificamos si puede llegar a alguna posicion del enroque
								resultado = logica_peon(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'T':
								resultado = logica_torre(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'H':
								resultado = logica_horse(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'B':
								resultado = logica_alfil(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'Q':
								resultado = logica_reina(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'K':
								resultado = logica_rey(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							}

						}

					}
				}
			}
		}
		else
		{
			for (short columna = columna_destino; columna <= columna_origen; columna++)
			{
				for (int i = 0; i < NUM_FILAS; i++) {
					for (int j = 0; j < NUM_COLUMNAS; j++) {

						if (mapa[i][j] >= CHAR_EMPIEZA_N && mapa[i][j] <= CHAR_FIN_N) {

							char pieza_oponente = mapa[i][j];

							fila_origen_pieza = i;
							columna_origen_pieza = j;

							switch (pieza_oponente)
							{

							case 'p':
								//Verificamos si puede llegar a alguna posicion del enroque
								resultado = logica_peon(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 't':
								resultado = logica_torre(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'h':
								resultado = logica_horse(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'b':
								resultado = logica_alfil(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'q':
								resultado = logica_reina(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							case 'k':
								resultado = logica_rey(fila_origen_pieza, columna_origen_pieza, fila_destino, columna, mapa, turno_cambiado_verificacion);
								break;
							}

						}

					}
				}
			}
		}
	}

	//Si puede llegar retornaremos false al enroque
	if (resultado)
	{
		return false;
	}
	else {
		return true;
	}
}

bool logica_rey(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno) {

	bool turno_blancas = (turno == "blancas");
	bool verifica_enroque = false;


	//Creamos unas constantes las cuales marcan la posiciones donde quedan la torre cuando esta enrocada.
	const short fila_torre_izquierda_enroque_B = 8;
	const short columna_torre_izquierda_enroque_B = 4;

	const short fila_torre_derecha_enroque_B = 8;
	const short columna_torre_derecha_enroque_B = 6;


	const short fila_torre_izquierda_enroque_N = 1;
	const short columna_torre_izquierda_enroque_N = 4;

	const short fila_torre_derecha_enroque_N = 1;
	const short columna_torre_derecha_enroque_N = 6;

	//Verificamos si el tipo de movimiento insertado
	bool movimiento_vertical = ((fila_origen - fila_destino == 1 || fila_destino - fila_origen == 1) && columna_origen == columna_destino);
	bool movimiento_lateral = ((columna_origen - columna_destino == 1 || columna_destino - columna_origen == 1) && fila_origen == fila_destino);
	bool movimiento_diagonal = ((fila_origen - fila_destino == 1 || fila_destino - fila_origen == 1) && (columna_origen - columna_destino == 1 || columna_destino - columna_origen == 1));

	//Verificamos que tipo de enroque quiere el usuario.
	bool es_enroque_derecha = (columna_destino - columna_origen == 2 && fila_origen == fila_destino);
	bool es_enroque_izquierda = (columna_origen - columna_destino == 2 && fila_origen == fila_destino);

	//si no es ningun movimiento dara error.
	if (!movimiento_vertical && !movimiento_lateral && !movimiento_diagonal && !es_enroque_derecha && !es_enroque_izquierda)
	{
		return false;
	}

	if (turno_blancas)
	{
		if (movimiento_vertical)
		{	
			//Verificara si la posicion del rey no hay nada
			if (mapa[fila_destino][columna_destino] == SIN_NADA)
			{
				//Si es asi pondra el booleando de rey movido como true.
				rey_movido_enroque_B = true;
				return true;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
			{
				//Si intenta ponserse en una pieza de su mismo equipo no podra.
				cout << "Estas pasando por encima de una pieza propia" << endl;
				return false;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && mapa[fila_destino][columna_destino] <= CHAR_FIN_N)
			{
				//En caso que mate.
				rey_movido_enroque_B = true;
				cout << "Rey Mata" << endl;
				return true;
			}
		}
		//Lo mismo pero para Lateral
		if (movimiento_lateral)
		{
			if (mapa[fila_destino][columna_destino] == SIN_NADA)
			{
				rey_movido_enroque_B = true;
				return true;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
			{
				cout << "Estas pasando por encima de una pieza propia" << endl;
				return false;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && mapa[fila_destino][columna_destino] <= CHAR_FIN_N)
			{
				rey_movido_enroque_B = true;
				cout << "Rey Mata" << endl;
				return true;
			}
		}
		//Lo mismo pero para diagonal
		if (movimiento_diagonal)
		{
			if (mapa[fila_destino][columna_destino] == SIN_NADA)
			{
				rey_movido_enroque_B = true;
				return true;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
			{
				cout << "Estas pasando por encima de una pieza propia" << endl;
				return false;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && mapa[fila_destino][columna_destino] <= CHAR_FIN_N)
			{
				rey_movido_enroque_B = true;
				cout << "Rey Mata" << endl;
				return true;
			}
		}
		//En caso que sea enroque derecha:
		if (es_enroque_derecha) {
			
			//Verifica si alguna pieza se ha movido.
			if (rey_movido_enroque_B || torre_derecha_movida_B)
			{
				cout << " No puedes hacer enroque ficha movida previamente" << endl;
				return false;
			}
			//Si no se ha movido nada, verificara que no haya piezas entre medias.
			if (mapa[fila_destino][columna_destino] != SIN_NADA && mapa[fila_destino][columna_destino - 1] != SIN_NADA)
			{
				cout << " Estas intentando enrrocar con piezas por el medio" << endl;
				return false;
			}
			//Si no hay ningun error por parte del usuario verificara si el enroque es posible.
			verifica_enroque = enroque(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno, es_enroque_derecha);

			//Si enroque es posible hara el cambio de fichas.
			if (verifica_enroque)
			{
				mapa[fila_torre_derecha_enroque_B][columna_torre_derecha_enroque_B] = TORRE_BLANCA;
				mapa[FILA_TORRE_DER_B][COLUM_TORRE_DER_B] = SIN_NADA;
				return true;
			}
			//Si no dira que no es posible.
			else
			{
				return false;
			}

		}
		if (es_enroque_izquierda) {

			if (rey_movido_enroque_B || torre_izquierda_movida_B)
			{
				cout << " No puedes hacer enroque ficha movida previamente" << endl;
				return false;
			}
			//En este caso al ser un enroque de largo verifica las tres casillas donde se moveran el enorque.
			if (mapa[fila_destino][columna_destino] != SIN_NADA && mapa[fila_destino][columna_origen - 1] != SIN_NADA && mapa[fila_destino][columna_destino + 1] != SIN_NADA)
			{
				cout << " Estas intentando enrrocar con piezas por el medio" << endl;
				return false;
			}

			verifica_enroque = enroque(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno, es_enroque_derecha);


			if (verifica_enroque)
			{
				mapa[fila_torre_izquierda_enroque_B][columna_torre_izquierda_enroque_B] = TORRE_BLANCA;
				mapa[FILA_TORRE_IZQ_B][COLUM_TORRE_IZQ_B] = SIN_NADA;
				return true;
			}
			else
			{
				return false;
			}
		}

	}
	//Lo mismo para las Negras
	else
	{
		if (movimiento_vertical)
		{
			if (mapa[fila_destino][columna_destino] == SIN_NADA)
			{
				rey_movido_enroque_B = true;
				return true;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && mapa[fila_destino][columna_destino] <= CHAR_FIN_N)
			{
				cout << "Estas pasando por encima de una pieza propia" << endl;
				return false;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
			{
				rey_movido_enroque_B = true;
				cout << "Rey Mata" << endl;
				return true;
			}
		}
		if (movimiento_lateral)
		{
			if (mapa[fila_destino][columna_destino] == SIN_NADA)
			{
				rey_movido_enroque_B = true;
				return true;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && mapa[fila_destino][columna_destino] <= CHAR_FIN_N)
			{
				cout << "Estas pasando por encima de una pieza propia" << endl;
				return false;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
			{
				rey_movido_enroque_B = true;
				cout << "Rey Mata" << endl;
				return true;
			}
		}
		if (movimiento_diagonal)
		{
			if (mapa[fila_destino][columna_destino] == SIN_NADA)
			{
				rey_movido_enroque_B = true;
				return true;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_N && mapa[fila_destino][columna_destino] <= CHAR_FIN_N)
			{
				cout << "Estas pasando por encima de una pieza propia" << endl;
				return false;
			}
			if (mapa[fila_destino][columna_destino] >= CHAR_EMPIEZA_B && mapa[fila_destino][columna_destino] <= CHAR_FIN_B)
			{
				rey_movido_enroque_B = true;
				cout << "Rey Mata" << endl;
				return true;
			}
		}

		if (es_enroque_derecha) {

			if (rey_movido_enroque_N || torre_derecha_movida_N)
			{
				cout << " No puedes hacer enroque ficha movida previamente" << endl;
				return false;
			}

			if (mapa[fila_destino][columna_destino] != SIN_NADA && mapa[fila_destino][columna_destino - 1] != SIN_NADA)
			{
				cout << " Estas intentando enrrocar con piezas por el medio" << endl;
				return false;
			}

			verifica_enroque = enroque(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno, es_enroque_derecha);

			if (verifica_enroque)
			{
				mapa[fila_torre_derecha_enroque_B][columna_torre_derecha_enroque_B] = TORRE_NEGRA;
				mapa[FILA_TORRE_DER_N][COLUM_TORRE_DER_N] = SIN_NADA;
				return true;
			}
			else
			{
				return false;
			}

		}
		if (es_enroque_izquierda) {

			if (rey_movido_enroque_N || torre_izquierda_movida_N)
			{
				cout << " No puedes hacer enroque ficha movida previamente" << endl;
				return false;
			}

			if (mapa[fila_destino][columna_destino] != SIN_NADA && mapa[fila_destino][columna_origen - 1] != SIN_NADA && mapa[fila_destino][columna_destino + 1] != SIN_NADA)
			{
				cout << " Estas intentando enrrocar con piezas por el medio" << endl;
				return false;
			}

			verifica_enroque = enroque(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno, es_enroque_derecha);


			if (verifica_enroque)
			{
				mapa[fila_torre_izquierda_enroque_B][columna_torre_izquierda_enroque_B] = TORRE_NEGRA;
				mapa[FILA_TORRE_IZQ_N][COLUM_TORRE_IZQ_N] = SIN_NADA;
				return true;
			}
			else
			{
				return false;
			}
		}
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
	//Verificamos que no ponga una posici n donde no hay ficha
	if (mapa[fila_origen][columna_origen] == SIN_NADA)
	{
		system("cls");
		cout << "Posicion insertada no hay nada" << endl;
		return false;
	}
	//Verificamos que si esta el turno de las blancas (Mayusculas) no intente mover una ficha del jugador de negras (minusculas)
	if (turno == "blancas" && mapa[fila_origen][columna_origen] >= CHAR_EMPIEZA_N && mapa[fila_origen][columna_origen] <= CHAR_FIN_N)
	{
		system("cls");
		cout << "Estas intentando cambiar una ficha que no te pertenece" << endl;
		return false;
	}
	//Verificamos lo mismo con el jugador de las negras.
	if (turno == "negras" && mapa[fila_origen][columna_origen] >= CHAR_EMPIEZA_B && mapa[fila_origen][columna_origen] <= CHAR_FIN_B)
	{
		system("cls");
		cout << "Estas intentando cambiar una ficha que no te pertenece" << endl;
		return false;
	}

	//Si ningun if es afectado significa que el movimiento en el tablero es valido (sin logica)
	else
	{
		//Aqui con el switch verificaremos todos los caracteres posibles y enviaremos a la funcion de logica de la misma.
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
		case 'Q':
		case 'q':
			resultado = logica_reina(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
			break;
		case 'K':
		case 'k':
			resultado = logica_rey(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno);
			break;
		}

		//Si el resultado es valido retornaremos true.
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


	//Verifica si el peon correcto se combierte a dama o no.
	if (peon_a_reina(fila_origen, columna_origen, fila_destino, columna_destino, mapa, turno))
	{
		//En caso que sea un peon a reina cambiara el peon por reina.
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
	//Si no es reina movera la ficha normal.
	else {
		char ficha_a_mover = mapa[fila_origen][columna_origen];
		mapa[fila_origen][columna_origen] = SIN_NADA;
		mapa[fila_destino][columna_destino] = ficha_a_mover;
	}

}

string cambiar_turno(string turno) {
	
	//Funcion para cambiar el turno
	if (turno == "blancas")
	{
		return "negras";
	}
	else
	{
		return "blancas";
	}
}






