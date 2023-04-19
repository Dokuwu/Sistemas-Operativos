#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	// declaração variáveis
	int file1, leitura, linhas= 0, resultado;
	char buffer[200];
	
	// Abertura do ficheiro file1, conforme o que é recebido nos argumentos
	// O Ficheiro é aberto apenas em modo de leitura.
	file1 = open(argv[1], O_RDONLY);
	
	// Caso a função open retorne -1, significa que o ficheiro não foi encontrado
	// E assim é dado uma mensagem de erro para o utilizador.
	if (file1 == -1)
	{
		write(STDERR_FILENO, "O ficheiro nao existe.\n", 24);
		return 0;
	}
	
	else
	{
	
	// Criado um while loop, que enquanto a variavel leitura receber da função read
	// algum um valor > 0, o que significa que ainda tem texto para ler
	// É criado um for loop que vai verificar por cada caracter até chegar a um
	// "\n" e faz a sua contagem. Assim conseguimos obter o numero de linhas existentes
	// Num ficheiro.
	while((leitura = read(file1,buffer,200)) >0)
	{
		for (int i = 0; i < leitura; i++)
		{
			if (buffer[i] == '\n')
			{
				linhas++;
			}
		}
	}
	// Usado a função sprintf() para formatar a variavel string resultado com 
	// o valor obtidos das linhas do ficheiro.
	resultado = sprintf(buffer, "%d\n", linhas);
	write(STDOUT_FILENO, buffer, resultado);
	return 1;
	}
	close(file1);
	return 0;
}

