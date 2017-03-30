#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int qtde;
	char *nome;
	int tamanho = 0;
	int i;
	
	qtde = argc;
	for(i = 0; i < qtde; i++){
		tamanho += sizeof(argv[i]);
	}
	nome = (char*)(malloc(100*sizeof(char)));
	for(i = 0; i < argc; i++){
		nome = argv[i];
		printf("%s ", nome);
	}
	printf("\n");

	//printf("sizeof das entradas = %d\n", tamanho);
	printf("Numero de entrada = %d\n", qtde);




	return 0;
}
