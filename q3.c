#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void traverse(char *fn, int indent) {
	DIR *dir;
    struct dirent *entry;
    int count;
    char path[1025];
    struct stat info;

    for (count=0; count<indent; count++) printf("  ");
  		printf("%s\n", fn);

    if ((dir = opendir(fn)) == NULL ) {
		printf("Failed to open directory.");
	}
	else {
		while (( entry = readdir(dir) ) != NULL) {
			if (entry->d_name[0] != '.') {
				strcpy(path, fn);
				strcat(path, "/");
				strcat(path, entry->d_name);
				if (stat(path, &info) != 0)
					fprintf(stderr, "stat() error on %s: %s\n", path, strerror(errno));
        		else if (S_ISDIR(info.st_mode))
               		traverse(path, indent+1);
			}
		}
		closedir(dir);
	}
}

int main(void) {
	if (fork() == 0) {
		exit(0);
	}

	else {
		pid_t child = wait(NULL);
		printf("Parent pid - %d\n", getpid());
		printf("Child pid - %d\n", child);
	}

	printf("Traversing directory\n\n");
	traverse("../../", 0);
}