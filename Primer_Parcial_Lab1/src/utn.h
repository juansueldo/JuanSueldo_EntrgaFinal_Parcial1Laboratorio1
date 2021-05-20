#ifndef UTN_H_
#define UTN_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * @brief solicita un texto al usuario, en caso de error otorga reintentos
 * @param array Array donde se cargara el texto ingresado
 * @param max cantidad maxima de caracteres que puede tener la cadena
 * @param mensaje Es el mesaje a ser mostrado
 * @param mensaje Es el mesaje a ser mostrado en caso de error
 * @param min cantidad minima de caracteres que puede tener la cadena
 * @para intentos cantidad de reintentos en caso de error
 * @return retorna cero en caso de que el texto sea valido
 */
int utn_getString(char array[],int tamanio,char mensaje[],char errorMensaje[],char min,int intentos);
/**
* @brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
* un máximo de ' longitud - 1' caracteres .
* @param pCadena Puntero al espacio de memoria donde se copiara la cadena obtenida
* @ param longitud Define el tamaño de cadena
* @return Retorna cero si se obtiene una cadena y -1 si no
*
*/
int myGets(char* pCadena,int longitud);
/**
* @brief Verifica si la cadena ingresada es numerica
* @param pNum Cadena de caracteres a ser analizada
* @return Retorna cero si la cadena es numerica y -1  si no lo es
*/
int esNumerica(char* pNum);
/**
* @brief Verifica si la cadena ingresada es numerica
* @param pNum Puntero al espacio de memoria donde se dejara el resultado de la funcion
* @return Retorna cero si se obtiene un numero entero y -1 si no
*
*/
int getInt ( int * pNum);
/**
* @brief Verifica si la cadena ingresada es numerica y contiene puntos
* @param pNum Cadena de caracteres a ser analizada
* @return Retorna cero si la cadena es numerica y continen puntos y -1  si no lo es
*/
int esFloat (char pNum[]);
/**
* @brief Verifica si la cadena ingresada es numerica
* @param pFloat Puntero al espacio de memoria donde se dejara el resultado de la funcion
* @return Retorna cero si se obtiene un numero flotante y -1 si no
*
*/
int getNumFloat(float * pFloat);
/**
* @brief Solicita un numero al usuario , luego de verificarlo devuelve el resultado
* @param pNum Puntero al espacio de memoria donde se dejara el resultado de la funcion
* @param mensaje Es el mensaje a ser mostrado
* @param mensajeError Es el mensaje de Error a ser mostrado
* @param minimo Es el numero maximo a ser aceptado
* @param maximo Es el minimo minimo a ser aceptado
* @return Retorna cero si se obtuvo el numero y -1 si no
*/
int utn_getNumero(int* pNum,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/**
* @brief Solicita un numero flotante al usuario , luego de verificarlo devuelve el resultado
* @param pFloat Puntero al espacio de memoria donde se dejara el resultado de la funcion
* @param mensaje Es el mensaje a ser mostrado
* @param mensajeError Es el mensaje de Error a ser mostrado
* @param minimo Es el numero maximo a ser aceptado
* @param maximo Es el minimo minimo a ser aceptado
* @return Retorna cero si se obtuvo el numero y -1 si no
*/
int utn_getFloat(float* pFloat,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
/*
 * @brief Pide al usuario el ingreso de un numero, y analiza si el numero esta dentro del rango
 * @param pOpcion Numero ingresado por el usuario
 * @param mensaje Es el mesaje a ser mostrado
 * @param mensaje Es el mesaje a ser mostrado en caso de error
 * @param min Valor minimo admitido
 * @param max Valor maximo admitido
 * @return Retorna cero en caso de que el valor este dentro del rango
 */
int utn_menu(int *opcion, char *mensaje, char *mensajeError, int min, int max);
/*
 * @brief imprime mensaje en pantalla solicitando una respuesta al usuario
 * @param mensaje Es el mesaje a ser mostrado
 * @param mensaje Es el mesaje a ser mostrado en caso de error
 * @param reintetos
 * @return retorna cero en caso de que la respuesta sea 's' y -1 si la respuesta es 'n'
 */
int utn_getRespuesta (char* mensaje,char*mensajeError, int reintentos);
/*
 * @brief Comprueba si el dato ingresado y lo valida si es un caracter o espacio
 * @param pString puntero que toma el dato ingresado
 * @retorno retorna cero en caso de que el dato sea un caracter o espacio
 */
int utn_getTexto (char *pString);
/*
 * @brief recibe una cadena y convierte todos sus carateres en minuscular y el primer caracter en mayuscula
 * @param name recibe la cadena
 * @param tam cantidad de caracteres de la cadena
 * @return retorna cero
 */
int utn_getMayusMin (char name[], int tam);
/*
 * @brief Recibe un caracter y lo convierte en minuscula
 * @param letra Caracter que se convertira en minuscula
 * @return Retorna cero cuando se convierte el caracter
 */
int utn_getLower(char* letra);
/*
 * @brief solicita el ingreso de una cadena numerica compuesta por dos guiones y 11 caracteres
 * @param cadena recibe el dato ingresado por el usuario
 * @return retorna cero si la cadena es numerica y contiene dos guiones
 */
int utn_EsCuil(char* cadena);
/*
 *@brief solicita al usuario el ingreso de una cadena numerica la cual debe tener guiones en la poscion 2 y 11
 *@param cadena recibe el dato ingresado por el usuario
 *@param mensaje Es el mesaje a ser mostrado
 *@param eMensaje Es el mesaje a ser mostrado en caso de error
 *@param reintentos cantidad de reintentos en caso de error
 *@return retorna cero en caso de que la cadena sea valida
 */
int utn_getCuil(char cadena[],char mensaje[],char eMensaje[],int reintentos);

#endif /* UTN_H_ */
