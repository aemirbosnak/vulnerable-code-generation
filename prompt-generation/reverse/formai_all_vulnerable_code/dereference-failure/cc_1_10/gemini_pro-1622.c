//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PAGE_SIZE 4096
#define NUM_PAGES 4

int main() {
    // Open the file
    int fd = open("test.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    // Get the file size
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return EXIT_FAILURE;
    }

    // Memory map the file
    void *addr = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return EXIT_FAILURE;
    }

    // Get a pointer to the first page
    void *page = addr;

    // Loop through the pages
    for (int i = 0; i < NUM_PAGES; i++) {
        // Clear the page
        memset(page, 0, PAGE_SIZE);

        // Increment the page pointer
        page += PAGE_SIZE;
    }

    // Unmap the file
    if (munmap(addr, st.st_size) == -1) {
        perror("munmap");
    }

    // Close the file
    close(fd);

    return EXIT_SUCCESS;
}