/*
 * funciones.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Lauty
 */

#include "funciones.h"

int menu()
{
	int opcion;

	printf("Bienvenidos al menu!\n");
	printf("0. Cancelar\n");
	printf("1. Alta Mascota\n");
	printf("2. Modificar Mascota\n");
	printf("3. Baja Mascota\n");
	printf("4. Listar Mascotas\n");
	printf("5. Listar Tipos\n");
	printf("6. Listar Colores\n");
	printf("7. Listar Servicios\n");
	printf("8. Alta Trabajo\n");
	printf("9. Listar Trabajos\n");
	printf("10. Mascotas del color seleccionado\n");
	printf("11. Ver promedio de mascotas vacunadas\n");
	printf("12. Ver mascotas de menor edad\n");
	printf("13. Ver mascotas separadas por tipo\n");
	printf("14. Seleccionar color y tipo\n");
	printf("15. Mostrar colores con mas mascotas\n");
	opcion = GetInt("Ingrese una opcion:");




	return opcion;
}

eMascotas cargarMascotas(eTipo tipos[],int tTipos,eColor colores[],int tColores)
{
	eMascotas auxiliar;

	auxiliar.id=GenerarId();
	GetString("Ingrese el nombre:", auxiliar.nombre);
	MostrarTipos(tipos, tTipos);
	auxiliar.idTipo=GetIntParam("Ingrese el id correspondiente:", 1000, 1004);
	MostrarColores(colores, tColores);
	auxiliar.idColor=GetIntParam("Ingrese el id correspondiente:",5000,5004);
	auxiliar.edad=GetIntParam("Ingrese la edad:",1,99);
	auxiliar.vacunado=GetChar("Ingrese 's' o 'n' para saber si su mascota esta o no vacunada:");
	while(auxiliar.vacunado!='s' && auxiliar.vacunado!='n')
	{
		auxiliar.vacunado=GetChar("ERROR.Ingrese 's' o 'n' para saber si su mascota esta o no vacunada:");
	}

	auxiliar.isEmpty=OCUPADO;

	return auxiliar;
}

int InsertarMascota(eTipo tipos[],int tTipos,eColor colores[],int tColores,eMascotas mascotas[],int tMascotas)
{
	int index=BuscarLibre(mascotas, tMascotas);

	if(index==-1)
	{
		printf("No hay espacio disponible!\n");
	}else
	{

		mascotas[index]=cargarMascotas(tipos, tTipos, colores, tColores);
	}


	return 0;
}

void MostrarMascota(eMascotas mascotas)
{

		printf("ID:%d|NOMBRE:%s|EDAD:%d", mascotas.id,mascotas.nombre,mascotas.edad);

		if(mascotas.vacunado=='s')
		{
			printf("|VACUNADO\n");
		}else
		{
			printf("|NO VACUNADO\n");
		}
}

void ListarMascotas(eTipo tipos[],int tTipos,eColor colores[],int tColores,eMascotas mascotas[],int tMascotas)
{
	int i;
	int c;
	int t;

	for(i=0;i<tMascotas;i++)
	{

		if(mascotas[i].isEmpty==OCUPADO)
		{

		printf("ID:%d|NOMBRE:%s|EDAD:%d", mascotas[i].id,mascotas[i].nombre,mascotas[i].edad);

		for(c=0;c<tColores;c++)
		{
			if(mascotas[i].idColor==colores[c].id)
			{
				printf("|COLOR:%s", colores[c].nombreColor);
			}


		}

		for(t=0;t<tTipos;t++)
		{
			if(mascotas[i].idTipo==tipos[t].id)
			{
				printf("|%s",tipos[t].descripcion);
			}


		}

		if(mascotas[i].vacunado=='s')
		{
			printf("|VACUNADO\n\n");
		}else if(mascotas[i].vacunado=='n')
		{
			printf("|NO VACUNADO\n\n");
		}

		}//Cierre if

	}




}

void ModificarMascotas(eTipo tipos[],int tTipos,eMascotas mascotas[],int tMascotas,eColor colores[],int tColores)
{
	ListarMascotas(tipos, tTipos, colores, tColores, mascotas, tMascotas);

	int index=GetInt("Ingrese la id correspondiente: ");
	int retorno=BuscarId(mascotas, tMascotas, index);
	int opcion;

	if(retorno!=-1)
	{
		printf("ID ENCONTRADA!\n");
		printf("1 .Editar Tipo\n");
		printf("2. Editar Vacunado\n");
		printf("3. Cancelar\n");
		opcion=GetIntParam("Ingrese la opcion correspondiente:", 1, 3);

		switch(opcion)
		{
			case 1:
				printf("Usted esta editando el tipo...\n\n");
				MostrarTipos(tipos, tTipos);
				mascotas[retorno].idTipo=GetIntParam("Ingrese el id correspondiente:", 1000, 1004);

				break;

			case 2:

				if(mascotas[retorno].vacunado=='s')
				{

					mascotas[retorno].vacunado='n';
					printf("Se ha cambiado el vacunado a NO!\n");
				}

				if(mascotas[retorno].vacunado=='n')
				{
					mascotas[retorno].vacunado='s';
					printf("Se ha cambiado el vacunado a SI!\n");
				}


				break;
			case 3:

				printf("Ha cancelado correctamente!\n");

				break;

			default:

				printf("ERROR EN LA OPCION INGRESADA\n");

				break;

		}




	}else printf("No se ha encontrado el id!");





}

