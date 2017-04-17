//mylib.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mylib(char **argumento, int index){
	int i, j;
	int tamanho;
	i = 0; j = 0;
	
	for(j = 0; j < index; j++){
		tamanho = strlen(argumento[j]);
		printf("Argumento: %s / Numero de caracteres: %d\n", argumento[j], tamanho);
	}		
}
