//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_FILE_SIZE 1024*1024
#define BLOCK_SIZE 512

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source destination\n", argv[0]);
        exit(1);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) die("Failed to open source file");

    struct stat st_src;
    if (fstat(&src_fd, &st_src) < 0) die("Failed to get source file stats");

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, st_src.st_mode);
    if (dest_fd < 0) die("Failed to open or create destination file");

    void *src_map = mmap(NULL, st_src.st_size, PROT_READ, MAP_PRIVATE, src_fd, 0);
    if (src_map == MAP_FAILED) die("Failed to map source file");

    off_t src_offset = 0;
    size_t bytes_read;
    char *dest_ptr = mmap(NULL, BLOCK_SIZE, PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    while (src_offset < st_src.st_size) {
        size_t len = st_src.st_size - src_offset > BLOCK_SIZE ? BLOCK_SIZE : st_src.st_size - src_offset;
        bytes_read = read(src_fd, (void *)((char *)src_map + src_offset), len);
        if (bytes_read < 0) die("Failed to read source file");

        size_t dest_written = 0;
        while (dest_written < len) {
            ssize_t res = write(dest_fd, ((char *)dest_ptr + dest_written), len - dest_written);
            if (res < 0) die("Failed to write to destination file");
            dest_written += res;
        }

        src_offset += bytes_read;
        memset(dest_ptr, 0, BLOCK_SIZE);
    }

    msync(src_map, st_src.st_size, MS_ASYNC);
    munmap(src_map, st_src.st_size);
    close(src_fd);

    msync(dest_ptr, BLOCK_SIZE, MS_SYNC);
    munmap(dest_ptr, BLOCK_SIZE);
    close(dest_fd);

    return 0;
}