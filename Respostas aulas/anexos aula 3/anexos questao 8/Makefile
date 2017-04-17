q8: q8.o num_caracs.o
	gcc $(CFLGAS) -o q8 q8.o num_caracs.o
num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS) -c num_caracs.c
q8.o: q8.c num_caracs.h
	gcc $(CFLAGS) -c q8.c
