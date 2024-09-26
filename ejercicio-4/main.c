#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
#include "ejercicio-4.h"

void validaciones (int *num, int *base){
    int resultado;
    char c;

    do {
        if(scanf("%c",&c)){
        printf("Entrada no válida.Introduce un número decimal:\n");
        while ((c = getchar()) != '\n' && c != EOF);

        }
    }while(scanf("%d", num) == 0);

    do {
        printf("Introduce un número para la base (entre 2 y 16): ");
        resultado = scanf("%d", base);

        if (resultado == 0 || *base < 2 || *base > 16) {
            printf("\nBase inválida. La base debe estar entre 2 y 16.\n");
            while (fgetc(stdin) != '\n');
        }
    } while (resultado == 0 || *base < 2 || *base > 16);

}


int main()
{
    Pila P1 = p_crear();
    int num ,base;
    printf("Introduce un número decimal: ");
    validaciones(&num,&base);
    conversion(num,P1,base);
}
