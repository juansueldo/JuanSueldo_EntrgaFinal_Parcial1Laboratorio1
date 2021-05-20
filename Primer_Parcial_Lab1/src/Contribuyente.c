#include "Contribuyente.h"


int eContribuyente_inicializar (eContribuyente arrayContribuyentes[],int tam)
{
	int i;
	int rtn = -1;
	if(arrayContribuyentes != NULL && tam >0)
	{

		for (i = 0; i < tam; i++)
		{
			strcpy(arrayContribuyentes[i].nombre," ");
			strcpy(arrayContribuyentes[i].apellido," ");
			strcpy(arrayContribuyentes[i].cuil," ");
			arrayContribuyentes[i].idContribuyente = 0;
			arrayContribuyentes[i].isEmpty=1;
		}
		rtn = 0;
	}
	return rtn;
}
int eContribuyente_buscarLibre (eContribuyente arrayContribuyentes[],int tam)
{
	int rtn;
	int i;
	rtn = -1;
	if(arrayContribuyentes != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if(arrayContribuyentes[i].isEmpty==1)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}
int eContribuyente_buscarId (eContribuyente arrayContribuyentes[],int tam,int id)
{
	int rtn = -1;
	int i;

	if (arrayContribuyentes != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (arrayContribuyentes[i].idContribuyente == id && arrayContribuyentes[i].isEmpty == 0)
			{
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
eContribuyente eContribuyente_cargar (void)
{
	eContribuyente auxContribuyente;

		if((utn_getString(auxContribuyente.nombre,30,"\nINGRESE EL NOMBRE DEL CONTRIUBUYENTE: ","\nERROR. INGRESE EL NOMBRE DEL CONTRIUBUYENTE: ",1,3)) != 0)
		{
			printf("\nERROR. NO SE INGRESO EL NOMBRE DEL CONTRIBUYENTE.");
		}
		if((utn_getString(auxContribuyente.apellido,30,"\nINGRESE EL APELLIDO DEL CONTRIUBUYENTE: ","\nERROR. INGRESE EL APELLIDO DEL CONTRIUBUYENTE: ",1,3)) != 0)
		{
			printf("\nERROR. NO SE INGRESO EL APELLIDO DEL CONTRIBUYENTE.");
		}
		if(utn_getCuil(auxContribuyente.cuil,"\nINGRESE EL CUIL DEL CONTIBUYENTE[FORMATO 11-11111111-1]: ","\nERROR. INGRESE EL CUIL DEL CONTIBUYENTE[FORMATO 11-11111111-1]: ",3) != 0)
		{
			printf("\nERROR. NO SE INGRESO EL CUIL DEL CONTRIBUYENTE.");
		}

	return auxContribuyente;
}
int eContribuyente_alta (eContribuyente arrayContribuyentes[], int tam, int *pIdContador)
{
	int rtn = -1;
	eContribuyente auxContribuyente;

	int index = eContribuyente_buscarLibre (arrayContribuyentes, tam);

	if (index != -1)
	{
		auxContribuyente = eContribuyente_cargar();

		auxContribuyente.isEmpty = 0;
		rtn = 0;
	}
	if(rtn == 0)
	{
		(*pIdContador)++;
		auxContribuyente.idContribuyente = *pIdContador;
		arrayContribuyentes[index] = auxContribuyente;
	}


	return rtn;
}
void eContribuyente_mostrarUno (eContribuyente arrayContribuyentes[],int tam)
{
	utn_getMayusMin (arrayContribuyentes[tam].nombre, MAX_CHARS_CADENAS);
	utn_getMayusMin (arrayContribuyentes[tam].apellido, MAX_CHARS_CADENAS);
	printf("\n%5d %15s     %15s         %15s    "
			,arrayContribuyentes[tam].idContribuyente
			,arrayContribuyentes[tam].nombre
			,arrayContribuyentes[tam].apellido
			,arrayContribuyentes[tam].cuil);
}
int eContribuyente_mostrarTodos (eContribuyente arrayContribuyentes[],int tam)
{
	int i;
	int rtn = -1;
	if(arrayContribuyentes != NULL && tam > 0)
	{
		printf("\n*************************************************************\n");
		printf("\n ID    NOMBRE           APELLIDO               CUIL       ");
		printf("\n**************************************************************\n");
		for (i = 0; i < tam; i++)
		{

			if(arrayContribuyentes[i].isEmpty == 0)
			{
				eContribuyente_mostrarUno(arrayContribuyentes,i);
			}
		}
		rtn = 0;
	}
	return rtn;
}
eContribuyente eContribuyente_modificarUno (eContribuyente arrayContribuyentes, int campoModificar)
{
	eContribuyente auxContribuyente = arrayContribuyentes;

	switch (campoModificar)
	{
		case 1:
			if((utn_getString(auxContribuyente.nombre,30,"\nINGRESE EL NOMBRE DEL CONTRIUBUYENTE: ","\nERROR. INGRESE EL NOMBRE DEL CONTRIUBUYENTE: ",1,3)) != 0)
			{
				printf("\nERROR. NO SE INGRESO EL NOMBRE DEL CONTRIBUYENTE.");
			}
			fflush(stdin);
			break;
		case 2:
			if((utn_getString(auxContribuyente.apellido,30,"\nINGRESE EL APELLIDO DEL CONTRIUBUYENTE: ","\nERROR. INGRESE EL APELLIDO DEL CONTRIUBUYENTE: ",1,3)) != 0)
			{
				printf("\nERROR. NO SE INGRESO EL APELLIDO DEL CONTRIBUYENTE.");
			}
			fflush(stdin);
			break;
		case 3:
			if(utn_getCuil(auxContribuyente.cuil,"\nINGRESE EL CUIL DEL CONTIBUYENTE: ","\nERROR. INGRESE EL CUIL DEL CONTIBUYENTE: ",3) != 0)
			{
				printf("\nERROR. NO SE INGRESO EL CUIL DEL CONTRIBUYENTE.");
			}
			break;
		default:
			break;
	}
	return auxContribuyente;
}
int eContribuyente_modificar (eContribuyente arrayContribuyentes[], int tam)
{
	int rtn = -1;
	int idContribuyente;
	int index;
	int flag = 0;
	int auxMod;
	eContribuyente auxContribuyente;
	if(eContribuyente_isEmpty (arrayContribuyentes, tam) == 0)
	{
		if(eContribuyente_mostrarTodos(arrayContribuyentes, tam) == 0)
		{
			flag = 1;
		}

		if (flag)
		{
			printf("\n*****************************************************************\n");
			utn_getNumero(&idContribuyente,"\nINGRESE EL ID DEL CONTRIBUYENTE A MODIFICAR: ","ERORR. NO ES UN ID VALIDO",1000,1050,3);
			while (eContribuyente_buscarId(arrayContribuyentes, tam, idContribuyente) == -1)
			{
				utn_getNumero(&idContribuyente,"\nNO EXISTE ID. REINGRESE EL ID DEL CONTRIBUYENTE: ","ERORR. NO ES UN ID VALIDO",1000,1050,3);
			}

			index = eContribuyente_buscarId(arrayContribuyentes, tam, idContribuyente);
			printf("\n*****************************************************************\n");
			printf("INGRESE EL CAMPOR A MODIFICAR: \n1. NOMBRE \n2. APELLIDO \n3. CUIL \n");
			printf("\n*****************************************************************\n");
			printf("Ingrese:");
			scanf("%d",&auxMod);
			if(utn_getRespuesta ("\nDESEA MODIFICAR EL CONTRIBUYENYE  [S] SI [N] NO: ","\nERROR. DESEA MODIFICAR EL CONTRIBUYENYE  [S] SI [N] NO: ", 3)==0)
			{
				auxContribuyente = eContribuyente_modificarUno(arrayContribuyentes[index],auxMod);
				arrayContribuyentes[index] = auxContribuyente;
				rtn = 0;
			}
			}
			else
			{
				rtn = -1;
			}

		}

		return rtn;
}

int eContribuyente_isEmpty (eContribuyente arrayContribuyentes[], int tam)
{
	int rtn = -1;
	for(int i = 0; i < tam; i++)
	{
		if(arrayContribuyentes[i].isEmpty == 0)
		{
			rtn = 0;
		}

	}
	return rtn;
}

int eContribuyente_bajaContribuyente (eContribuyente arrayContribuyentes[], int tamanio, int*pIdContribuyente, int*index)
{
	int rtn = -1;
	int auxIndex;

	auxIndex = eContribuyente_buscarId(arrayContribuyentes, tamanio, *pIdContribuyente);

	if(utn_getRespuesta ("\nDESEA DAR DE BAJA EL CONTRIBUYENYE  [S] SI [N] NO:  ","\nERROR. DESEA DAR DE BAJA EL CONTRIBUYENYE  [S] SI [N] NO: ", 3)==0)
	{
		arrayContribuyentes[auxIndex].isEmpty = 1;
		*index = auxIndex;
		rtn = 0;
	}
	else
	{
		rtn = -1;
	}

	return rtn;
}
