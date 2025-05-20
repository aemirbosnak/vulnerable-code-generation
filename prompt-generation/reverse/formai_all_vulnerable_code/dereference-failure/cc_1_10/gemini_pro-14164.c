//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	DIR *dir;
	struct dirent *entry;
	struct stat buf;
	char buf2[BUFSIZE];
	int fd;
	int i;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s directory\n", argv[0]);
		exit(1);
	}

	dir = opendir(argv[1]);
	if (dir == NULL) {
		perror("opendir");
		exit(1);
	}

	while ((entry = readdir(dir)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;

		snprintf(buf2, BUFSIZE, "%s/%s", argv[1], entry->d_name);

		if (lstat(buf2, &buf) == -1) {
			perror("lstat");
			continue;
		}

		if (S_ISDIR(buf.st_mode)) {
			printf("%s/\n", entry->d_name);
		} else if (S_ISREG(buf.st_mode)) {
			printf("%s\n", entry->d_name);
		} else {
			printf("%s\n", entry->d_name);
		}
	}

	closedir(dir);

	return 0;
}