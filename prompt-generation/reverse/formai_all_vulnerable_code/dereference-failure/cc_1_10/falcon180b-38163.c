//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>

#define PAGE_SIZE (4096)

int main() {
    int fd;
    char *filename = "test.txt";
    struct stat stat_buf;
    size_t file_size;
    void *addr;
    int count = 0;

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }

    if (fstat(fd, &stat_buf) == -1) {
        printf("Error getting file status: %s\n", strerror(errno));
        exit(1);
    }

    file_size = stat_buf.st_size;

    addr = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        printf("Error mapping file to memory: %s\n", strerror(errno));
        exit(1);
    }

    printf("Mapped %zu bytes of %s to memory at %p\n", file_size, filename, addr);

    while (1) {
        count = 0;
        for (int i = 0; i < file_size; i += PAGE_SIZE) {
            if (mprotect(addr + i, PAGE_SIZE, PROT_READ | PROT_WRITE) == -1) {
                printf("Error changing permissions for page %d: %s\n", count + 1, strerror(errno));
                exit(1);
            }
            count++;
        }

        printf("Changed permissions for %d pages\n", count);

        usleep(1000);
    }

    munmap(addr, file_size);
    close(fd);

    return 0;
}