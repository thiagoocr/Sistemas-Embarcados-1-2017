#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <unistd.h>

	void conexao_server(char* a);
	void print_exemplo(void);
	void sensores(void);
	void menu1(void);

	char IP_Servidor[] = "192.168.25.25";
	int socket_id;
	struct sockaddr_in servidorAddr;
	int length;
	unsigned short servidorPorta = 9000;
	char mensagem[] = "oii";
	

int main (int argc, char* const argv[])
{
	menu1();
	return 0;
}

void conexao_server(char* a)
{ char* text;
//	printf(stderr, "Abrindo o socket para o cliente... ");
	socket_id = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(socket_id < 0)
	{
		fprintf(stderr, "Erro na criacao do socket!\n");
		exit(0);
	}
	fprintf(stderr, "Feito!\n");

	fprintf(stderr, "Conectando o socket ao IP %s pela porta %d... ", IP_Servidor, servidorPorta);
	memset(&servidorAddr, 0, sizeof(servidorAddr)); // Zerando a estrutura de dados
	servidorAddr.sin_family = AF_INET;
	servidorAddr.sin_addr.s_addr = inet_addr(IP_Servidor);
	servidorAddr.sin_port = htons(servidorPorta);
	if(connect(socket_id, (struct sockaddr *) &servidorAddr,sizeof(servidorAddr)) < 0)
	{
		fprintf(stderr, "Erro na conexao!\n");
		exit(0);
	}
	fprintf(stderr, "Feito!\n");

	fprintf(stderr, "Mandando mensagem ao servidor... ");
	length = strlen(a) + 1;
	write(socket_id, &length, sizeof(length));
	write(socket_id, a, length);
	fprintf(stderr, "Feito!\n");
	sleep(1);

	text = (char*) malloc (length);
	read(socket_id, &length, sizeof (length));
	read(socket_id, text, length);
	fprintf(stderr,"\n\n   Mensagem = %s\n\n", text);
	free (text);
	sleep(5);


	fprintf(stderr, "Fechando o socket local... ");
	close(socket_id);
	fprintf(stderr, "Feito!\n");
	system("clear");
}


void print_exemplo()
{
		puts("   Este programa cria um cliente que se comunica");
		puts("   a um servidor TCP/IP na porta especificada");
		puts("   pelo usuario. Para permitir que o cliente comunique-se");
		puts("   com este servidor, o servidor deve ser");
		puts("   executado inicialmente com uma porta definida,");
		puts("   e o cliente devera ser executado em outra");
		puts("   janela ou em outra aba do terminal, utilizando");
		puts("   a mesma porta. O servidor escreve na tela");
		puts("   todo texto enviado pelo cliente. Se o cliente");
		puts(" f  transmitir o texto \"sair\", o servidor se");
		puts("   encerra. Se o usuario pressionar CTRL-C para");
		puts("   o servidor, ele tambem se encerra.");
		puts("   encerra.");
		puts("   Modo de Uso:");
		printf("       <IP do Servidor> <Porta do servidor> <Mensagem>\n");
		printf("   Exemplo: 127.0.0.1 8000 \"Ola socket\"\n");
		exit(1);
}

void sensores(void)
{ 
	char *a;
	char parametro;
	 do
    {
        printf("\n\tSensores\n\n");
        printf("1. sala\n");
        printf("2. quarto\n");
        printf("3. cozinha\n");
        printf("0. voltar ao menu anterior\n");

        scanf("%c", &parametro);
        system("clear");

        switch(parametro)
        {
            case '1':
            	//scanf("%c",a);
            a = "zizi";
                conexao_server(a);
                break;

            case '2':
                a = "oziel";
                conexao_server(a);
                break;

            case '3':
                
                break;

            case '0':
                menu1();
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(parametro);
}

void menu1(void)
{
char parametro;

	//if(argc = 1)
	//	print_exemplo();
	 do
    {
        printf("\n\t Menu de Opções\n\n");
        printf("1. Sensores\n");
        printf("2. Tomadas\n");
        printf("3. Câmera\n");
        printf("0. Sair\n");


        scanf("%c", &parametro);
        system("clear");

        switch(parametro)
        {
            case '1':
                sensores();
                break;

            case '2':
                printf("caso 2/\n");
                break;

            case '3':
                printf("caso 3\n");
                break;

            case '0':
                exit(0);
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(parametro);
}