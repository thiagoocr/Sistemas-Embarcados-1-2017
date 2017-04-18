//compila com
//gcc pthread.c -o pthread -lpthread
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

pthread_t tid[2];

void* doSomeThing(void *arg){
	unsigned long i = 0;
	pthread_t id = pthread_self();
	if(pthread_equal(id, tid[0])){
		printf("\nFirst thread processing\n");
	}else{
		printf("Second thread processing\n");
	}
	for(i = 0; i < (0xFFFFFFFFF); i++);
	return NULL;
}

int main(){
	/*int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void *(*start_rtn)(void), void *restrict arg)	
    The first argument is a pthread_t type address. Once the function is called successfully, the variable whose address is passed as first argument will hold the thread ID of the newly created thread.
    The second argument may contain certain attributes which we want the new thread to contain.  It could be priority etc.
    The third argument is a function pointer. This is something to keep in mind that each thread starts with a function and that functions address is passed here as the third argument so that the kernel knows which function to start the thread from.
    As the function (whose address is passed in the third argument above) may accept some arguments also so we can pass these arguments in form of a pointer to a void type. Now, why a void type was chosen? This was because if a function accepts more than one argument then this pointer could be a pointer to a structure that may contain these arguments.
	*/
	/*
    pthread_t pthread_self(void);
    So we see that the function ‘pthread_self()’ is used by a thread for printing its own thread ID.
	*/

	int i = 0;
	int err;
	while(i < 2){
		err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
		if(err  != 0){
			printf("\ncan't create thread: [%s]", strerror(err));
		}else{
			printf("Trhead created successfuly\n");
		}
		i++;
	}
	sleep(5);
	return 0;
}