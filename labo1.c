/* Este programa contendrá lo necesario para el primer lab
 * Integrantes:
 * Brandon Nicolas Fiscal Bustos
 * Nicolas Santiago Moreno Tello
 * Santiago Castro Rojas
 */

/*estás son todas las librerias utilizadas, un detalle importante sobre la libreria math.h es que al final del gcc se debe inluir -lm
 * por lo tanto quedaría algo así:
 * gcc lab.c -o lab.exe -lm */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define VALOR_MAX 10

// a continuación se encuentran todos los prototipos utilizados para la realización de los procesos
void ingreso_datos(char [VALOR_MAX]);
void desviacion_val (int  [VALOR_MAX],float*, float );
void promedio_val (float*,float* ,int [VALOR_MAX] );
char maximo (int [VALOR_MAX], float );
char minimo (int [VALOR_MAX], float );
void nuevo (char[VALOR_MAX]);
void comparacion (char [VALOR_MAX],char [VALOR_MAX], int);
void comparaciones(int[VALOR_MAX],int[VALOR_MAX], float *, int);
void conversion (char[VALOR_MAX],float *,int[VALOR_MAX]);
void conversion2 (char[VALOR_MAX],float *,int[VALOR_MAX]);


/* este es el menú principal y mediante el cual recorreremos todos los sub procesos para el desarrollo del programa principal */
int main()
{
        char valores1[VALOR_MAX];
        int opcion, datos[VALOR_MAX], datos1[VALOR_MAX];
        float desviacion, promedio;
         char valore[VALOR_MAX];
        float  numeros_datos1, cantidad;

        do{
                printf("Bienvenido, por favor elija una de las siguientes opciones:\n\t 1. ingresa valores \n\t 2. mostrar promedio\n\t 3.mostrar desviacion estandar \n\t 4.mostrar valores max y min\n\t 5. mostrar todo\n\t 6. comparar cadenas \n\t 7 ingresar segunda cadena \n\t 8. comparaciones \n\t 9. salir\n\t");
                printf("elige opción:\n");
                scanf("%d", &opcion);
                switch (opcion){
                        case 1:
                                ingreso_datos(valores1);
                //              printf("se aceptó correctamente\n %s \n", valores1);
                                break;
                        case 2:
                                printf("se calcula promedio\n");
                                conversion (valores1,&cantidad, datos);
                                promedio_val(&promedio, &cantidad, datos);
                                break;
                        case 3:
        //                      printf("esto debe entrar %ls \n\t", datos);
                                conversion (valores1,&cantidad, datos);
                                desviacion_val(datos, &desviacion, cantidad);
                //              printf("obtenemos \n %ls",desviacion);
                                break;
                        case 4:
                                conversion (valores1,&cantidad, datos);
			       	maximo (datos, cantidad);
                                minimo (datos, cantidad);
                                break;
                        case 5:
                                 printf("mostrar todo\n");
				 conversion (valores1,&cantidad, datos);
                                 promedio_val(&promedio, &cantidad, datos);
                                 desviacion_val(datos, &desviacion, cantidad);
                                 maximo (datos, cantidad);
                                 minimo (datos, cantidad);
                                break;
                        case 6:
                                printf("comparacion\n");
                                conversion (valores1,&cantidad, datos);
                                comparacion (valore, valores1, numeros_datos1);
                                break;
                        case 7:
                                printf("valor nuevo\n");
                                nuevo(valore);
                                conversion2 (valore,&numeros_datos1, datos1);
                                break;
                        case 8:
                                conversion (valores1,&cantidad, datos);
                                comparaciones(datos,datos1, &cantidad, numeros_datos1);

                                 break;
                }
         }while(opcion != 9);
}


/* a partir de aquí se encuentran los sub procesos*/

// aquí recibiremos los datos
void ingreso_datos(char valores1[VALOR_MAX]){


        printf("Por favor, ingrese los valores con el siguiente formato: 1;2;3;4;5;... \n");
        scanf("%s",valores1);

}

//aquí se calcula la desviación estándar

void desviacion_val(int  datos[VALOR_MAX], float *desviacion, float  cantidad)

{
        int medio=VALOR_MAX/2;
        int cont,val[medio];
        int valores[VALOR_MAX];
        int pot[5];
        float div, desvi,acum=0, prom=0;
//      printf("entra esto \n %ls",datos);
        for (cont=0;cont<medio;cont ++)
        {
                val[cont] = datos[cont];
        //      printf("contenido: \n %d \n", val[cont]);
                prom=val[cont]+prom;
        //      printf("acumulado: %f \n", prom);

        }
        prom=prom/cantidad;
//      printf("promedio es: %5.3f \n", prom);

        for (cont=0;cont<medio;cont++){
                pot[cont]=pow((datos[cont]-prom),2);
        //      printf("potencia #%d da: %d", cont, pot[cont]);
                acum=pot[cont]+acum;
        }


       // printf("acum: %5.3f \n", acum);
         div=acum/cantidad;
        // printf("div: %5.3f \n", div);
         desvi=sqrt(div);
         printf("desviacion: %5.3f \n", desvi);
        *desviacion=desvi;
        return;
}

//Se encuentra el calculo del promedio

 void promedio_val(float* promedio,float* cantidad, int datos[VALOR_MAX]){
        float p=*promedio;
        int contador=0;
        int c=*cantidad;
        p=0;

        for (contador=0 ; contador<c; contador++){
        p=p+datos[contador];
        }
        p=p/c;
        printf("El promedio es: %0.3f \n",p);  
        *promedio=p;                          /* Guardar en una posición de memoria.*/

}

//hallamos el valor minimo

char minimo (int datos[VALOR_MAX], float cantidad)

