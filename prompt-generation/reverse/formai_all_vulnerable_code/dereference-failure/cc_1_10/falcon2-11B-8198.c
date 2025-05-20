//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_file dest_file\n", argv[0]);
        return 1;
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    int dest_fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (dest_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        close(source_fd);
        return 1;
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        fprintf(stderr, "Error getting source file size: %s\n", strerror(errno));
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    off_t source_size = source_stat.st_size;
    off_t dest_size = 0;

    char *source_ptr = mmap(NULL, source_size, PROT_READ, MAP_SHARED, source_fd, 0);
    if (source_ptr == MAP_FAILED) {
        fprintf(stderr, "Error mapping source file: %s\n", strerror(errno));
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    char *dest_ptr = mmap(NULL, source_size, PROT_READ | PROT_WRITE, MAP_SHARED, dest_fd, 0);
    if (dest_ptr == MAP_FAILED) {
        fprintf(stderr, "Error mapping destination file: %s\n", strerror(errno));
        munmap(source_ptr, source_size);
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    char *dest_end = dest_ptr + source_size;

    while (dest_ptr < dest_end) {
        if (*dest_ptr!= *source_ptr) {
            fprintf(stderr, "Error: files are not synchronized\n");
            munmap(dest_ptr, source_size);
            munmap(source_ptr, source_size);
            close(source_fd);
            close(dest_fd);
            return 1;
        }

        dest_ptr++;
        source_ptr++;
    }

    munmap(dest_ptr, source_size);
    munmap(source_ptr, source_size);
    close(source_fd);
    close(dest_fd);

    return 0;
}