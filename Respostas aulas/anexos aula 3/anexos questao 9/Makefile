q9 : q9.o mylib.o
	gcc $(CFLAGS)  -o q9 q9.o mylib.o
mylib.o : mylib.c mylib.h
	gcc $(CLAGS) -c mylib.c
q9.o : q9.c mylib.c mylib.h
	gcc $(CFLAGS) -c q9.c 
