#include "utn.h"

int utn_getTexto (char *pString)
{
	int rtn = -1;

	if (strlen(pString) > 0)
	{
		for (int i = 0; i < strlen(pString); i++)
		{
			if (isalpha(pString[i]) == 0)
			{
				if (isspace(pString[i]) == 0)
				{
					rtn = 0;
					break;
				}
			}
		}
	}

	return rtn;
}

int utn_getString(char array[],int max,char mensaje[],char errorMensaje[],char min,int intentos)
{
	int rtn = -1;
	int aux;
	char bufferString[max];
	int i;
	if(array != NULL && max > 0 &&  mensaje != NULL && errorMensaje != NULL &&  min <= max && intentos >= 0 )
	{
		printf("\n%s",mensaje);
		fflush(stdin);
		scanf("%s",bufferString);

		for (i = 0; i < intentos; ++i)
		{
			if(utn_getTexto (bufferString) != 0)
			{
			aux = strlen(bufferString);

			if(aux >= min && aux <= max)
			{
				strcpy(array,bufferString);
				rtn = 0;
				break;
			}
			}
			else
			{
				printf("\n %s",errorMensaje);
				fflush(stdin);
				scanf("%s",bufferString);

			}

		}
	}
	return rtn;
}

int myGets ( char * pCadena, int longitud)
{
	int rtn=-1;
	if (pCadena != NULL && longitud >0 && fgets (pCadena,longitud,stdin)==pCadena)
	{
		fflush (stdin);
		if (pCadena[ strlen (pCadena)-1] == '\n' )
		{
			pCadena[ strlen (pCadena)-1] = '\0' ;
		}
		rtn=0;
	}
	return rtn;
}

int esNumerica(char* pNum)
{
	int i = 0;
	int rtn = 0;
	if(pNum != NULL && strlen(pNum) > 0)
	{
		while(pNum[i] != '\0')
		{
			if(pNum[i] < '0' || pNum[i] > '9')
			{
				rtn = -1;
				break;
			}
			i++;
		}
	}
	return rtn;
}

int getInt ( int* pNum)
{
	int rtn=-1;
	char buffer[64];
	if (pNum != NULL)
	{
		if (myGets(buffer, sizeof (buffer))==0 && esNumerica(buffer)==0)
		{
			*pNum = atoi (buffer);
			 rtn = 0;
		}
	}
	return rtn;
}

int utn_getNumero(int* pNum,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int bufferInt;
	int rtn = -1;
	if(pNum != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("%s",mensaje);
			fflush(stdin);
			if(getInt(&bufferInt) == 0)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pNum = bufferInt;
					rtn = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return rtn;
}
int esFloat (char pNum[])
{
   int i=0;
   int rtn = -1;
   int cantidadPuntos=0;
   while(pNum[i] != '\0')
   {
       if (pNum[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(pNum[i] < '0' || pNum[i] > '9')
    	   rtn = 0;
       i++;
   }
   return rtn;
}

int getNumFloat (float * pFloat)
{
	int rtn = -1;
	char buffer[64];
	if(pFloat != NULL)
	{
		if(myGets(buffer,sizeof(buffer)) == 0 && esFloat(buffer))
		{
			*pFloat = atof(buffer);
			rtn = 0;
		}
	}
	return rtn;
}
int utn_getFloat(float* pFloat,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	float bufferFloat;
	int rtn = -1;
	if(pFloat != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos > 0)
	{
		while(reintentos > 0)
		{
			reintentos--;
			printf("\n %s",mensaje);
			fflush(stdin);
			if(getNumFloat(&bufferFloat)==0)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pFloat = bufferFloat;
					rtn = 0;
					break;
				}
			}
			printf("\n %s",mensajeError);
		}
	}

	return rtn;

}
int utn_menu(int *pOpcion, char *mensaje, char *mensajeError, int min, int max)
{

	int rtn = -1;
	int bufferMenu;
	if (mensaje != NULL && mensajeError != NULL && min <= max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &bufferMenu);

		if(isdigit(bufferMenu) == 0)
		{
			if (bufferMenu >= min && bufferMenu <= max)
			{
				*pOpcion = bufferMenu;
				rtn = 0;
			}
		}
		else
		{
			printf("%s", mensajeError);
		}
	}
	return rtn;
}
int utn_getLower(char* letra)
{
	strlwr(letra);
	return 0;
}int utn_getChar (char *pData)
{
	int rtn = 1;
	int i;
	if (strlen(pData) > 0)
	{
		for (i = 0; i < strlen(pData); i++)
		{
		if (isalpha(pData[i]) == 0)
		{
			rtn = 0;
			break;
		}
		}
	}
	else
	{
		rtn = 1;
	}

	return rtn;
}
int utn_getRespuesta (char* mensaje,char*mensajeError, int reintentos)
{
	int rtn = -1;
	char respuesta;
	while(reintentos > 0)
	{
		reintentos--;
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&respuesta);
		if(utn_getChar(&respuesta) ==0)
		{
		utn_getLower (&respuesta);
		while(respuesta != 's' && respuesta != 'n')
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c",&respuesta);
		}
		if(respuesta == 's')
		{
			rtn = 0;
			break;
		}
		else if(respuesta == 'n')
		{
			rtn = -1;
			break;
		}
	}}
	return rtn;
}
int utn_getMayusMin (char name[], int tam)
{
   strlwr(name);

   name[0] = toupper(name[0]);


   return 0;
}

int utn_EsCuil(char* cadena)
{
	int rtn;
	int i;
	int contadorDigito=0;
	int contadorGuion=0;

	if(cadena!=NULL)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(isdigit(cadena[i])!=0)
			{
				contadorDigito++;
			}
			else
			{
				if(cadena[i]=='-')
				{
					contadorGuion++;
				}
				else
				{
					rtn=-1;
					break;
				}
			}
		}
		if(contadorDigito==11 && contadorGuion==2)
		{
			rtn=0;
		}
	}
	return rtn;
}

int utn_getCuil(char cadena[],char mensaje[],char eMensaje[],int reintentos)
{
	int rtn;
	char buffer[14];
	int i;
	int aux;

		if(cadena!=NULL && mensaje!= NULL && eMensaje!= NULL && reintentos>0)
		{
			for(i=reintentos;i>0;i--)
			{
				printf("\n %s",mensaje);
				fflush(stdin);
				gets(buffer);
				aux=utn_EsCuil(buffer);
				if(aux==0)
				{
					if(buffer[2]=='-' && buffer[11]=='-')
					{
						strcpy(cadena,buffer);
						rtn=0;
						break;
					}
				}
				else
				{
					printf("\n %s\n",eMensaje);
				}
			}
		}
		if(reintentos==0)
		{
			rtn=-1;
		}
	return rtn;
}



