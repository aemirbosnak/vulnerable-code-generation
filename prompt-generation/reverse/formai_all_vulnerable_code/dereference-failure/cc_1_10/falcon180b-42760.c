//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#define MEGABYTE (1024*1024)
#define GIGABYTE (1024*MEGABYTE)
#define TOTAL_MEMORY (GIGABYTE*4)

#define SLEEP_SECONDS 3

void print_memory_info(char *name, long long total, long long available, long long usage) {
    printf("%s memory information:\n", name);
    printf("Total: %lld MB\n", total/MEGABYTE);
    printf("Available: %lld MB\n", available/MEGABYTE);
    printf("Usage: %lld MB\n", usage/MEGABYTE);
    printf("Usage percentage: %.2f%%\n", (float)usage/(float)total*100.0);
}

int main() {
    int fd;
    char *addr;
    long long total, available, usage;
    struct statvfs statvfs;
    int ret;

    fd = open("/dev/zero", O_RDWR);
    if (fd == -1) {
        printf("Error opening /dev/zero: %s\n", strerror(errno));
        return 1;
    }

    ret = fstatvfs(fd, &statvfs);
    if (ret == -1) {
        printf("Error getting file system information: %s\n", strerror(errno));
        return 1;
    }

    total = statvfs.f_blocks * statvfs.f_frsize;
    available = statvfs.f_blocks - statvfs.f_blocks % statvfs.f_frsize;
    usage = total - available;

    addr = mmap(NULL, total, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        printf("Error mapping memory: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        sleep(SLEEP_SECONDS);
        print_memory_info("System", total, available, usage);
    }

    return 0;
}