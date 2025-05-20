//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <ctype.h>

#define KEY 3
#define BUFFER_SIZE 1024
#define ENCRYPT 1
#define DECRYPT 0

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void *map_file(int fd, size_t len) {
    void *map = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) die("mmap");
    return map;
}

void unmap_file(void *addr, size_t len) {
    if (munmap(addr, len) == -1) die("munmap");
}

void process_file(int argc, char *argv[]) {
    int fd, i, j, shift = KEY;
    char *buffer, *input, *output, temp;
    int encrypt = ENCRYPT;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) die("open");

    buffer = map_file(fd, BUFFER_SIZE);
    input = buffer;

    fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    output = malloc(BUFFER_SIZE);

    while (*input != '\0') {
        if (isalpha(*input)) {
            if (encrypt) {
                i = *input - 97;
                j = (i + shift) % 26;
                output[i] = (char) (j + 97);
            } else {
                i = *input - 97;
                j = (i - shift + 26) % 26;
                output[i] = (char) (j + 97);
            }
        } else {
            output[i] = *input;
        }
        input++;
    }

    write(fd, output, strlen(output));
    close(fd);
    unmap_file(buffer, BUFFER_SIZE);
    free(output);

    printf("Encryption complete.\n");
}

int main(int argc, char *argv[]) {
    process_file(argc, argv);
    return EXIT_SUCCESS;
}