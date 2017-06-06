// Servidor Local
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <signal.h>
#include <wiringPi.h>
#include <mcp3004.h>

int socket_id;
void sigint_handler(int signum);
void print_client_message(int client_socket);
void end_server(void);
void sensores(char *sensor,int n_socket);

int main (int argc, char* const argv[])
{
	unsigned short servidorPorta;
	struct sockaddr_in servidorAddr;
    wiringPiSetup() ;
    mcp3004Setup(100, 0);

	if (argc < 2)
	{
		puts("   Este programa cria um servidor TCP/IP ");
		puts("   conectado a porta especificada pelo usuario.");
		puts("   Para permitir que o cliente comunique-se");
		puts("   com este servidor, o servidor deve ser");
		puts("   executado inicialmente com uma porta definida,");
		puts("   e o cliente devera ser executado em outra");
		puts("   janela ou em outra aba do terminal, utilizando");
		puts("   a mesma porta. O servidor escreve na tela");
		puts("   todo texto enviado pelo cliente. Se o cliente");
		puts("   transmitir o texto \"sair\", o servidor se");
		puts("   encerra. Se o usuario pressionar CTRL-C,");
		puts("   o servidor tambem se encerra.");
		puts("   encerra.");
		puts("   Modo de Uso:");
		printf("      %s <Numero da porta>\n", argv[0]);
		printf("   Exemplo: %s 8080\n", argv[0]);
		exit(1);
	}
	servidorPorta = atoi(argv[1]);

	fprintf(stderr, "Definindo o tratamento de SIGINT... ");
	signal(SIGINT, sigint_handler);
	fprintf(stderr, "Feito!\n");
	
	fprintf(stderr, "Abrindo o socket local... ");
	socket_id = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socket_id < 0)
	{
		fprintf(stderr, "Erro na criacao do socket!\n");
		exit(0);
	}
	fprintf(stderr, "Feito!\n");

	fprintf(stderr, "Ligando o socket a porta %d... ", servidorPorta);
	memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servidorAddr.sin_port = htons(servidorPorta);
	if(bind(socket_id, (struct sockaddr *) &servidorAddr, sizeof(servidorAddr)) < 0)
	{
		fprintf(stderr, "Erro na ligacao!\n");
		exit(0);
	}
	fprintf(stderr, "Feito!\n");

	fprintf(stderr, "Tornando o socket passivo (para virar um servidor)... ");
	if(listen(socket_id, 10) < 0)
	{
		fprintf(stderr, "Erro!\n");
		exit(0);
	}
	fprintf(stderr, "Feito!\n");

	while(1)
	{
		int socketCliente;
		struct sockaddr_in clienteAddr;
		unsigned int clienteLength;

		fprintf(stderr, "Aguardando a conexao de um cliente... ");
		clienteLength = sizeof(clienteAddr);
		if((socketCliente = accept(socket_id, (struct sockaddr *) &clienteAddr, &clienteLength)) < 0)
			fprintf(stderr, "Falha no accept().\n");
		fprintf(stderr, "Feito!\n");
		
		fprintf(stderr, "Conexão do Cliente %s\n", inet_ntoa(clienteAddr.sin_addr));
		
		fprintf(stderr, "Tratando comunicacao com o cliente... ");

		menu(socketCliente);

		fprintf(stderr, "Feito!\n");

		fprintf(stderr, "Fechando a conexao com o cliente... ");
		close(socketCliente);
		fprintf(stderr, "Feito\n");
	}
	return 0;
}



void menu(int client_socket)
{	
    int n_socket = client_socket;	
	int length;
	char* rx;
	char buffer[5];
    int valor =analogRead(100+0);

 	fprintf(stderr, "\nMensagem enviada pelo cliente tem ");

	read(client_socket, &length, sizeof (length));
	fprintf(stderr, "%d bytes.", length);
	rx = (char*) malloc (length);

	read(client_socket, rx, length);
	fprintf(stderr,"\n\n   Mensagem = %s\n\n", rx);
	//free (text);
	sleep(1);

	fprintf(stderr, "Mandando mensagem ao cliente... ");

    snprintf(buffer,5, "%d",valor);

    sleep(2);

    length = strlen(buffer) + 1;
	write(client_socket, &length, sizeof(length));
	write(client_socket, buffer, length);
	fprintf(stderr, "Feito!\n");
    
    int valor_menu = atoi(rx);

	if  (valor_menu == 1)
	{
		quarto(client_socket);
	}
	if  (valor_menu == 2)
	{
		quarto(param_envio);
	}
	
     
        free(rx);
} 


void quarto(int* client_socket)
{
	read(client_socket, &length, sizeof (length));
	fprintf(stderr, "%d bytes.", length);
	rx = (char*) malloc (length);
	int valor = atoi(rx);

	if (valor == 1)
		tomadas(1);
	if (valor == 2)
		sensores(client_socket)
		break;
}









void sensores(char* sensor,int n_socket)

{
	fprintf(stderr,"Estou em sensores inicio da função");
    int length;
	char* rx;

	int client_socket = n_socket;
		while(1)
		{
	        int socketCliente;
		    struct sockaddr_in clienteAddr;
		    unsigned int clienteLength;
            int valor_menu;
					
			clienteLength = sizeof(clienteAddr);
			if((socketCliente = accept(socket_id, (struct sockaddr *) &clienteAddr, &clienteLength)) < 0)
				fprintf(stderr, "Falha no accept().\n");

			read(client_socket, &length, sizeof (length));
	        

		
			rx = (char*) malloc (length);
            read(client_socket, rx, length);
			valor_menu = atoi(rx);
            fprintf(stderr,"o opção foi %d",valor_menu);

    //         if (valor_menu == 1)
				// {
				// 	fprintf(stderr, "Cliente pediu para o servidor fechar.\n");
    //                 fprintf(stderr, "estou em sensores. \n");
				// 	end_server();
				// }

			
			
		}
}

void sigint_handler(int signum)
{
	fprintf(stderr, "\nRecebido o sinal CTRL+C... vamos desligar o servidor!\n");
	end_server();
}


void end_server(void)
{
	fprintf(stderr, "Fechando o socket local... ");
	close(socket_id);
	fprintf(stderr, "Feito!\n");
	exit(0);
}