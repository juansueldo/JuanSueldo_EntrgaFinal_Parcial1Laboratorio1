/*
 ============================================================================
 Name        : Primer_Parcial_Lab1.c
 Author      : Juan Sueldo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Informes.h"
int main()
{
	system("cls");
    setbuf(stdout, NULL);


	eContribuyente arrayContribuyentes[MAX];
	eRecaudacion arrayRecaudadores [CANT];
	eTipo arrayTipo[CANT_TIPO];
	eEstado arrayEstado[CANT_ESTADO];

    eContribuyente_inicializar(arrayContribuyentes, MAX);
    eRecaudacion_inicializar(arrayRecaudadores, CANT);
    eTipo_inicializar (arrayTipo, CANT_TIPO);
    eEstado_inicializar(arrayEstado, CANT_ESTADO);

    strcpy(arrayTipo[0].descripcion,"ARBA");
   	arrayTipo[0].idTipo = ARBA;

   	strcpy(arrayTipo[1].descripcion,"IIBB");
   	arrayTipo[1].idTipo = IIBB;

   	strcpy(arrayTipo[2].descripcion,"GANANCIAS");
   	arrayTipo[2].idTipo = GANANCIAS;

   	strcpy(arrayEstado[0].detalleEstado,"REFINANCIADO");
   	arrayEstado[0].idEstado = REFINANCIADO;

   	strcpy(arrayEstado[1].detalleEstado,"SALDADO");
   	arrayEstado[1].idEstado = SALDADO;

   	menu (arrayContribuyentes, MAX, arrayRecaudadores, CANT, arrayTipo, CANT_TIPO , arrayEstado, CANT_ESTADO);

   	return EXIT_SUCCESS;
}





