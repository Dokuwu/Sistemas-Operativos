#include <fcntl.h>#include <unistd.h>int main(int argc, char* argv[]) {	int fd, leitura;	char buffer[200];	for (int i = 1; i < argc; i++) {		fd = open(argv[i], O_RDONLY);		if (fd == -1) write(STDERR_FILENO, "ficheiro nao existe\n", 20);				while ((leitura = read(fd, buffer, 200)) > 0) {			write(STDOUT_FILENO, buffer, leitura);		}		if (leitura == -1) write(STDERR_FILENO, "Erro na leitura\n", 16);	}	close(fd);	return 0;}