void EliminarMascotas(eTipo tipos[],int tTipos,eMascotas mascotas[],int tMascotas,eColor colores[],int tColores)
{
	ListarMascotas(tipos, tTipos, colores, tColores, mascotas, tMascotas);

	int index=GetInt("Ingrese el id correspondiente: ");
	int retorno=BuscarId(mascotas, tMascotas, index);

	if(retorno!=-1)
	{
		mascotas[retorno].isEmpty=EMPTY;
		printf("Mascota eliminada con exito!\n");

	}else
	{
		printf("No se ha encontrado el id ingresado!\n");
	}

}

eTrabajos cargarTrabajo(eServicios servicios[],int tServicios,eMascotas mascotas[],int tMascotas,eTipo tipos[],int tTipos,eColor colores[],int tColores)
{
	eTrabajos auxiliar;

	auxiliar.id = GenerarIdT();

	ListarMascotas(tipos, tTipos, colores, tColores, mascotas, tMascotas);
	auxiliar.idMascota = GetInt("Ingrese el id correspondiente:");
	int retorno=BuscarId(mascotas, tMascotas, auxiliar.id);
	while(retorno==-1)
	{
		printf("Su id no se ha encontrado!\n");
		auxiliar.idMascota = GetInt("Reingrese el id correspondiente:");
	}
	MostrarServicios(servicios, tServicios);
	auxiliar.idServicio=GetIntParam("Ingrese el id correspndiente:", 20000, 20002);
	auxiliar.fecha.dia=GetIntParam("Ingrese el dia:", 1, 31);
	auxiliar.fecha.mes=GetIntParam("Ingrese el mes:", 1, 12);
	auxiliar.fecha.anio=GetIntParam("Ingrese el año:",2021,2022);


	auxiliar.isEmpty=OCUPADO;

	return auxiliar;
}

int InsertarTrabajo(eServicios servicios[],int tServicios,eMascotas mascotas[],int tMascotas,eTipo tipos[],int tTipos,eColor colores[],int tColores,eTrabajos trabajos[],int tTrabajos)
{
	int index = BuscarTrabajoLibre(trabajos, tTrabajos);

	if(index!=-1)
	{

		trabajos[index]=cargarTrabajo(servicios, tServicios, mascotas, tMascotas, tipos, tTipos, colores, tColores);

	}else printf("No hay espacio disponible!\n");

	return 0;
}

void ListarTrabajos(eServicios servicios[],int tServicios,eMascotas mascotas[],int tMascotas,eTipo tipos[],int tTipos,eColor colores[],int tColores,eTrabajos trabajos[],int tTrabajos)
{
	int i;
	int m;
	int s;

	for(i=0;i<tTrabajos;i++)
	{
		if(trabajos[i].isEmpty==OCUPADO)
		{


		printf("ID:%d", trabajos[i].id);

		for(m=0;m<tMascotas;m++)
		{

			if(trabajos[i].idMascota==mascotas[m].id)
			{
				printf("|NOMBRE:%s|EDAD:%d", mascotas[m].nombre,mascotas[m].edad);

			}


		}

		for(s=0;s<tServicios;s++)
		{
			if(trabajos[i].idServicio==servicios[s].id)
			{
				printf("|%s|$%.2f", servicios[s].descripcion,servicios[s].precio);
			}


		}

		printf("|FECHA:%d/%d/%d\n",trabajos[i].fecha.dia,trabajos[i].fecha.mes,trabajos[i].fecha.anio);

		}//cierre if
	}



}

//

int seleccionarColor(eMascotas mascotas[],int tMascotas,eColor color[],int tColor)
{
	MostrarColores(color, tColor);
	int id1=5000;
	int id2=5001;
	int id3=5002;
	int id4=5003;
	int id5=5004;

	int opcion=GetIntParam("Ingrese el id correspondiente:", 5000, 5004);

	printf("\nMostrando animales del color seleccionado...\n");

	switch(opcion)
	{
		case 5000:
			mostrarcolorseleccionado(mascotas, tMascotas, color, tColor,id1);
			break;
		case 5001:
			mostrarcolorseleccionado(mascotas, tMascotas, color, tColor,id2);
			break;
		case 5002:
			mostrarcolorseleccionado(mascotas, tMascotas, color, tColor,id3);
			break;
		case 5003:
			mostrarcolorseleccionado(mascotas, tMascotas, color, tColor,id4);
			break;
		case 5004:
			mostrarcolorseleccionado(mascotas, tMascotas, color, tColor,id5);
			break;
	}



	return 0;
}

void mostrarcolorseleccionado(eMascotas mascotas[],int tMascotas,eColor color[],int tColor,int id)
{
	int i;

	for(i=0;i<tMascotas;i++)
	{
		if(mascotas[i].isEmpty==OCUPADO && mascotas[i].idColor==id)
		{

			MostrarMascota(mascotas[i]);

		}
	}

}

