#include "Informes.h"


void eRecaudacion_mostrarTipoEstado(eRecaudacion arrayRecaudacion[],int tam, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	char detalle[30];
	char detalleEstado[20];
	eRecaudacion_obtenerNombre (arrayTipo,cantTipo,arrayRecaudacion[tam].idTipo,detalle);
	eRecaudacion_obtenerNombreEstado (arrayEstado,cantEstado,arrayRecaudacion[tam].idEstado,detalleEstado);
	printf("\n**********************************************************************************\n");
	printf(" ID RECAUDACION        MES      IMPORTE      TIPO     ESTADO  ");
	printf("\n**********************************************************************************\n");
	printf("%d    %15d   %10.2f     %15s   %15s\n"
			,arrayRecaudacion[tam].idRecaudacion
			,arrayRecaudacion[tam].mes
			,arrayRecaudacion[tam].importe
			,detalle
			,detalleEstado);


}
int mostrarTodos(eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int rtn = -1;
	int i;
	int j;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for(i = 0; i < cant; i++)
		{
			if(arrayContribuyente[i].isEmpty == 0)
			{
				printf("\n\n*************************************************************\n");
				printf(" ID    NOMBRE           APELLIDO               CUIL       ");
				printf("\n**************************************************************\n");
				eContribuyente_mostrarUno(arrayContribuyente,i);
			}

			for(j = 0; j < tam; j++)
			{
				if(arrayContribuyente[i].idContribuyente == arrayRecaudacion[j].idContribuyente && arrayRecaudacion[j].isEmpty ==0)
				{
					eRecaudacion_mostrarTipoEstado(arrayRecaudacion,j,arrayTipo,cantTipo,arrayEstado,cantEstado);
					rtn =0;
				}

				}
			}
		}
		return rtn;
}
int eRecaudacion_mostrarSaldados (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int rtn = -1;
	int i;
	int j;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(arrayRecaudacion[i].isEmpty == 0 && arrayRecaudacion[i].idEstado == 2)
			{
				eRecaudacion_mostrarTipoEstado(arrayRecaudacion,i,arrayTipo,cantTipo,arrayEstado,cantEstado);

				for(j = 0; j < tam; j++)
				{
					if(arrayRecaudacion[i].idContribuyente == arrayContribuyente[j].idContribuyente && arrayContribuyente[j].isEmpty ==0)
					{
					printf("\n*************************************************************\n");
					printf("  ID    NOMBRE           APELLIDO               CUIL       ");
					printf("\n**************************************************************\n");
					eContribuyente_mostrarUno(arrayContribuyente,j);
					printf("\n\n");
					rtn = 0;
					}
				}
			}
		}
	}
	return rtn;
}

