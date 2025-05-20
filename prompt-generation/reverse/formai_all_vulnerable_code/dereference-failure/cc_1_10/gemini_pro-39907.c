//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src file> <dst file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    int dst_fd = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct stat src_sb;
    if (fstat(src_fd, &src_sb) == -1) {
        perror("fstat");
        return EXIT_FAILURE;
    }

    if (ftruncate(dst_fd, src_sb.st_size) == -1) {
        perror("ftruncate");
        return EXIT_FAILURE;
    }

    char *src_mmap = mmap(NULL, src_sb.st_size, PROT_READ, MAP_PRIVATE, src_fd, 0);
    if (src_mmap == MAP_FAILED) {
        perror("mmap");
        return EXIT_FAILURE;
    }

    char *dst_mmap = mmap(NULL, src_sb.st_size, PROT_WRITE, MAP_SHARED, dst_fd, 0);
    if (dst_mmap == MAP_FAILED) {
        perror("mmap");
        return EXIT_FAILURE;
    }

    memcpy(dst_mmap, src_mmap, src_sb.st_size);

    munmap(src_mmap, src_sb.st_size);
    munmap(dst_mmap, src_sb.st_size);

    close(src_fd);
    close(dst_fd);

    return EXIT_SUCCESS;
}