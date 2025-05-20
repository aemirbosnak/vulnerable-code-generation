//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        printf("Error getting file status: %s\n", strerror(errno));
        exit(1);
    }

    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        char *line = strchr(buffer, '\n');
        if (line == NULL) {
            printf("Error: Line too long\n");
            exit(1);
        }
        *line = '\0';
        printf("%s", buffer);
        fflush(stdout);
        memmove(buffer, line + 1, BUFFER_SIZE - (line - buffer));
    }

    if (bytes_read == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        exit(1);
    } else if (bytes_read == 0) {
        printf("End of file reached\n");
    }

    close(fd);
    free(buffer);
    return 0;
}