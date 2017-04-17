//main_q3.c
#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int main(int argc, char *argv[]){
	char *string;
	int tamanho;
	
	string = malloc(100*sizeof(char));
	//scanf("%s", string);	
	print_argumento(argv, argc);		
	tamanho = count_caracter(argv);
	printf("Numero de caracteres: %d\n", tamanho);
	

	return 0;	
	
}
