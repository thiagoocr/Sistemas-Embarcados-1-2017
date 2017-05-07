//q2.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){
	int i, tamanho;
	char *comand;
	for(i = 1; i <= argc; i++){

		system(argv[i]);
	}
	return 0;
}
