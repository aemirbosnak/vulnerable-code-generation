//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define BUFFER_SIZE 4096
#define PAGE_SIZE 4096

void *mmap_alloc(void *start, size_t length, int prot, int flags, int fd, off_t offset) {
    void *addr = mmap(start, length, prot, flags, fd, offset);
    if (addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return addr;
}

void print_memory_map(void *start, size_t length) {
    char *buffer = mmap(NULL, length, PROT_READ, MAP_PRIVATE, -1, 0);
    if (buffer == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    char *addr = (char*)mmap_alloc(buffer, length, PROT_READ, MAP_PRIVATE, -1, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    int fd = open("/proc/self/maps", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char *line = NULL;
    size_t len = 0;
    while ((len = getline(&line, &len, fd))!= -1) {
        char *start = strtok(line, " ");
        char *end = strtok(NULL, " ");
        if (start == NULL || end == NULL) {
            continue;
        }
        int prot = 0;
        if (strstr(start, "r-x")!= NULL) {
            prot |= PROT_READ;
        }
        if (strstr(start, "w-x")!= NULL) {
            prot |= PROT_WRITE;
        }
        if (strstr(start, "x-x")!= NULL) {
            prot |= PROT_EXEC;
        }
        printf("%s -> %s (prot=%x)\n", start, end, prot);
    }
    close(fd);
    munmap(buffer, length);
    munmap(addr, length);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <start_address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    void *start = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (start == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    char *ptr = start;
    int i = 0;
    while (ptr < (start + BUFFER_SIZE)) {
        if (i % 2 == 0) {
            ptr = mmap_alloc(ptr, PAGE_SIZE, PROT_READ, MAP_PRIVATE, -1, 0);
            if (ptr == MAP_FAILED) {
                perror("mmap");
                exit(EXIT_FAILURE);
            }
        }
        ptr += PAGE_SIZE;
        i++;
    }
    print_memory_map(start, BUFFER_SIZE);
    munmap(start, BUFFER_SIZE);
    return 0;
}