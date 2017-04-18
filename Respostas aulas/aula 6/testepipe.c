#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	int fd[2], n;
	char line[100];
	pid_t pid;
	
	if(pipe(fd) < 0){
		fprintf(stderr, "pipe error\n");
		exit(1);
	}
	if( (pid = fork()) < 0){
		fprintf(stderr, "Fork error\n");
		exit(2);
	}
	else if(pid > 0){
		close(fd[0]);
		write(fd[1], "Hello world\n", 12);

	}else{
		close(fd[1]);
		n = read(fd[0], line, 100);
		write(STDOUT_FILENO, line, n);
		printf("Nada\n");
	}
	exit(0);

	return 0;
}
