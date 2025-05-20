//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    int line_number;
} ErrorInfo;

void error_handler(int errnum, const char *message) {
    fprintf(stderr, "ERROR: %s (%d): %s\n", message, errnum, strerror(errnum));
}

void read_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        error_handler(errno, "Failed to open file");
        exit(1);
    }

    char buffer[MAX_LINE_LENGTH];
    size_t bytes_read;

    while ((bytes_read = read(fd, buffer, MAX_LINE_LENGTH))!= 0) {
        if (bytes_read == -1) {
            error_handler(errno, "Failed to read from file");
            exit(1);
        }

        char *line = strchr(buffer, '\n');
        if (line == NULL) {
            fprintf(stderr, "WARNING: Line too long\n");
            continue;
        }

        *line = '\0';
        printf("%s", buffer);
    }

    if (close(fd) == -1) {
        error_handler(errno, "Failed to close file");
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "USAGE: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_file(argv[1]);

    return 0;
}