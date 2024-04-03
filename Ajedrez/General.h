#pragma once

#include <iostream>
#include <windows.h>// Para hacer un Sleep para poder dejar un tiempo y borrar la terminal. (Sacado de mi proyecto hundir la flota).


#include "mapa.h"
#include "movimientos_peon.h"
#include "logica_torre.h"
#include "logica_alfil.h"
#include "game_logic.h"
#include "juego.h"



#define SIN_NADA '*'
#define ESPACIO ' '

#define NUM_FILAS 9
#define NUM_COLUMNAS 9
#define REINA_BLANCA 'Q'
#define REINA_NEGRA 'q'

#define CHAR_EMPIEZA_B 'A'
#define CHAR_FIN_B 'Z'

#define CHAR_EMPIEZA_N 'a'
#define CHAR_FIN_N 'z'


using namespace std;
