//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define CACHELINE_SIZE 64

int main(int argc, char *argv[]) {
    struct timeval start, end, result;
    int fd, size, page_size, cache_size, i, j, k;
    char *mmap_addr, *file_addr;
    double elapsed_time;

    if (argc!= 3) {
        printf("Usage: %s <filename> <cachesize>\n", argv[0]);
        return 1;
    }

    size = atoi(argv[1]);
    cache_size = atoi(argv[2]);

    fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        printf("Error opening file\n");
        return 1;
    }

    page_size = sysconf(_SC_PAGESIZE);
    cache_size = cache_size * page_size;

    mmap_addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mmap_addr == MAP_FAILED) {
        printf("Error mapping file\n");
        close(fd);
        return 1;
    }

    file_addr = (char *)mmap_addr;

    gettimeofday(&start, NULL);

    for (i = 0; i < cache_size; i += CACHELINE_SIZE) {
        for (j = 0; j < CACHELINE_SIZE; j += 8) {
            for (k = 0; k < 8; k++) {
                *(int *)((int)file_addr + i + j + k * 8) = rand() % 256;
            }
        }
    }

    gettimeofday(&end, NULL);
    timersub(&end, &start, &result);
    elapsed_time = result.tv_sec + result.tv_usec / 1000000.0;

    printf("Elapsed time: %lf seconds\n", elapsed_time);

    munmap(mmap_addr, size);
    close(fd);

    return 0;
}