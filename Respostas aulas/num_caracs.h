//programa num_caracs.h
// int Num_Caracs(char *string);
#ifndef NUM_CARACS_H
#define NUM_CARACS_H


int Num_Caracs(char *string){
	int qtde, i;	
	for(i = 0; string[i] != '\0'; i++){
		if(string[i] == '\0'){
			qtde = i+1;
			break;
		}	
	}
	return qtde;
}

#endif

