#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv){
	char *nome;
	int tamanho;
	tamanho = sizeof(argv[1]);
	nome = (char*)(malloc(tamanho*sizeof(char)));
	nome = argv[1];
	printf("Ola %s\n", nome);




	return 0;
}
