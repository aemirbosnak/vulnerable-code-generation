//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define BLOCK_SIZE 1024
#define SHA_BLOCK_SIZE 64
#define HASH_SIZE SHA_BLOCK_SIZE

typedef struct {
    unsigned char hash[HASH_SIZE];
    off_t file_size;
} FileInfo;

void shannon_hash(unsigned char *data, unsigned char *hash) {
    int i, j, bit;
    for (i = 0; i < HASH_SIZE; i++) {
        hash[i] = 0;
        for (j = 0; j < 8; j++) {
            bit = (data[i / 8] >> (7 - j)) & 1;
            hash[i] ^= (bit << (j * 3));
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return 1;
    }

    struct stat src_stat;
    if (fstat(src_fd, &src_stat) < 0) {
        perror("Error getting source file status");
        close(src_fd);
        return 1;
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, src_stat.st_mode);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(src_fd);
        return 1;
    }

    FileInfo *src_info = mmap(NULL, sizeof(FileInfo), PROT_READ, MAP_PRIVATE, src_fd, 0);
    if (src_info == MAP_FAILED) {
        perror("Error mapping source file to memory");
        close(src_fd);
        close(dest_fd);
        return 1;
    }

    char *src_buffer = mmap(NULL, BLOCK_SIZE, PROT_READ, MAP_PRIVATE, src_fd, 0);
    if (src_buffer == MAP_FAILED) {
        perror("Error mapping source file buffer to memory");
        munmap(src_info, sizeof(FileInfo));
        close(src_fd);
        close(dest_fd);
        return 1;
    }

    unsigned char src_hash[HASH_SIZE];
    shannon_hash(src_buffer, src_hash);

    FileInfo *dest_info = mmap(NULL, sizeof(FileInfo), PROT_WRITE, MAP_PRIVATE, dest_fd, 0);
    if (dest_info == MAP_FAILED) {
        perror("Error mapping destination file to memory");
        munmap(src_buffer, BLOCK_SIZE);
        munmap(src_info, sizeof(FileInfo));
        close(src_fd);
        close(dest_fd);
        return 1;
    }

    memcpy(dest_info, src_info, sizeof(FileInfo));
    dest_info->file_size = src_stat.st_size;

    while (src_stat.st_size > 0) {
        ssize_t read_bytes = read(src_fd, src_buffer, BLOCK_SIZE);
        if (read_bytes < 0) {
            perror("Error reading from source file");
            munmap(dest_info, sizeof(FileInfo));
            munmap(src_buffer, BLOCK_SIZE);
            munmap(src_info, sizeof(FileInfo));
            close(src_fd);
            close(dest_fd);
            return 1;
        }

        write(dest_fd, src_buffer, read_bytes);

        unsigned char dest_hash[HASH_SIZE];
        shannon_hash(src_buffer, dest_hash);

        if (memcmp(src_hash, dest_hash, HASH_SIZE) != 0) {
            printf("Hash mismatch! Source and destination files are not identical.\n");
            munmap(dest_info, sizeof(FileInfo));
            munmap(src_buffer, BLOCK_SIZE);
            munmap(src_info, sizeof(FileInfo));
            close(src_fd);
            close(dest_fd);
            return 1;
        }

        src_stat.st_size -= read_bytes;
    }

    munmap(src_info, sizeof(FileInfo));
    munmap(src_buffer, BLOCK_SIZE);

    close(src_fd);
    close(dest_fd);

    printf("Files are identical.\n");

    return 0;
}