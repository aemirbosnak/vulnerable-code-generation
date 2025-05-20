//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define KEY 3
#define BUF_SIZE 128

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <encrypt|decrypt> <filename>\n", argv[0]);
        return 1;
    }

    int mode = (strcmp(argv[1], "encrypt") == 0) ? 1 : -1;
    int fd_in, fd_out;
    char buf[BUF_SIZE];

    if ((fd_in = open(argv[2], O_RDONLY)) < 0) {
        perror("Error opening file for reading");
        return 1;
    }

    if ((fd_out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0) {
        perror("Error creating file for writing");
        close(fd_in);
        return 1;
    }

    while (read(fd_in, buf, BUF_SIZE) > 0) {
        for (int i = 0; i < BUF_SIZE; i++) {
            if (mode == 1)
                buf[i] = (char)((int)buf[i] + KEY);
            else
                buf[i] = (char)((int)buf[i] - KEY);

            if (buf[i] > 127)
                buf[i] %= 128;
        }

        write(fd_out, buf, BUF_SIZE);
    }

    close(fd_in);
    close(fd_out);

    return 0;
}