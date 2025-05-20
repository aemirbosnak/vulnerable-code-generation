//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/mman.h>

#define MMAP_SIZE 1024 * 1024 // Set the size of mmap to 1MB
#define BUF_SIZE 4096
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

typedef struct ram_usage {
    size_t used;
    size_t total;
} ram_usage;

int main() {
    char *mmap_ptr;
    size_t mmap_size = MMAP_SIZE;
    int fd;
    struct stat stat_buf;
    ram_usage usage;

    // Create a shared memory file and mmap it
    fd = open("/dev/shm/ram_usage_monitor", O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &stat_buf) < 0) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    mmap_ptr = mmap(NULL, mmap_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mmap_ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Initialize the ram_usage structure
    usage.used = 0;
    usage.total = mmap_size;

    while (1) {
        // Get the current RAM usage
        memcpy(&usage, mmap_ptr, sizeof(ram_usage));

        printf("%sRAM Usage:%s %llu/%llu bytes%s\n", ANSI_COLOR_GREEN, "Currently using", (unsigned long long)usage.used, (unsigned long long)usage.total, ANSI_COLOR_RESET);

        // Sleep for a short period of time before checking again
        usleep(100000);

        // Update the RAM usage in the shared memory
        msync(mmap_ptr, sizeof(ram_usage), MS_ASYNC);
        mmap_ptr += usage.used;
        usage.used = 0;

        // Grow the mmap if necessary
        if (getpagesize() * ((size_t)(mmap_ptr - (char *)0) / getpagesize()) >= usage.total) {
            ftruncate(fd, usage.total + MMAP_SIZE);
            mmap_ptr = mremap(mmap_ptr, usage.total, usage.total + MMAP_SIZE, MAP_FIXED | MAP_SHARED);
            if (mmap_ptr == MAP_FAILED) {
                perror("mremap");
                exit(EXIT_FAILURE);
            }
            usage.total += MMAP_SIZE;
        }
    }

    // Unmap the shared memory and close the file
    munmap(mmap_ptr, mmap_size);
    close(fd);

    return EXIT_SUCCESS;
}