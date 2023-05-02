#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <pwd.h>
#include <string.h>
#include <time.h>
int main(int argc, char* argv[])
{
	// Declaração variaveis.
	struct stat file;
	struct passwd *info_dono;
	// Na variavel tipo inteiro status, a funcao stat da retorno de 0 quando é executada
	// com sucesso e 1 caso contrário. 
	int status = stat(argv[1], &file);
	
	info_dono = getpwuid(file.st_uid);
	char dono_ficheiro[200], inode[20], u_acesso[50], u_mod[50], u_creat[50];
	
	// Caso stat tenha retornado 0, criamos um switch para verificamos qual é o tipo de ficheiro
	// É usado em combinação com o .st_mode o S_IFMT, que é uma bitmask usada para obter
	// o valor do modo do ficheiro especificado
	if (status == 0)
	{ 
		switch(file.st_mode & S_IFMT)
		{
			case S_IFREG:
				write(STDOUT_FILENO, "Ficheiro do tipo normal.\n", 26);
				break;
			case S_IFDIR:
				write(STDOUT_FILENO, "Ficheiro do tipo diretorio.\n", 29); 
				break;
			case S_IFBLK:
				write(STDOUT_FILENO, "Ficheiro do tipo bloco.\n", 25); 
				break;
			case S_IFSOCK:
				write(STDOUT_FILENO, "Ficheiro do tipo socket.\n", 26);
				break;
			case S_IFCHR:
				write(STDOUT_FILENO, "Ficheiro do tipo especial caracter.\n",30); 
			case S_IFIFO:
				write(STDOUT_FILENO, "Ficheiro do tipo Pipe.\n",24);
			case S_IFLNK:
				write(STDOUT_FILENO, "Ficheiro do tipo Link.\n", 24);					
			default:
				write(STDOUT_FILENO, "Ficheiro desconhecido.\n", 18);
		}
			//Print do dono de ficheiro.
			sprintf(dono_ficheiro, "Dono: %s\n", info_dono->pw_name);
			write(STDOUT_FILENO, dono_ficheiro, 20);
			
			//Print do inode.			
			sprintf(inode, "I-node:%ld\n", file.st_ino);
			write(STDOUT_FILENO, inode, strlen(inode));
			
			//Print da data de criacao.
			sprintf(u_creat, "Data de criacao: %s\n", ctime(&file.st_ctime));	
			write(STDOUT_FILENO, u_creat, strlen(u_creat));
	
			//Print da data de modificacao.
			sprintf(u_mod, "Data da ultima modificacao: %s\n", ctime(&file.st_mtime));
			write(STDOUT_FILENO, u_mod, strlen(u_mod));
			
			//Print da data de ultimo acesso.
			sprintf(u_acesso, "Data de ultimo acesso: %s\n", ctime(&file.st_atime));
			write(STDOUT_FILENO, u_acesso, strlen(u_acesso));
	}
	else
	{
		write(STDERR_FILENO, "O Ficheiro nao existe.\n", 24);
		return 0;
	}

	
	return 0;
	
}
