#include "Recaudaciones.h"

int eRecaudacion_inicializar (eRecaudacion arrayRecaudacion[],int tam)
{
	int i;
	int rtn = -1;
	if(arrayRecaudacion != NULL && tam >0)
	{

		for (i = 0; i < tam; i++)
		{
			arrayRecaudacion[i].mes = 0;
			arrayRecaudacion[i].idTipo = 0;
			arrayRecaudacion[i].idRecaudacion = 0;
			arrayRecaudacion[i].idEstado = 0;
			arrayRecaudacion[i].importe = 0;
			arrayRecaudacion[i].isEmpty=1;
		}
		rtn = 0;
	}
	return rtn;
}
int eTipo_inicializar (eTipo arrayTipo[],int cant)
{
	int i;
	int rtn = -1;
	if(arrayTipo != NULL && cant >0)
	{

		for (i = 0; i < cant; i++)
		{
			arrayTipo[i].idTipo = 0;
			strcpy(arrayTipo[i].descripcion," ");
		}
		rtn = 0;
	}
	return rtn;
}
int eEstado_inicializar (eEstado arrayEstado[],int cant)
{
	int i;
	int rtn = -1;
	if(arrayEstado != NULL && cant >0)
	{

		for (i = 0; i < cant; i++)
		{
			arrayEstado[i].idEstado = 0;
			strcpy(arrayEstado[i].detalleEstado," ");
		}
		rtn = 0;
	}
	return rtn;
}
int eRecaudacion_obtenerNombre (eTipo arrayTipo[],int cant,int tipo,char detalle[20])
{
	int rtn = -1;
	int i;
	if(arrayTipo != NULL && cant > 0 && (isdigit(tipo)) == 0  && detalle != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			if(arrayTipo[i].idTipo == tipo)
			{
				if(arrayTipo[i].idTipo== 1)
				{
				strcpy(detalle,"ARBA");
				rtn = 0;
				break;
				}
				if(arrayTipo[i].idTipo== 2)
				{
					strcpy(detalle,"IIBB");
					rtn = 0;
				break;
				}
				if(arrayTipo[i].idTipo== 3)
				{
					strcpy(detalle,"GANANCIAS");
					rtn = 0;
				break;
				}

			}
		}
	}

	return rtn;
}
int eRecaudacion_obtenerEstado (eEstado arrayEstado[],int cant,int tipo,char detalle[20])
{
	int rtn = -1;
	int i;
	if(arrayEstado != NULL && cant > 0 && (isdigit(tipo)) == 0  && detalle != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			if(arrayEstado[i].idEstado == tipo)
			{
				if(arrayEstado[i].idEstado == 1)
				{
				strcpy(detalle,"REFINANCIAR");
				rtn = 0;
				break;
				}
				if(arrayEstado[i].idEstado== 2)
				{
					strcpy(detalle,"SALDADO");
					rtn = 0;
				break;
				}

			}
		}
	}

	return rtn;
}
int eRecaudacion_buscarLibre (eRecaudacion arrayRecaudacion[],int tam)
{
	int ret;
	int i;
	ret = -1;
	if(arrayRecaudacion != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if(arrayRecaudacion[i].isEmpty==1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}
int eRecaudacion_buscarId (eRecaudacion arrayRecaudacion[],int tam,int id)
{
	int rtn = -1;
	int i;

	if (arrayRecaudacion != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (arrayRecaudacion[i].idRecaudacion == id && arrayRecaudacion[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
eRecaudacion eRecaudacion_cargar (eContribuyente arrayContribuyente[], int cant)
{
	eRecaudacion auxiliar;
	if(utn_getNumero(&auxiliar.idContribuyente,"\n\nINGRESE EL ID DEL CONTRIBUYENTE: ","\n\nERROR.INGRESE EL ID DEL CONTRIBUYENTE: ",1000,1050,3) != 0)
	{
		printf("\n ERROR NO SE INGRESO EL ID DEL CONTRIBUYENTE");
	}
	while (eContribuyente_buscarId(arrayContribuyente, cant , auxiliar.idContribuyente) ==-1)
	{
		if(utn_getNumero(&auxiliar.idContribuyente,"\nINGRESE EL ID DEL CONTRIBUYENTE: ","\nERROR.INGRESE EL ID DEL CONTRIBUYENTE: ",1000,1050,3) != 0)
		{
			printf("\n ERROR NO SE INGRESO EL ID DEL CONTRIBUYENTE");
		}
	}
	if(utn_getNumero(&auxiliar.mes,"\nINGRESE EL MES[1 a 12]: ","\nERROR. INGRESE EL MES[1 a 12]: ",1,12,3) != 0)
	{
		printf("\nERROR NO SE INGRESO EL NOMBRE");
	}
	if(utn_getNumero(&auxiliar.idTipo,"\nINGRESE EL TIPO [1] ARBA [2] IIBB [3] GANANCIAS: ","\nERROR.INGRESE EL TIPO [1] ARBA [2] IIBB [3] GANANCIAS:",1,3,3) != 0)
	{
		printf("\n ERROR NO SE INGRESO EL TIPO");
	}
	if(utn_getFloat(&auxiliar.importe,"\nINGRESE EL IMPORTE [DEL 100 AL 9999999]: ","\nERROR. INGRESE EL IMPORTE [DEL 100 AL 9999999]; ",100,999999,3) !=0)
	{
		printf("\nERROR NO SE INGRESO EL IMPORTE");
	}



	return auxiliar;
}
int eRecaudacion_alta (eRecaudacion arrayRecaudacion[], int tam, int *pIdContador, eContribuyente arrayContribuyente[], int cant)
{
	int rtn = -1;
	int i;
	eRecaudacion auxRecaudacion;
	int index = eRecaudacion_buscarLibre (arrayRecaudacion, tam);

	if(arrayRecaudacion != NULL && tam > 0 && pIdContador != NULL && arrayContribuyente != NULL && cant >0)
	{
		for(i = 0; i < cant; i++)
		{
			if(arrayContribuyente[i].isEmpty == 0)
			{
				if (index != -1)
				{
					eContribuyente_mostrarTodos(arrayContribuyente, cant);

					auxRecaudacion = eRecaudacion_cargar(arrayContribuyente,cant);

					auxRecaudacion.isEmpty = 0;
					rtn = 0;
				}
				if(rtn == 0)
				{
					(*pIdContador)++;
					auxRecaudacion.idRecaudacion = *pIdContador;
					arrayRecaudacion[index] = auxRecaudacion;
					break;
				}
			}
		}

}


	return rtn;
}
void eRecaudacion_mostrarUno (eRecaudacion arrayRecaudacion[],int tam, eTipo arrayTipo[], int cant)
{
	char detalle[30];
	eRecaudacion_obtenerNombre (arrayTipo,cant,arrayRecaudacion[tam].idTipo,detalle);
	printf("\n%d   %15d      %15d   %10.2f     %15s\n"
			,arrayRecaudacion[tam].idContribuyente
			,arrayRecaudacion[tam].idRecaudacion
			,arrayRecaudacion[tam].mes
			,arrayRecaudacion[tam].importe
			,detalle);
}
int eRecaudacion_mostrarTodos (eRecaudacion arrayRecaudacion[],int tam, eTipo arrayTipo[], int cant)
{
	int i;
	int rtn = -1;
	if(arrayRecaudacion != NULL && tam > 0 && arrayTipo != NULL && cant > 0)
	{
		printf("\n**********************************************************************\n");
		printf("\n ID CONTRIBUYENTE    ID RECAUDACION        MES      IMPORTE      TIPO       ");
		printf("\n***********************************************************************\n");
		for (i = 0; i < tam; i++)
		{

			if(arrayRecaudacion[i].isEmpty == 0)
			{
				eRecaudacion_mostrarUno(arrayRecaudacion,i,arrayTipo,cant);
			}
		}
		rtn = 0;
	}
	return rtn;
}
int eRecaudacion_buscarIdContribuyente (eRecaudacion arrayRecaudacion[],int tam,int id)
{
	int rtn = -1;
	int i;

	if (arrayRecaudacion != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++) {
			if (arrayRecaudacion[i].idContribuyente == id && arrayRecaudacion[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
int eRecaudaciones_mostrarContribuyentes (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, int* auxId)
{
	int rtn = -1;
	int i;
	int indexIdContribuyente;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && tam > 0 && cant > 0 && auxId != NULL)
	{
		for(i = 0; i < tam; i++)
		{
			if(arrayRecaudacion[i].idRecaudacion == *auxId)
			{
				indexIdContribuyente = eContribuyente_buscarId (arrayContribuyente,cant,arrayRecaudacion[i].idContribuyente);
				printf("\n*************************************************************\n");
				printf("\n ID    NOMBRE           APELLIDO               CUIL       ");
				printf("\n**************************************************************\n");
				eContribuyente_mostrarUno (arrayContribuyente,indexIdContribuyente);
				rtn = 0;
			}
		}

	}
	return rtn;
}
int eRecaudacion_cambiarEstado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo, int* indexId)
{
	int rtn = -1;
	int flag = 0;
	int idRecaudacion;

		if(eRecaudacion_isEmpty(arrayRecaudacion, tam) == 0)
		{
			if (eRecaudacion_mostrarTodos (arrayRecaudacion,tam, arrayTipo, cantTipo) == 0)
			{
				flag = 1;
			}

			if (flag)
			{
				printf("\n*****************************************************************\n");

				utn_getNumero(&idRecaudacion,"INGRESE EL ID DE LA RECAUDACION: ","\nERORR. NO ES UN ID VALIDO",100,150,3);
				while (eRecaudacion_buscarId(arrayRecaudacion, tam, idRecaudacion) == -1)
				{
					utn_getNumero(&idRecaudacion,"\nNO EXISTE ID. REINGRESE EL ID DE LA RECAUDACION: ","\nERORR. NO ES UN ID VALIDO",100,150,3);
				}
				}
				if(eRecaudacion_buscarId(arrayRecaudacion, tam, idRecaudacion) != -1)
				{
					*indexId = eRecaudacion_buscarId(arrayRecaudacion, tam, idRecaudacion);
					eRecaudaciones_mostrarContribuyentes (arrayRecaudacion,tam, arrayContibuyente, cant, &idRecaudacion);
					rtn = 0;
				}
		}

	return rtn;
}
int eRecaudacion_estadoRefinanciar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo)
{
	int rtn = -1;
	int index;
	if(eRecaudacion_cambiarEstado (arrayRecaudacion,tam,arrayContibuyente,cant,arrayTipo, cantTipo,&index)==0)
	{
		if(utn_getRespuesta ("\n\nDESEA CAMBIAR EL ESTADO A REFINANCIAR [S] SI [N]: ","\n\nDESEA CAMBIAR EL ESTADO A REFINANCIAR [S] SI [N]: ", 3)==0)
		{
			arrayRecaudacion[index].idEstado = 1;
			rtn = 0;
		}
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}
int eRecaudacion_estadoSaldado (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContibuyente[], int cant, eTipo arrayTipo[], int cantTipo)
{
	int rtn = -1;
	int index;
	if(eRecaudacion_cambiarEstado (arrayRecaudacion,tam,arrayContibuyente,cant,arrayTipo, cantTipo,&index)==0)
	{
		if(utn_getRespuesta ("\n\nDESEA CAMBIAR EL ESTADO A SALDAR [S] SI [N]: ","\n\nDESEA CAMBIAR EL ESTADO A SALDAR [S] SI [N]: ", 3)==0)
		{
			arrayRecaudacion[index].idEstado = 2;
			rtn = 0;
		}
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}
int eRecaudacion_obtenerNombreEstado (eEstado arrayEstado[],int cant,int estado,char detalle[20])
{
	int rtn = -1;
	int i;
	if(arrayEstado != NULL && cant > 0 && (isdigit(estado)) == 0  && detalle != NULL)
	{
		for (i = 0; i < cant; i++)
		{
			if(arrayEstado[i].idEstado == estado)
			{
				if(arrayEstado[i].idEstado== 1)
				{
					strcpy(detalle,"REFINANCIADO");
					rtn = 0;
				break;
				}
				if(arrayEstado[i].idEstado== 2)
				{
					strcpy(detalle,"SALDADO");
					rtn = 0;
				break;
				}

			}
		}
	}

	return rtn;
}


int eRecaudacion_isEmpty (eRecaudacion arrayRecaudacion[], int tam)
{
	int rtn = -1;
	for(int i = 0; i < tam; i++)
	{
		if(arrayRecaudacion[i].isEmpty == 0)
		{
			rtn = 0;
		}

	}
	return rtn;
}

