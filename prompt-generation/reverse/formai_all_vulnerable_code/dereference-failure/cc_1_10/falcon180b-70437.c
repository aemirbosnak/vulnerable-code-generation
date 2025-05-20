//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096
#define ROUND_UP(x) ((x) + PAGE_SIZE - 1)

int main() {
    int fd = open("/dev/zero", O_RDWR);
    if (fd == -1) {
        fprintf(stderr, "Failed to open /dev/zero\n");
        return 1;
    }

    void *ptr = mmap(NULL, 1024 * 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        fprintf(stderr, "Failed to mmap\n");
        close(fd);
        return 1;
    }

    printf("RAM usage monitor started\n");
    while (1) {
        struct statvfs fs_stat;
        if (statvfs("/", &fs_stat) == -1) {
            fprintf(stderr, "Failed to get filesystem stats\n");
            munmap(ptr, 1024 * 1024);
            close(fd);
            return 1;
        }

        printf("Total RAM: %ld bytes\n", fs_stat.f_blocks * fs_stat.f_bsize);
        printf("Used RAM: %ld bytes\n", (fs_stat.f_blocks - fs_stat.f_bfree) * fs_stat.f_bsize);
        printf("Free RAM: %ld bytes\n", fs_stat.f_bfree * fs_stat.f_bsize);

        int i;
        for (i = 0; i < 1024 * 1024; i += PAGE_SIZE) {
            if (memcmp(ptr + i, "\0\0\0\0", PAGE_SIZE)!= 0) {
                printf("Page %d is in use\n", i / PAGE_SIZE);
            }
        }

        sleep(1);
    }

    munmap(ptr, 1024 * 1024);
    close(fd);

    return 0;
}