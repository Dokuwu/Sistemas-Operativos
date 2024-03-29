#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	int fd, copia, leitura;
	char buffer[200];
///O OBJETIVO ERA PARA CRIAR POR EXEMPLO OLA.COPIA E NAO FICHEIRO.COPIA
  
	copia = open("ficheiro_copia.txt", O_WRONLY);

	if (copia == -1) {
		write(STDERR_FILENO, "Ficheiro de copia não existe, foi criado no diretorio.\n", 55);
		copia = open("ficheiro_copia.txt", O_CREAT, S_IRUSR | S_IWUSR);
	}

	for (int i = 1; i < argc; i++) {
		fd = open(argv[i], O_RDONLY);

		if (fd == -1) write(STDERR_FILENO, "ficheiro nao existe\n", 20);

		while ((leitura = read(fd, buffer, 200)) > 0) {
			write(copia, buffer, leitura);
		}

		if (leitura == -1) write(STDERR_FILENO, "Erro na leitura\n", 16);

	}

	close(fd);
	close(copia);

	return 0;
}
