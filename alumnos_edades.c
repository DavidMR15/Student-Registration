#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

void registrar_alumno(char nombre[30],int edad){
	FILE* us;
	FILE* ed;
	us=fopen("usuarios.txt","a");
	ed=fopen("edades.txt","a");
	srand(time(NULL));
	int contrasena=rand()%5000+1000;
	printf("La contrasena del usuario %s es %d\n",nombre,contrasena);
	fprintf(us,"%s %d\n",nombre,contrasena);
	fprintf(ed,"%d\n",edad);
	fclose(us);
	fclose(ed);
}
void mostrar_usuarios(char nombre[30],int contrasena){
	FILE* us;
	FILE* ed;
	us=fopen("usuarios.txt","r");
	ed=fopen("edades.txt","r");
	char posiblenom[30];
	int posiblecontra,edad,entro=0;
	while(feof(us)==0){
		fscanf(us,"%s",posiblenom);
		fscanf(us,"%d",&posiblecontra);
		if((strcmp(posiblenom,nombre)==0)&&(posiblecontra==contrasena)){
			fclose(us);
			us=fopen("usuarios.txt","r");
			while (!feof(us)&!feof(ed)){
				fscanf(us,"%s",posiblenom);
				if(!isdigit(posiblenom[0])){
					printf("%s ",posiblenom);
            		fscanf(ed,"%d",&edad);
            		printf("%d\n",edad);	
				}
			}
			entro=1;
			break;
		}
	}
	if(entro==0){
		printf("usuario o contrasena incorrecta\n");
	}
	fclose(us);
	fclose(ed);
}
void ordenar_arreglo(int arr[],int tam){
	int i,j;              
	int temp=0;             

	for (i=1;i<tam;i++){
       for (j=0; j < tam-i ;j++){
          if (arr[j] > arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
          }
       }
	}
	for(i=0;i<tam;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void mostrar_edades(char nombre[30],int contrasena,int cant){
	FILE* us;
	FILE* ed;
	us=fopen("usuarios.txt","r");
	ed=fopen("edades.txt","r");
	char posiblenom[30];
	int posiblecontra,edad,entro=0;
	int edades[cant];
	while(feof(us)==0){
		fscanf(us,"%s",posiblenom);
		fscanf(us,"%d",&posiblecontra);
		if((strcmp(posiblenom,nombre)==0)&&(posiblecontra==contrasena)){
			int i=0;
			while(!feof(ed)){
				fscanf(ed,"%d",&edad);
				edades[i]=edad;
				i++;
			}
			ordenar_arreglo(edades,cant);
			entro =1;
			break;
		}
	}
	if(entro==0){
		printf("usuario o contrasena incorrecta\n");
	}
	fclose(us);
	fclose(ed);
}
void menu(){
	printf("-----Menu-----\n1.Registrar Usuario\n2.Mostrar Usuarios\n3.Mostrar edades ordenadas\n4.Salir\nElige una opcion:");
}
int main(){
	char nombre[30];
	int edad,contrasena,cant,selector,salir=0;
	
	while(salir==0){
		menu();
		scanf("%d",&selector);
	switch(selector){
		case 1:
			printf("Escribe el nombre del usuario\n");
			scanf("%s",nombre);
			printf("Escribe la edad del usuario\n");
			scanf("%d",&edad);
			registrar_alumno(nombre,edad);
			break;
		case 2:
			printf("Escribe el nombre del usuario\n");
			scanf("%s",nombre);
			printf("Escribe la contrasena del usuario\n");
			scanf("%d",&contrasena);
			mostrar_usuarios(nombre,contrasena);
			break;
		case 3:
			printf("Escribe el nombre del usuario\n");
			scanf("%s",nombre);
			printf("Escribe la contrasena del usuario\n");
			scanf("%d",&contrasena);
			printf("Escribe la cantidad de usuarios\n");
			scanf("%d",&cant);
			mostrar_edades(nombre,contrasena,cant);
			break;
		case 4:
			salir++;
			break;
		default:
			printf("Opcion Incorrecta\n");
			break;
	}	
	}
	return 0;
}
