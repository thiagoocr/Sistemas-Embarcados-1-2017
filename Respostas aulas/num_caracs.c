#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int main(){
	

	char *nome;
	nome = (char*)(malloc(100*sizeof(char)));
	gets(nome);
	int qtde;
	qtde = Num_Caracs(nome);
	printf("%d\n", qtde);


	return 0;
}
