//FormAI DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

#define READ_SIZE 1024
#define ENCRIPTION_KEY 10

char buffer[READ_SIZE];
volatile sig_atomic_t stop_flag = 0;

void handle_sigint(int signum) {
    stop_flag = 1;
}

void encrypt(char *buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] ^= ENCRIPTION_KEY;
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *file_path = argv[1];
    int file_fd = open(file_path, O_RDWR);

    if (file_fd < 0) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct stat file_stat;
    if (stat(file_path, &file_stat) < 0) {
        printf("Error determining file size: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    off_t file_size = file_stat.st_size;
    int num_reads = file_size / READ_SIZE;
    int remainder_bytes = file_size % READ_SIZE;

    if (remainder_bytes > 0) {
        num_reads++;
    }

    printf("Encrypting %ld bytes of data in %d reads\n", file_size, num_reads);

    signal(SIGINT, handle_sigint);

    for (int i = 0; i < num_reads; i++) {
        if (stop_flag) break;

        int bytes_to_read = READ_SIZE;
        if (i == num_reads - 1 && remainder_bytes > 0) {
            bytes_to_read = remainder_bytes;
        }

        off_t offset = i * READ_SIZE;
        if (lseek(file_fd, offset, SEEK_SET) < 0) {
            printf("Error seeking file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (read(file_fd, buffer, bytes_to_read) < 0) {
            printf("Error reading from file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        encrypt(buffer, bytes_to_read);

        if (lseek(file_fd, offset, SEEK_SET) < 0) {
            printf("Error seeking file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (write(file_fd, buffer, bytes_to_read) < 0) {
            printf("Error writing to file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        printf("Read %d bytes from file, encrypted and wrote back to file\n", bytes_to_read);
        sleep(1);
    }

    close(file_fd);
    printf("File %s encrypted successfully\n", file_path);
    return 0;
}