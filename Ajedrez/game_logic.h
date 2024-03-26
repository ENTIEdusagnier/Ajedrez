#pragma once

using namespace std;

bool moviminento_correcto(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS], string turno);

void mover_ficha(short fila_origen, short columna_origen, short fila_destino, short columna_destino, char mapa[NUM_FILAS][NUM_COLUMNAS]);

void posiciones_user(char mapa[NUM_FILAS][NUM_COLUMNAS], string turno);

string cambiar_turno(string turno);

bool jaque_mate();
