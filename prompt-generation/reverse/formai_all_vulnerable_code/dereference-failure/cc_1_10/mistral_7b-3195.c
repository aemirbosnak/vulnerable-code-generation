//MISTRAL-7B DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

typedef struct {
    unsigned char c1, c2, c3, c4, c5, c6, c7, c8;
} byte8;

typedef struct {
    unsigned short int w1, w2, w3, w4;
} word16;

typedef union {
    byte8 b;
    word16 w;
} le;

typedef struct {
    int len, pos;
    unsigned char data[65536];
} buffer;

void checksum_file(const char *filename) {
    int fd, bytes_read;
    struct stat file_stat;
    buffer buffer;
    unsigned int sum = 0;

    if (stat(filename, &file_stat) < 0) {
        perror("Error reading file status");
        return;
    }

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    buffer.len = file_stat.st_size;
    buffer.pos = 0;

    while (buffer.len > 0) {
        bytes_read = read(fd, &buffer.data[buffer.pos], 1);
        if (bytes_read < 0) {
            perror("Error reading file");
            goto error;
        }
        buffer.pos++;
        sum += buffer.data[buffer.pos - 1];
        buffer.len--;
    }

    close(fd);

    printf("File '%s' checksum: %x\n", filename, sum);

    return;

error:
    close(fd);
}

void checksum_string(const char *str, int length) {
    buffer buffer;
    unsigned int sum = 0;

    buffer.len = length;
    buffer.pos = 0;

    while (buffer.len > 0) {
        sum += buffer.data[buffer.pos] ^ getc(stdin);
        buffer.pos++;
        buffer.len--;
    }

    printf("String checksum: %x\n", sum);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [file | string [length]]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strchr(argv[1], '.') != NULL) {
        checksum_file(argv[1]);
    } else {
        checksum_string(argv[1], atoi(argv[2]));
    }

    return EXIT_SUCCESS;
}