int baja_ContribuyenteRecaudaciones (eContribuyente arrayContribuyentes[], int tamanio, eRecaudacion arrayRecaudacion[], int cant)
{
	int rtn = -1;
	int idContribuyente;
	int index;
	int flag = 0;
	if(arrayContribuyentes != NULL && tamanio > 0 && arrayRecaudacion != NULL && cant > 0)
	{
	if(eContribuyente_isEmpty(arrayContribuyentes, tamanio)==0)
	{
		if (eContribuyente_mostrarTodos(arrayContribuyentes, tamanio) == 0)
		{
			flag = 1;
		}

		if (flag == 1)
		{
		printf("\n*****************************************************************\n");
		utn_getNumero(&idContribuyente,"\nINGRESE EL ID DEL CONTRIBUYENTE A DAR DE BAJA: ","\nERORR. NO ES UN ID VALIDO\n",1000,1999,3);
		while (eContribuyente_buscarId(arrayContribuyentes, tamanio, idContribuyente) == -1)
		{
			utn_getNumero(&idContribuyente,"\nNO EXISTE ID. INGRESE EL ID DEL CONTRIBUYENTE A DAR DE BAJA:","\nERORR. NO ES UN ID VALIDO\n",1000,1999,3);
		}
		index = eContribuyente_buscarId(arrayContribuyentes, tamanio, idContribuyente);
		if(eContribuyente_isEmpty (arrayContribuyentes,tamanio) == 0)
		{
			if(eContribuyente_bajaContribuyente (arrayContribuyentes, tamanio, &idContribuyente, &index)==0)
			{
				for(int i = 0; i < cant; i++)
				{
					if(idContribuyente == arrayRecaudacion[i].idContribuyente)
					{
						arrayRecaudacion[i].isEmpty = 1;

					}
				}
			}

		}
		}
		rtn = 0;
	}
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}
void menu (eContribuyente arrayContribuyentes[], int tam,eRecaudacion arrayRecaudadores[], int cant, eTipo arrayTipo [],int cantTipo,eEstado arrayEstado[], int cantEstado )
{
	int opcion;
	int opcion2;
	int flagAlta = 0;
	int flagRecaudacion = 0;
	int flagEstado = 0;
	int contIdContribuyente = 999;
	int contIdRecaudaciones = 99;


	do
	{
		utn_menu(&opcion, "\nMenu\n1. ALTA COTRIBUYENTE \n2. MODIFICAR CONTRIBUYENTE \n3. BAJA CONTRIBUYENTE \n4. ALTA RECAUDADACIONES \n5. REFINANCIAR RECAUDACION \n6. SALDAR RECAUDACION \n7. IMPRIMIR CONTRIBUYEBTES \n8. IMPRIMIR RECAUDACION \n9. INFORMES \nINGRESE: ", "\nNO ES VALIDO\n", 1, 10);

		switch (opcion)
		{

		case 1:
			if (eContribuyente_alta(arrayContribuyentes, tam, &contIdContribuyente)==0)
			{
				printf("\nALTA EXITOSA.\n\n");
				flagAlta = 1;
			}
			else
			{
				printf("\nERROR. SIN ESPACIO PARA ALMACENAR.\n\n");
			}
			system("pause");
			break;
		case 2:
			if(flagAlta == 1)
			{
				if(eContribuyente_modificar(arrayContribuyentes, tam) ==0)
				{
					printf("\nSE MODIFICO EL CONTRIBUYENTE.\n\n");
				}
				else
				{
					printf("\nNO SE MODIFICO EL CONTRIBUYENTE.\n\n");
				}
			}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE PARA MODIFICARLO.\n\n");
			}
			system("pause");
			break;
		case 3:
			if(flagAlta == 1)
			{

				if(baja_ContribuyenteRecaudaciones(arrayContribuyentes, tam, arrayRecaudadores, cant) ==0)
				{
					printf("\nSE DIO LA BAJA DEL CONTRIBUYENTE.\n\n");
				}
				else
				{
					printf("\nNO SE DIO LA BAJA.\n\n");
				}
			}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE PARA DARLO DE BAJA.\n\n");
			}
			system("pause");
			break;
		case 4:
			if(flagAlta == 1)
			{
				if (eRecaudacion_alta(arrayRecaudadores, cant, &contIdRecaudaciones,arrayContribuyentes,tam)==0)
				{
					printf("\nALTA EXITOSA.\n\n");
					eRecaudacion_mostrarTodos (arrayRecaudadores,cant, arrayTipo, cantTipo);
					flagRecaudacion = 1;
				}
				else
				{
					printf("\nERROR. SIN ESPACIO PARA ALMACENAR.\n\n");
				}
			}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE PARA AGREGAR RECAUDACIONES.\n\n");
			}
			system("pause");
			break;
		case 5:
			if(flagAlta == 1 && flagRecaudacion == 1)
			{
				if(eRecaudacion_estadoRefinanciar (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo)==0)
				{
					printf("\nSE REFINANCIO.\n\n");
					flagEstado = 1;
				}
				else
				{
					printf("\nNO SE REFINANCIO.\n\n");
				}
			}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE Y RECAUDACION PARA CONTINUAR.\n\n");
			}
			system("pause");
			 break;
		case 6:
			if(flagAlta == 1 && flagRecaudacion == 1)
			{
				if(eRecaudacion_estadoSaldado (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo)==0)
				{
					printf("\nSE SALDO.\n\n");
					flagEstado = 1;
				}
				else
				{
					printf("\nNO SE SALDO.\n\n");
				}
				}
			else
			{
				printf("\nDEBE INGRESAR UN CONTRIBUYENTE Y RECAUDACION PARA CONTINUAR.\n\n");
			}
			system("pause");
			break;
		case 7:
			if(flagAlta == 1 && flagRecaudacion == 1 && flagEstado == 1)
			{
				if(mostrarTodos (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo,arrayEstado, cantEstado) != 0)
				{
					printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
				}

			}
			else
			{
				printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
			}
			break;
		case 8:
			if(flagAlta == 1 && flagRecaudacion == 1 && flagEstado == 1)
			{
				if(eRecaudacion_mostrarSaldados (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo,arrayEstado, cantEstado) != 0)
				{
					printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
				}

			}
			else
			{
				printf("\nSE DEBEN INGRESAR TODOS LOS DATOS.\n\n");
			}
			break;
		case 9:
			do
			{
				utn_menu(&opcion2, "\nINFORMES\n1. MAYOR ESTADO REFINANCIAR \n2. SALDADO E IMPORTE MAYOR A 1000 \n3. BAJA CONTRIBUYENTE \n4. ALTA RECAUDADACIONES \n5. VOLVER ATRAS \nINGRESE: ", "\nNO ES VALIDO\n", 1, 5);

					switch (opcion2)
					{
					case 1:
						if(eInformes_informeRefinanciar (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo,arrayEstado, cantEstado)==0)
						{
							mostrarTodos (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo,arrayEstado, cantEstado);
						}
						break;
					case 2:
						if(eInformes_SaldadoImporte(arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo,arrayEstado, cantEstado)!=0)
						{
							printf("\nNO HAY NADA PARA INFORMAR");
						}
						break;
					case 3:
						if(mostrarTodos (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo,arrayEstado, cantEstado)!=0)
						{
							printf("\nNO HAY NADA PARA INFORMAR");
						}
						break;
					case 4:
						if(eInformes_febrero (arrayRecaudadores,cant, arrayContribuyentes, tam, arrayTipo, cantTipo,arrayEstado, cantEstado)!=0)
						{
							printf("\nNO HAY NADA PARA INFORMAR");
						}
						break;
					}
			}while(opcion2 != 5);
			system("pause");
			break;
		case 10:
			printf("\nFIN.");
			break;
		}
	} while (opcion != 10);
}
/*
9) Informes:
a) Contribuyentes con más recaudaciones en estado “refinanciar”.

c) Informar todos los datos de los contribuyentes de un tipo de recaudación
ingresada por el usuario (ARBA, IIBB, GANANCIAS)
d)Nombre y c.u.i.l. de los Contribuyentes que pagaron impuestos en el mes de
FEBRERO.*/
int eInformes_informeRefinanciar (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int i;
	int j;
	int rtn = -1;
	eRecaudacion aux;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{

	for(i = 0; i < cant -1;i++)
		{
			for(j = i+1; j < cant; j++)
			{
				if(arrayRecaudacion[i].idTipo > arrayRecaudacion[j].idTipo)
					{
						aux = arrayRecaudacion[i];
						arrayRecaudacion[i] = arrayRecaudacion[j];
						arrayRecaudacion[j] = aux;
						rtn = 0;
					}

			}
		}
	}


		return rtn;
}
int eInformes_febrero (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int rtn = -1;
	if(arrayRecaudacion != NULL && arrayContribuyente != NULL && arrayTipo != NULL && tam > 0 && cant > 0 && cantTipo > 0)
	{
		for(int i =0; i < cant; i++)
		{
		if(arrayRecaudacion[i].mes == 2)
		{
			for(int j = 0; j < tam; j++)
			{
				if(arrayRecaudacion[i].idContribuyente == arrayContribuyente[j].idContribuyente)
				{
					utn_getMayusMin (arrayContribuyente[j].nombre, MAX_CHARS_CADENAS);
					printf("NOMBRE      CUIL");
					printf("\n%15s      %15s   "
								,arrayContribuyente[j].nombre
								,arrayContribuyente[j].cuil);
				}
			}
		}
		}
		rtn = 0;
	}
	return rtn;
}
/*b) Cantidad de recaudaciones saldadas de importe mayor a 1000: Se imprimirá
la cantidad de recaudaciones en estado “saldado” con ese importe o mayor.*/
int eInformes_SaldadoImporte (eRecaudacion arrayRecaudacion[],int tam, eContribuyente arrayContribuyente[], int cant, eTipo arrayTipo[], int cantTipo, eEstado arrayEstado[], int cantEstado)
{
	int contador = 0;
	if(eRecaudacion_estadoSaldado (arrayRecaudacion,tam, arrayContribuyente, cant, arrayTipo, cantTipo)==0)
	{
		for(int i = 0; i< tam; i++)
		{
		if(arrayRecaudacion[i].importe >= 1000)
		{
			mostrarTodos (arrayRecaudacion,cant, arrayContribuyente, i, arrayTipo, cantTipo,arrayEstado, cantEstado);
			contador++;
		}
		}
	}
	printf("LA CANTIDAD DE RECAUDACIONES SALDADAS CON ESTADO SALDADO E IMPORTE MAYOR A $1000: %d", contador);
	return 0;
}
