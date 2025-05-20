//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        fprintf(stderr, "Error opening output file: %s\n", strerror(errno));
        return 1;
    }

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            if (isalpha(buffer[i])) {
                buffer[i] = toupper(buffer[i]);
            }
        }
        write(fd, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading input file: %s\n", strerror(errno));
        return 1;
    }

    close(fd);
    return 0;
}