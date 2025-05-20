//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define MEGABYTE (1024*1024)

int main() {
    int fd;
    char *addr;
    struct statvfs buf;
    long long total, available;
    int i;

    if ((fd = open("/dev/zero", O_RDWR)) == -1) {
        perror("open");
        exit(1);
    }

    if (fstatvfs(fd, &buf) == -1) {
        perror("fstatvfs");
        exit(1);
    }

    total = buf.f_blocks * buf.f_frsize;
    available = buf.f_bavail * buf.f_frsize;

    printf("Total RAM: %lld MB\n", total / MEGABYTE);
    printf("Available RAM: %lld MB\n", available / MEGABYTE);

    addr = mmap(NULL, total, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if (addr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    for (i = 0; i < total; i += MEGABYTE) {
        if (i % 10 == 0) {
            printf("Checking %d MB...\n", i / MEGABYTE);
        }
        if (memset(addr + i, 0, MEGABYTE) == -1) {
            perror("memset");
            exit(1);
        }
    }

    if (munmap(addr, total) == -1) {
        perror("munmap");
        exit(1);
    }

    close(fd);

    return 0;
}