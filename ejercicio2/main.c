#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ejercicio2.h"
#include "tad.h"
#include "tipo_elemento.h"


int validacion(){

    char dato[50];
    int i = 0;

    while(fgets(dato, sizeof(dato), stdin) == NULL){
        printf("Por favor ingrese un numero: ");
    };

    if(dato[i] == '-'){
        i++;
    };

    while(!isdigit(dato[i])){
        printf("Ingrese unicamente un numero: ");
        i = 0;
        fgets(dato, sizeof(dato), stdin);
    };

    int num = atoi(dato);
    return num;
};

int main(){

    int clave;

    Pila pila = p_crear();

    cargar_pila(&pila);

    int opcion;

    do{
        printf("\n--------------MENÚ DE OPCIONES----------------\n");
        printf("1.Valores de la Pila\n");
        printf("2.Buscar un valor de la Pila\n");
        printf("3.Insertar un nuevo elemento\n");
        printf("4.Eliminar un elemento\n");
        printf("5.Intercambiar dos valores con su posición ordinal\n");
        printf("6.Duplicar contenido de la Pila\n");
        printf("7.Contar elementos de una Pila\n");
        printf("9.Salir\n");
        printf("\n\nIntroduzca una opción(1-9): ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                p_mostrar(pila);
                break;
            case 2:
                //buscar
                printf("Elemento que desea buscar.");
                clave = validacion();
                buscar(&pila, clave);
                break;
            case 3:
                //insertar
                printf("Posicion del nuevo elemento.");
                int pos = validacion();
                printf("Valor del nuevo elemento.");
                int elemento = validacion();
                insertar(&pila, pos, elemento);
                break;
            case 4:
                //eliminar
                printf("Elemento a eliminar.");
                clave= validacion();
                eliminar(&pila, clave);
                break;
            case 5:
                //intercambiar
                printf("Posicion 1.");
                int pos1 = validacion();
                printf("Posicion 2.");
                int pos2 = validacion();
                intercambiar(&pila, pos1, pos2);
                break;
            case 6:
                //duplicar
                duplicar(&pila);
                break;
            case 7:
                //contar_elementos
                printf("contando...");
                int cant = contar(&pila);
                printf("Cantidad de elementos de la pila: %d",cant);
                break;
        }
    }while (opcion != 9);

    return 0;
};
