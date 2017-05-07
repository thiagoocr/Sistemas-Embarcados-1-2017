#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main (char argc, char *argv[]) {
	
	
pid_t pid = fork();
	if (pid == 0)
	{
		execl(argv[1],argv[2],NULL);
	}
      sleep(2);
      printf("Eu sou o pai e finalmente posso continuar\n");
}
