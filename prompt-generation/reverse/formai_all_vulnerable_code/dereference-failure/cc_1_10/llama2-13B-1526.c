//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LEN 1024
#define BUFFER_SIZE 4096

int main(void) {
    char *buffer = malloc(BUFFER_SIZE);
    char *filename = "secret.txt";
    int fd = open(filename, O_RDONLY, 0600);
    off_t offset = 0;
    size_t bytes_read = 0;

    while (bytes_read < BUFFER_SIZE) {
        size_t bytes_to_read = BUFFER_SIZE - bytes_read;
        ssize_t ret = read(fd, buffer + bytes_read, bytes_to_read);
        if (ret == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        bytes_read += ret;
        offset += ret;

        if (offset >= BUFFER_SIZE) {
            break;
        }
    }

    close(fd);

    char *ptr = buffer;
    while (ptr < buffer + bytes_read) {
        char c = *ptr++;
        if (c == '\n') {
            printf("%s\n", buffer);
            buffer = ptr;
            bytes_read = 0;
        }
    }

    free(buffer);

    return 0;
}