{
  int i, val[VALOR_MAX], dato[VALOR_MAX/2], cont, cosito;
  int min,medio;
        medio=VALOR_MAX/2;
         for (cont=0;cont<medio;cont ++)
        {
                val[cont]=datos[cont];
        //      printf("contenido: \n %d \n", val[cont]);
        //      printf("prueba");
             // printf("contenido: \n %d \n", val[cont]);
             // printf("dato %d: %d \n",cont, dato[cont]);


        //       printf("contenido: \n %d \n", val[cont]);
        //       printf("dato %d: %d \n",cont, dato[cont]);
        }

cosito=cantidad;
//printf("aquí está tu cosito: %d\n", cosito);
  min = val[0];
// printf("aquí está tu dato prueba %d\n", min);
  for (i = 0; i <cosito ; i++){
//        printf("rastreo: %d \n dato: %d \n", min,val[i]);
    if (val[i] < min){
          min = val[i];
//        printf("dato: %d\n", min);
    }
  //  printf("prueba: %d\n", i);
  }
  printf("aquí está tu valor minimo: %d\n", min);
  return (min);
}

//hallamos el valor máximo

char maximo (int datos[VALOR_MAX], float cantidad)
{
  int i, val[VALOR_MAX], dato[VALOR_MAX/2], cont, cosito;
  int max, medio=VALOR_MAX/2;

         for (cont=0;cont<medio;cont ++)
        {
            dato[cont] = datos[cont];
                //         printf("contenido: \n %d \n", val[cont]);
                //         printf("dato %d: %d \n",cont, dato[cont]);

        //       printf("contenido: \n %d \n", val[cont]);
        //       printf("dato %d: %d \n",cont, dato[cont]);
        }

cosito=cantidad;
//printf("aquí está tu cosito: %d\n", cosito);
  max = dato[0];
// printf("aquí está tu dato prueba %d\n", max);
  for (i = 0; i <cosito ; i++){
//        printf("rastreo: %d \n dato: %d \n", min,dato[i]);
    if (dato[i] > max){
          max = dato[i];
     //     printf("dato: %d\n", max);
    }
   // printf("prueba: %d\n", i);
  }
  printf("aquí está tu valor maximo %d\n", max);
  return (max);
}

//aquí recibimos los valores de la segunda cadena

void nuevo (char valore[VALOR_MAX])
{
       printf("por favor ingrese los numeros de la cadena.\n\n");
       scanf("%s",valore);
}

// aquí convertimos los valores de la segunda cadena

void  conversion2 (char valore[VALOR_MAX], float * numeros_datos1, int datos1[VALOR_MAX])
{

  float numero_dat;
  int contador = 0;
  int contador1 = 0;
  int posicion = 0;
  char destino[VALOR_MAX];

  for(contador=0;contador<=strlen(valore)+1;contador++)
        {
                if(valore[contador]==';'|| valore[contador]=='\0')
                {
                        datos1[posicion]=atoi(destino);
                        posicion=posicion+1;

                        for (contador1=1; contador1<VALOR_MAX; contador1++){
                        destino[contador1]='\0';
                }
                contador=contador+1;
                contador1=0;
                }
                destino[contador1]=valore[contador];
        contador1=contador1+1;
        }
        numero_dat=posicion;
  if (numero_dat<=100)
  {
        *numeros_datos1=numero_dat;
  }

}

// se realiza la conversión de la primer cadena de carácteres

void comparacion (char valore[VALOR_MAX],char valores1[VALOR_MAX], int numeros_datos1)
{
   int i;
   int max =2*numeros_datos1;


        for (i=0;i<max;i++)
        {
          if(valore[i]==valores1[i])
                 {
                       printf("\tlos caracteres son iguales\n");

                 }

                  else if(valore[i]<valores1[i])
                    {
                       printf("\tla primer cadena es mas grande\n");
                    }
          else
          {
                  printf("\tla segunda cadena es mas grande\n");
          }
        }
}

//se compara la suma  total de las cadenas de carácteres


void comparaciones( int datos[VALOR_MAX],int datos1[VALOR_MAX],float *cantidad,int numeros_datos1 )
{


        int suma=0;
        int suma1=0;
        int contador=0;
        int contador1=0;
        int c=*cantidad/2;
        int var2= numeros_datos1;

        printf("valor c: %d",c);

        for (contador=0 ; contador<c; contador++){
        suma=suma+datos[contador];
      
        }
      


        for (contador1=0 ; contador1<var2; contador1++){
        suma1=suma1+datos1[contador1];
      

        }
      


        if(suma==suma1){

                printf("Son iguales\n");

        }

        else if (suma>suma1){

                printf("el segundo vector es mayor\n");


        }

        else{

                printf("El primer vector es mayor\n");
        }

}

// se realiza la conversión de los valores ASCII a entero mediante la función atoi

void conversion (char valores1[VALOR_MAX],float * cantidad, int datos[VALOR_MAX] )
{

  float numero_dat;
  int contador = 0;
  int contador1 = 0;
  int posicion = 0;
  char destino[VALOR_MAX];

  for(contador=0;contador<=strlen(valores1)+1;contador++)
        {
                if(valores1[contador]==';'|| valores1[contador]=='\0')
                {
                        datos[posicion]=atoi(destino);
                        posicion=posicion+1;

                        for (contador1=1; contador1<VALOR_MAX; contador1++){
                        destino[contador1]='\0';
                }
                contador=contador+1;
                contador1=0;
                }
                destino[contador1]=valores1[contador];
        contador1=contador1+1;
        }
        numero_dat=posicion;
  if (numero_dat<=100)
  {
        *cantidad=numero_dat;
  }
}
