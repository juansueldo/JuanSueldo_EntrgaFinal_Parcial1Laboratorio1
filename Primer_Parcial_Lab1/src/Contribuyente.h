#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

#include "utn.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30

#define MAX 50

typedef struct {
	char nombre [MAX_CHARS_CADENAS];
	char apellido [MAX_CHARS_CADENAS];
	int idContribuyente;
	char cuil [14];
	int isEmpty;
} eContribuyente;

/*
 * @brief recibe una estructura y la inicializa
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de exito
 */
int eContribuyente_inicializar (eContribuyente arrayContribuyentes[],int tam);
/*
 * @brief recorre la estrucutra en busca de un campo libre
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de que el campo esta vacio
 */
int eContribuyente_buscarLibre (eContribuyente arrayContribuyentes[],int tam);
/*
 * @brief recorre la estrucutra, busca que el id ingresado coincida con el que se busca
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @para id que se ingresa para comprar
 * @return retorna cero en caso de coincidencia
 */
int eContribuyente_buscarId (eContribuyente arrayContribuyentes[],int tam,int id);
/*
 * @brief pide al usuario los datos y los carga en el auxiliar
 * @return auxiliar donde se cargaron los datos ingresados por el usuario
 */
eContribuyente eContribuyente_cargar (void);
/*
 * @brief carga en la estructura arrayContribuyentes los datos ingresados por el usuario
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @param pIdContador puntero donde se dejara el id del contribuyente
 * @return retorna cero en caso de que se cargaran todos los datos
 */
int eContribuyente_alta (eContribuyente arrayContribuyentes[], int tam, int *pIdContador);
/*
 * @brief da de baja el cotribuyente solicitado por el usuario
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de que haya dado de baja un contribuyente
 */
int eContribuyente_baja (eContribuyente arrayContribuyentes[], int tamanio);
/*
 * @brief modifica la estructura arrayContribuyentes, con los nuevos datos ingresados por el usuario
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de que se modificaran los datos
 */
int eContribuyente_modificar (eContribuyente arrayContribuyentes[], int tamanio);
/*
 * @brief modifica la estructura arrayContribuyentes, el usuario elige el campo a modificar
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param campoModificar toma el campo que el usario desea modificar
 * @return retorna cero en caso de que se modificaran los datos
 */
eContribuyente eContribuyente_modificarUno (eContribuyente arrayContribuyentes, int campoModificar);
/*
 * @brief muestra todos los contribuyentes ingresados por el usuario
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de que hayan empleados a mostrar
 */
int eContribuyente_mostrarTodos (eContribuyente arrayContribuyentes[],int tamanio);
/*
 * @brief muestra un contribuyente
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 */
void eContribuyente_mostrarUno (eContribuyente arrayContribuyentes[],int tamanio);
/*
 * @brief recibe un id compara si existe y pregunta si quiere dar de baja al contribuyente que pertence el id
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @param pIdContribuyente puntero que recibe el id
 * @param index puntero recibe la direccion del id a dar de baja
 * @return retorna cero si se dio la baja
 */

int eContribuyente_bajaContribuyente (eContribuyente arrayContribuyentes[], int tamanio, int*pIdContribuyente, int*index);
/*
 * @brief Recorre el array isEmpty en busca de los que esten ocupados
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @return retona cero si esta ocupado y 1 si esta vacio
 */
int eContribuyente_isEmpty (eContribuyente arrayContribuyentes[], int tam);


#endif /* CONTRIBUYENTE_H_ */
