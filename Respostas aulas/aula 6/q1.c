#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid1,pid2,pid3;
	//pid process pai
	printf("Eu sou o processo pai com id de %d\n", getpid());
	pid1 = fork(); //gerando o primeiro filho
	if(pid1 != 0){
		printf("Eu sou o filho 1 com pid: %d\n", pid1);
		pid2 = fork();
		if(pid2 != 0){
			printf("Eu sou o filho 2 com pid: %d\n", pid2);
			pid3 = fork();		
		}if (pid3 != 0){
			printf("Eu sou o filho 3 com pid: %d\n", pid3);
		}
	}

	return 0;
}
