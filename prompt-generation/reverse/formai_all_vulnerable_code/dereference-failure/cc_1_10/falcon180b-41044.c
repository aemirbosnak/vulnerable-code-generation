//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void read_file(char *filename, char **buffer) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    struct stat file_stat;
    fstat(fd, &file_stat);
    int file_size = file_stat.st_size;

    *buffer = malloc(file_size + 1);
    if (*buffer == NULL) {
        printf("Error: Could not allocate memory for buffer\n");
        exit(1);
    }

    int bytes_read = read(fd, *buffer, file_size);
    if (bytes_read!= file_size) {
        printf("Error: Could not read entire file '%s'\n", filename);
        exit(1);
    }

    (*buffer)[file_size] = '\0';
    close(fd);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *buffer = NULL;

    read_file(filename, &buffer);

    printf("File contents:\n");
    printf("%s", buffer);

    return 0;
}