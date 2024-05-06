#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {
	char inp[100];
	char out[100];
	int size;
	printf("Enter string to write into file: ");
	scanf("%[^\n]", inp);

	int file = open("test.txt", O_WRONLY);
	if (file < 0) {
		printf("An error occured. Exiting...\n");
		exit(1);
	}

	write(file, inp, strlen(inp));
	printf("String successfully written into file.\n");
	close(file);

	int f = open("test.txt", O_RDONLY);
	if (f < 0) {
		printf("An error occured. Exiting...\n");
		exit(1);
	}

	size = read(f, out, sizeof(inp));
	out[size] = '\0';
	printf("Contents of the file: %s\n", out);
	close(f);
}
