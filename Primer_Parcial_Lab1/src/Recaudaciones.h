

#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

#define ARBA 1
#define IIBB 2
#define GANANCIAS 3
#define CANT 50
#define CANT_TIPO 3
#define CANT_ESTADO 2
#define REFINANCIADO 1
#define SALDADO 2
#include "Contribuyente.h"


typedef struct {
	int idContribuyente;
	int mes;
	int idTipo;
	int idRecaudacion;
	int idEstado;
	float importe;
	int isEmpty;
} eRecaudacion;

typedef struct {
	int idTipo;
	char descripcion[MAX_CHARS_CADENAS];
} eTipo;

typedef struct {
	int idEstado;
	char detalleEstado[MAX_CHARS_CADENAS];
} eEstado;

/*
 * @brief recibe una estructura y la inicializa en cero si el array es numerico y vacio/espacio si un caracter o candena de caracteres
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de exito
 */
int eRecaudacion_inicializar (eRecaudacion arrayRecaudacion[],int tam);
/*
 * @brief recibe una estructura y la inicializa en cero si el array es numerico y vacio/espacio si un caracter o candena de caracteres
 * @param arrayTipo estructura que incluye el tipo de recaudacion
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de exito
 */
int eTipo_inicializar (eTipo arrayTipo[],int cant);
/*
 * @brief recibe una estructura y la inicializa en cero si el array es numerico y vacio/espacio si un caracter o candena de caracteres
 * @param arrayEstado estructura que incluye el estado de la recaudacion
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de exito
 */
int eEstado_inicializar (eEstado arrayEstado[],int cant);
/*
 * @brief Obtiene el tipo de recaudacion ingresada por el usuario
 * @param arrayTipo estructura que incluye el tipo de racudacion
 * @param cant cantidad de elementos
 * @param tipo id del tipo ingresado por el usuario
 * @return retorna cero en caso de exito
 */
int eRecaudacion_obtenerNombre (eTipo arrayTipo[],int cant,int tipo,char detalle[20]);
/*
 * @brief recorre la estrucutra en busca de un campo libre
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @return retorna cero en caso de que el campo esta vacio
 */
int eRecaudacion_buscarLibre (eRecaudacion arrayRecaudacion[],int tam);
/*
 * @brief recorre la estrucutra, busca que el id ingresado coincida con el que se busca
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @para id que se ingresa para comprar
 * @return retorna cero en caso de coincidencia
 */
int eRecaudacion_buscarId (eRecaudacion arrayRecaudacion[],int tam,int id);
/*
 * @brief pide al usuario el ingreso del id de la recaudacion y compara si coincide con un id existente,
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @return auxiliar donde se cargaron los datos ingresados por el usuario
 */
eRecaudacion eRecaudacion_cargar (eContribuyente arrayContribuyente[], int cant);
/*
 * @brief carga en la estructura arrayRecaudacion los datos ingresados por el usuario
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param pIdContador puntero donde se dejara el id de la recaudacion
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @return retorna cero en caso de que se cargaran todos los datos
 */
int eRecaudacion_alta (eRecaudacion arrayRecaudacion[], int tam, int *pIdContador, eContribuyente arrayContribuyente[], int cant);
/*
 * @brief modifica la estructura arrayRecaudacion, con los nuevos datos ingresados por el usuario
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tamanio cantidad de elementos
 * @return retorna cero en caso de que se modificaran los datos
 */
int eRecaudacion_modificar (eRecaudacion arrayRecaudacion[], int tamanio);
/*
 * @brief muestra un contribuyente y el tipo de recaudacion
 * @param arrayRecaudacion estructura que incluye las recudaciones
 * @param tamanio cantidad de elementos
 * @param arrayTipo estructura que incluye el tipo de racudacion
 * @param cant cantidad de elementos
 */
void eRecaudacion_mostrarUno (eRecaudacion arrayRecaudacion[],int tamanio, eTipo arrayTipo[], int cant);
/*
 * @brief muestra todos los contribuyentes ingresados por el usuario y el tipo de recaudacion
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @param arrayTipo estructura que incluye el tipo de racudacion
 * @param cant cantidad de elementos
 * @return retorna cero en caso de que hayan empleados a mostrar
 */
int eRecaudacion_mostrarTodos (eRecaudacion arrayRecaudacion[],int tamanio, eTipo arrayTipo[], int cant);
/*
 * @brief compara el id ingresado con los id existentes
 * @param arrayRecaudacion estructura que incluye las recudaciones
 * @param tam cantidad de elementos
 * @param id que se va a comprar
 * @return retorna cero en caso de que la comparacion sea exitosa
 */
int eRecaudacion_buscarIdContribuyente (eRecaudacion arrayRecaudacion[],int tam,int id);
/*
 *@brief Muestra los datos del contribuyente que en caso que el id de contribuyente coincida con la reaudacion
 *@param arrayRecaudacion estructura que incluye las recaudaciones
 *@param tam cantidad de elementos
 *@param arrayContribuyente estructura que incluye los contribuyentes
 *@param cant cantidad de elementos
 *@param *auxId puntero que recibe el id a comparar
 *@return retorna cero si conicide el id y se muestra en pantalla los datos del contribuyente
 */
int eRecaudaciones_mostrarContribuyentes (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, int* auxId);
/*
 * @brief Pide al usuario el ingreso del idRecaudacion la cual se va a cambiar el estado, y obtiene el id a modificar
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @param arrayTipo estructura que incluye los tipos de recaudaciones
 * @param cantTipo cantidad de elementos
 * @param *indexId puntero que recibe el id
 * @return retorna cero en caso de que el id ingresado por el usuario sea valido
 */
int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo, int* indexId);
/*
 * @brief Pregunta al usuario si quiere cambiar el estado de la recaudacion, si ingresa 's' modifica el estado
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @param arrayTipo estructura que incluye los tipos de recaudaciones
 * @param cantTipo cantidad de elementos
 * @return retorna cero en caso de que el estado se cambio a refinanciar
 */
int eRecaudacion_estadoRefinanciar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
/*
 * @brief Pregunta al usuario si quiere cambiar el estado de la recaudacion, si ingresa 's' modifica el estado
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @param arrayTipo estructura que incluye los tipos de recaudaciones
 * @param cantTipo cantidad de elementos
 * @return retorna cero en caso de que el estado se cambio a saldado
 */
int eRecaudacion_estadoSaldado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo);
/*
 * @brief Obtiene el estado de recaudacion ingresada por el usuario
 * @param arrayTipo estructura que incluye el tipo de racudacion
 * @param cant cantidad de elementos
 * @param estado id del estado ingresado por el usuario
 * @param detalle cadena que guarda el estado
 * @return retorna cero en caso de exito
 */
int eRecaudacion_obtenerNombreEstado (eEstado arrayEstado[],int cant,int estado,char detalle[20]);


int eRecaudacion_baja (eRecaudacion arrayRecaudacion[], int tam, int*pIdContribuyente);
/*
 * @brief Recorre el array isEmpty en busca de los que esten ocupados
 * @param arrayContribuyentes estructura que incluye los contribuyentes
 * @param tam cantidad de elementos
 * @return retona cero si esta ocupado y 1 si esta vacio
 */
int eRecaudacion_isEmpty (eRecaudacion arrayRecaudacion[], int tam);

#endif /* RECAUDACIONES_H_ */
