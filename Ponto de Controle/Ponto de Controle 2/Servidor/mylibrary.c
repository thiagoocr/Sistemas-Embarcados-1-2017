#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>


void liga_led(){
	char choose;	
	
	printf("Digite a opcao desejada:  \n");
	printf("\t1. Mudar o estado atual(S)\n");
	printf("\t2. Ligar lâmpada(Y)\n");
	printf("\t3. Desligar lâmpada(N)\n");	
	scanf("%c", &choose);
	

	//variavel pra saber o estado	
	int on = 0;	
	if(choose == 'S'){
		if(on == 0){
			while(1){			
				digitalWrite(0, 1);
			}		
		}else{
			while(1){
				digitalWrite(0,0);
			}
		}	
	
	
	}else if(choose == 'Y'){
		while(1){
			digitalWrite(0,1);
			on = 1;		
		}	
	}else if(choose == 'N'){
		while(1){
			digitalWrite(0, 0);
			on = 0;		
		}
	}else{
		while(choose != 'Y' || choose != 'N' || choose != 'S'){
			printf("Escolha uma opção valida (S/Y/N): ");
			scanf("%c", &choose);
		}		
	} 



}