int obtenerMascotasVacunadas(eMascotas mascotas[],int tam)
{
	int contador=0;
	int i;

	for(i=0;i<tam;i++)
	{
		if(mascotas[i].isEmpty==OCUPADO && mascotas[i].vacunado=='s')
		{
			contador++;
		}

	}

	return contador;
}

int obtenerTotalMascotas(eMascotas mascotas[],int tam)
{
	int contador=0;
		int i;

	for(i=0;i<tam;i++)
	{
		if(mascotas[i].isEmpty==OCUPADO)
		{
			contador++;
		}

	}

	return contador;
}

void calcularYMostrarPromedio(eMascotas mascotas[],int tam)
{
	int vacunadas= obtenerMascotasVacunadas(mascotas, tam);
	printf("Vacunadas: %d\n", vacunadas);
	int total= obtenerTotalMascotas(mascotas, tam);
	printf("Totales: %d\n", total);
	float promedio = vacunadas/total;

	printf("El promedio de mascotas vacunadas es: %f\n", promedio);
}


void mascotasPorTipo(eMascotas mascotas[],int tMascotas,eTipo tipos[],int tTipos)
{
	int i;
	int j;

	for(i=0;i<tTipos;i++)
	{
		printf("ID:%d|%s\n\n", tipos[i].id,tipos[i].descripcion);

		for(j=0;j<tTipos;j++)
		{
			if(mascotas[j].idTipo==tipos[i].id)
			{

				MostrarMascota(mascotas[j]);
			}


		}
	}
}

void mostrarPorEdad(eMascotas mascotas[],int tam)
{
	int edad= obtenerMenorEdad(mascotas, tam);

	int i;

	for(i=0;i<tam;i++)
	{
		if(mascotas[i].edad==edad)
		{
			MostrarMascota(mascotas[i]);

		}

	}

}

int obtenerMenorEdad(eMascotas mascotas[],int tam)
{
	int edadObtenida;
	int i;

	for(i=0;i<tam;i++)
	{
		if(mascotas[i].isEmpty==OCUPADO)
		{
			if(i==0 || mascotas[i].edad<edadObtenida)
			{

				edadObtenida=mascotas[i].edad;

			}
		}

	}

	printf("La menor edad obtenida es: %d\n", edadObtenida);

	return edadObtenida;
}

void HardcodearAux(eAux aux[],int tam)
{
	int id[]={5000,5001,5002,5003,5004};
	int contador[]={0,0,0,0,0};

	int i;

	for(i=0;i<tam;i++)
	{
		aux[i].id=id[i];
		aux[i].contador=contador[i];


	}
}

int contarColores(eMascotas mascotas[],int tam, eAux aux[],int taux)
{
	// "Negro","Blanco","Rojo","Gris","Azul"

	int maximo=0;
	int i;
	int c;
	int x;

	for(i=0;i<tam;i++)
	{
		for(c=0;c<taux;c++)
		{

			if(mascotas[i].isEmpty==OCUPADO)
			{
				if(aux[c].id==mascotas[i].idColor)
				{

					aux[c].contador++;
				}

			}

		}
	}



	for(x=0;x<taux;x++)
	{
		if(x==0 || aux[x].contador>maximo)
		{

			maximo=aux[x].contador;
		}



	}

	printf("La maxima cantidad es: %d\n", maximo);


	return maximo;
}

void mostrarColoresMaximos(eMascotas mascotas[],int tMascotas,eColor colores[],int tColores,eAux aux[],int taux)
{
	int max = contarColores(mascotas, tMascotas,aux,taux);

	int i;
	int j;

	for(i=0;i<tColores;i++)
	{
		for(j=0;j<taux;j++)
		{

			if(aux[j].contador== max)
			{
				if(aux[j].id==colores[i].id)
				{
					printf("El maximo pertenece a %s con %d\n", colores[i].nombreColor,max);
				}

			}
		}

	}

}

void elegirColorYTipo(eTipo tipo[],int tTipo,eMascotas mascotas[],int tMascotas,eColor color[],int tColor)
{
	MostrarTipos(tipo, tTipo);
	int idTipo=GetIntParam("Ingrese el id correspondiente para tipo:", 1000, 1004);
	MostrarColores(color, tColor);
	int idColor=GetIntParam("Ingrese el id correspondiente para color:", 5000, 5004);

	printf("Buscando resultados...\n");
	int contador= iniciarContador(mascotas, tMascotas, idColor, idTipo);

	if(contador!=0)
	{
		printf("Se han encontrado %d mascotas con los parametros de busqueda!\n", contador);
	}else printf("No se han encontrado mascotas con los parametros especializados!\n");

}

int iniciarContador(eMascotas mascotas[],int tMascotas,int idcolor,int idtipo)
{
	int i;
	int contador=0;

	for(i=0;i<tMascotas;i++)
	{
		if(mascotas[i].isEmpty==OCUPADO)
		{
			if(mascotas[i].idColor==idcolor && mascotas[i].idTipo==idtipo)
			{
				contador++;
			}
		}

	}


	return contador;
}
