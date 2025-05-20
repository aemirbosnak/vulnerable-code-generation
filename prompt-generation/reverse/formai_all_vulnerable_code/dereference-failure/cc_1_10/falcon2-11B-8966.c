//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

void handle_segfault(int sig) {
    fprintf(stderr, "Segmentation fault!\n");
    exit(EXIT_FAILURE);
}

void handle_int(int sig) {
    fprintf(stderr, "Interrupted!\n");
    exit(EXIT_FAILURE);
}

void* my_malloc(size_t size) {
    void* ptr;
    if ((ptr = malloc(size)) == NULL) {
        fprintf(stderr, "Failed to allocate %lu bytes!\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main(int argc, char* argv[]) {
    int fd;
    void* mapped_memory;
    struct stat st;
    int result;
    int i;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        fprintf(stderr, "Failed to open file %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &st) == -1) {
        fprintf(stderr, "Failed to get file size: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((mapped_memory = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED) {
        fprintf(stderr, "Failed to map file into memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < st.st_size; i += 4096) {
        if (mprotect(mapped_memory + i, 4096, PROT_READ | PROT_WRITE) == -1) {
            fprintf(stderr, "Failed to protect memory region %ld: %s\n", i, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    if (signal(SIGSEGV, handle_segfault) == SIG_ERR) {
        fprintf(stderr, "Failed to install signal handler for SIGSEGV: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (signal(SIGINT, handle_int) == SIG_ERR) {
        fprintf(stderr, "Failed to install signal handler for SIGINT: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < st.st_size; i += 4096) {
        if (mprotect(mapped_memory + i, 4096, PROT_READ) == -1) {
            fprintf(stderr, "Failed to protect memory region %ld: %s\n", i, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    if (munmap(mapped_memory, st.st_size) == -1) {
        fprintf(stderr, "Failed to unmap memory: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}