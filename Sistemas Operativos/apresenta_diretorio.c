#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
	DIR *dir;
	struct dirent *entrada;
	
	char *caminho = argc>1 ? argv[1] : ".";
	
	if ((dir = opendir(caminho)) == NULL)
	{
		perror("Erro ao abrir diretoria");
		exit(EXIT_FAILURE);
	}
	while((entrada = readdir(dir)) !=NULL)
	{
		switch(entrada->d_type)
		{
			case DT_DIR:
			printf("Diretorio:%s\n", entrada->d_name);
			break;
			case DT_REG:
			printf("%s\n", entrada->d_name);
			break;
			
		}
		
	}
	

	closedir(dir);
	
	return 0;	
}
