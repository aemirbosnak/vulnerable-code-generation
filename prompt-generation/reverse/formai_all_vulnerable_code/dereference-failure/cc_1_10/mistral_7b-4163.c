//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define KEY_LENGTH 256
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int fd_in, fd_out, i, key;
    char buffer[BUFFER_SIZE];
    char *filename;
    int encrypt = 1;

    if (argc < 2) {
        printf("Usage: %s <key> <input_file> [output_file]\n", argv[0]);
        exit(1);
    }

    key = atoi(argv[1]);

    if (argc < 3) {
        filename = "encrypted.bin";
    } else {
        filename = argv[2];
    }

    fd_in = open(argv[3], O_RDONLY);
    if (fd_in == -1) {
        die("Failed to open input file.");
    }

    fd_out = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_out == -1) {
        die("Failed to open output file.");
    }

    while (read(fd_in, buffer, BUFFER_SIZE)) {
        for (i = 0; buffer[i]; i++) {
            if (buffer[i] == '\n') {
                putchar(encrypt ? '\n' : '\r');
                continue;
            }
            buffer[i] = (char)((int)buffer[i] + key);
            if (buffer[i] > 127) {
                buffer[i] -= 256;
            }
        }
        write(fd_out, buffer, i);
        if (encrypt) {
            i = write(fd_out, "\n", 1);
            if (i == -1) {
                die("Failed to write to output file.");
            }
        }
    }

    close(fd_in);
    close(fd_out);

    printf("Encrypted %s to %s.\n", argv[3], filename);

    return 0;
}