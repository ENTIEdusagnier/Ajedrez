#pragma once


#define NUM_FILAS 9
#define NUM_COLUMNAS 9

#define REINA_BLANCA 'Q'
#define REINA_NEGRA 'q'

#define CHAR_EMPIEZA_B 'A'
#define CHAR_FIN_B 'Z'

#define CHAR_EMPIEZA_N 'a'
#define CHAR_FIN_N 'z'

#define SIN_NADA '*'
#define ESPACIO ' '

#define REY_BLANCO 'K'
#define REY_NEGRO 'k'

#define TORRE_BLANCA 'T'
#define TORRE_NEGRA 't'


#define FILA_TORRE_IZQ_B 8
#define COLUM_TORRE_IZQ_B 1

#define FILA_TORRE_DER_B 8
#define COLUM_TORRE_DER_B 8

#define FILA_TORRE_IZQ_N 1
#define COLUM_TORRE_IZQ_N 1

#define FILA_TORRE_DER_N 1
#define COLUM_TORRE_DER_N 8

#define BLANCAS "blancas"
#define NEGRAS "negras"

#include <windows.h>// Para hacer un Sleep para poder dejar un tiempo y borrar la terminal. (Sacado de mi proyecto hundir la flota).
#include <iostream>

#include "mapa.h"
#include "movimientos_peon.h"
#include "logica_torre.h"
#include "logica_alfil.h"
#include "game_logic.h"
#include "juego.h"
#include "logica_horse.h"


using namespace std;
