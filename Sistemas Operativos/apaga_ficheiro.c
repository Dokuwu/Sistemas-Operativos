#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int file1;
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
	{
		write(STDERR_FILENO, "O ficheiro nao existe.\n", 24);
	}
	else
	{
		unlink(argv[1]);
		write(STDOUT_FILENO, "O ficheiro foi removido com sucesso.\n", 38);
		return 1;
	}
	return 0;
}
