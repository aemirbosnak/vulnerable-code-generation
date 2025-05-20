//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLOCK_SIZE 512
#define FILENAME_MAX 256

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int src_fd, dst_fd;
    char src_filename[FILENAME_MAX];
    char dst_filename[FILENAME_MAX];
    char block[BLOCK_SIZE];
    off_t src_file_size;
    ssize_t read_bytes;
    size_t written_bytes;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <corrupted_source> <recovered_destination>\n", argv[0]);
        exit(1);
    }

    strcpy(src_filename, argv[1]);
    strcpy(dst_filename, argv[2]);

    src_fd = open(src_filename, O_RDONLY);
    if (src_fd == -1)
        die("Failed to open source file.");

    src_file_size = lseek(src_fd, 0, SEEK_END);
    lseek(src_fd, 0, SEEK_SET);

    dst_fd = open(dst_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (dst_fd == -1)
        die("Failed to create destination file.");

    for (off_t i = 0; i < src_file_size; i += BLOCK_SIZE) {
        read_bytes = read(src_fd, block, BLOCK_SIZE);
        if (read_bytes <= 0) {
            close(src_fd);
            close(dst_fd);
            die("Error reading source file.");
        }

        for (size_t j = 0; j < read_bytes; ++j) {
            if (block[j] == 0xAA) { // Magic value to check for valid data
                written_bytes = write(dst_fd, &block[j], read_bytes - j);
                if (written_bytes <= 0) {
                    close(src_fd);
                    close(dst_fd);
                    die("Error writing to destination file.");
                }
                break;
            }
        }
    }

    close(src_fd);
    close(dst_fd);

    printf("Data recovery successful: %s -> %s\n", src_filename, dst_filename);

    return 0;
}