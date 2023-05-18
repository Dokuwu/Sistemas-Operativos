//#include <fcntl.h>
//#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
//#include <sys/stat.h>
#include <string.h>

int main() {
	char* prompt = ' ';
	while (strcmp(prompt, "exit")){
		fgets(0,prompt,200);
	}

}