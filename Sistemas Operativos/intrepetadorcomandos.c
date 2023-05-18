#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
int main(int argc, char* argv[]) {
	//Declara��o de variaveis.
	char comando[200];
	int pid; //Variavel para receber o valor do fork
	char* strptr; //Variavel do tipo pointer para array de caracteres, para usar com o strtok_r, onde a sua fun��o vai ser para armazenar o proximo texto a ler.
	write(STDOUT_FILENO, "%", 1);
	// While loop, onde se for escrito sair, � encerrado o programa, caso contrario � executado o comando, caso ele exista.
	while (strcmp(fgets(comando, sizeof(comando), stdin), "termina\n") != 0)
	{
		// Retirar o \n do comando inserido.
		comando[strlen(comando) - 1] = '\0';
		int i = 0;
		//Usando o strtok_r conseguimos repartir tudo o que foi inserido pelo caractere " " (espa�o) e assim executar o comando pedido e os seus argumentos passados.
		char* token = strtok_r(comando, " ", &strptr);
		while (token != NULL && argc < 10)
		{
			argv[i] = token;
			token = strtok_r(NULL, " ", &strptr);
			i++;
		}
		// � terminado o seguinte valor da array argv[i] para null, assim n�o � lido lixo.
		argv[i] = NULL;
		//Criado o processo para executar o comando pretendido.
		pid = fork();
		//Caso pid retorne 0, significa que o processo filho foi criado e ir� ser executado o comando.
		if (pid == 0)
		{
			//Verificamos se a funcao execv, consegue executar o comando, caso o comando nao exista, ir� ser apresentada uma mensagem de erro ao utilizador. Caso contrario � executado o comando.
			execv(argv[0], argv);
			perror("execv failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
		write(STDOUT_FILENO, "%", 1);
	}
	return 0;
}