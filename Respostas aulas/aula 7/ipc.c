#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX 300

int main(){
	int fd[2];
	pid_t pid;

	
	if(pipe(fd) < 0){
		fprintf(stderr, "pipe error\n");
		exit(1);
	}
	if(pid < 0){
		fprintf(stderr, "Failed Process\n");
	}
	//close(fd[0])  = fecha o descritor LEITURA
	//close(fd[1])  = fecha o descritor ESCRITA
	pid = fork();
	if(pid > 0){ //processo pai
		printf("Processo pai criado, ID = %d\n", getpid());
		close(fd[1]); //o pai vai ler o filho
		char strcp[MAX];
		read(fd[0], strcp, sizeof(strcp) + 1);
		printf("Envio do filho: %s\n", strcp);
	}else{  //processo filho
		printf("Processo filho criado, ID = %d\n",  getpid());
		close(fd[0]);
		char strsend[MAX] = "I am the child";
		write(fd[1], strsend, sizeof(strsend));

	}
	

	return 0;
}



/*
	FILHO: Pai, qual é a verdadeira essência da sabedoria?
	PAI: Não façais nada violento, praticai somente aquilo que é justo e equilibrado.
	FILHO: Mas até uma criança de três anos sabe disso!
	PAI: Sim, mas é uma coisa difícil de ser praticada até mesmo por um velho como eu...
*/