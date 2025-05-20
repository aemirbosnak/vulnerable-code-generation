//Falcon2-11B DATASET v1.0 Category: System administration ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>

#define PAGE_SIZE 4096

void* alloc_page() {
    void* addr;
    int fd = open("/dev/zero", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    addr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        exit(EXIT_FAILURE);
    }
    close(fd);

    return addr;
}

void free_page(void* addr) {
    int fd = open("/dev/zero", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd, PAGE_SIZE)!= 0) {
        perror("ftruncate");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (msync(addr, PAGE_SIZE, MS_SYNC)!= 0) {
        perror("msync");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (madvise(addr, PAGE_SIZE, MADV_DONTNEED)!= 0) {
        perror("madvise");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    void* page_addr = alloc_page();
    if (page_addr == NULL) {
        perror("alloc_page");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd, PAGE_SIZE)!= 0) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    if (fread(page_addr, PAGE_SIZE, 1, file)!= 1) {
        perror("fread");
        exit(EXIT_FAILURE);
    }

    if (msync(page_addr, PAGE_SIZE, MS_SYNC)!= 0) {
        perror("msync");
        exit(EXIT_FAILURE);
    }

    if (madvise(page_addr, PAGE_SIZE, MADV_DONTNEED)!= 0) {
        perror("madvise");
        exit(EXIT_FAILURE);
    }

    free_page(page_addr);

    fclose(file);
    close(fd);

    return 0;
}