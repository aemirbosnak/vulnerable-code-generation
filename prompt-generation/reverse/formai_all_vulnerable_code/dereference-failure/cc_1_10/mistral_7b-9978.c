//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <errno.h>

#define MAP_SIZE 1024
#define MAP_NAME "/mmap_test"
#define PROT (PROT_READ | PROT_WRITE)
#define FLAGS (MAP_PRIVATE | MAP_ANON)

void *map_file(size_t size) {
    int fd = open(MAP_NAME, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    ftruncate(fd, size);
    void *addr = mmap(NULL, size, PROT, FLAGS, fd, 0);
    close(fd);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }

    return addr;
}

void unmap_file(void *addr, size_t size) {
    if (munmap(addr, size) == -1) {
        perror("munmap");
    }
}

void *protected_malloc(size_t size) {
    void *addr = map_file(size);
    if (!addr) {
        return NULL;
    }

    memset(addr, 0xcc, size);

    return addr;
}

void protected_free(void *ptr, size_t size) {
    if (ptr == NULL) {
        return;
    }

    unmap_file(ptr, size);
}

int main(void) {
    void *ptr = protected_malloc(1024);
    if (ptr == NULL) {
        fprintf(stderr, "failed to allocate memory\n");
        return 1;
    }

    // use the memory here

    protected_free(ptr, 1024);

    return 0;
}