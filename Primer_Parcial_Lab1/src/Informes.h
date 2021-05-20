
#ifndef INFORMES_H_
#define INFORMES_H_

#include "Recaudaciones.h"

/*
 * @brief Muestra las recaudaciones con el tipo de recaudacion y el estado de la misma
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param arrayTipo estructura que incluye el tipo de recaudacion
 * @param cantTipo cantidad de elementos
 * @param arrayEstado estructura que incluye el estado de la recaudacion
 * @param cantEstado cantidad de elementos
 */
void eRecaudacion_mostrarTipoEstado(eRecaudacion arrayRecaudacion[],int tam, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
/*
 * @brief Muestra los datos del contribuyente con todas las recaudaciones que posee, estado y tipo
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @param cantTipo cantidad de elementos
 * @param arrayEstado estructura que incluye el estado de la recaudacion
 * @param cantEstado cantidad de elementos
 * @return retorna cero si se mostraron los datos
 */
int mostrarTodos(eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
/*
 * @brief Muestra los datos del contribuyente con todas las recaudaciones que posee y el tipo solo si el estado es SALDADO
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param tam cantidad de elementos
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param cant cantidad de elementos
 * @param cantTipo cantidad de elementos
 * @param arrayEstado estructura que incluye el estado de la recaudacion
 * @param cantEstado cantidad de elementos
 * @return retorna cero si se mostraron los datos
 */
int eRecaudacion_mostrarSaldados (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
/*
 * @brief Muestra al usuario los contribuyentes y pide el ingreso del ID del contribuyente a dar de baja, da la baja del contribuyente y sus recaudaciones
 * @param arrayContribuyente estructura que incluye los contribuyentes
 * @param tamanio cantidad de elementos
 * @param arrayRecaudacion estructura que incluye las recaudaciones
 * @param cant cantidad de elementos
 * return retorna cero si se dio la baja
 */
int baja_ContribuyenteRecaudaciones (eContribuyente arrayContribuyentes[], int tamanio, eRecaudacion arrayRecaudacion[], int cant);

/*
 * @brief Muestra el menu y solicita al usuario el ingreso de la accion que desea realizar
 *
 */
void menu (eContribuyente arrayContribuyentes[], int tam,eRecaudacion arrayRecaudadores[], int cant, eTipo arrayTipo [],int cantTipo,eEstado arrayEstado[], int cantEstado );
int eInformes_SaldadoImporte (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
int eInformes_febrero (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);
int eInformes_informeRefinanciar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado);

#endif /* INFORMES_H_ */
