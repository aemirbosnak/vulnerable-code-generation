//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

typedef struct {
    char *filename;
    off_t offset;
    size_t size;
} file_info;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file> <offset> <size>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    off_t offset = atoll(argv[2]);
    size_t size = atoll(argv[3]);

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    if (lseek(fd, offset, SEEK_SET) == -1) {
        perror("lseek");
        return EXIT_FAILURE;
    }

    char buf[BUFSIZE];
    size_t bytes_read;
    while ((bytes_read = read(fd, buf, BUFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, bytes_read) == -1) {
            perror("write");
            return EXIT_FAILURE;
        }

        if (bytes_read < BUFSIZE) {
            break;
        }
    }

    close(fd);

    return EXIT_SUCCESS;
}