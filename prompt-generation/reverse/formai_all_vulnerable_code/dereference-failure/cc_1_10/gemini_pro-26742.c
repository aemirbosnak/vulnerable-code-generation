//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define KB 1024
#define MB (1024 * KB)
#define SIZE 20 * MB

int main() {
    int fd = open("test.bin", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (ftruncate(fd, SIZE) == -1) {
        perror("ftruncate");
        return 1;
    }

    void *ptr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Initialize the memory with zeros
    memset(ptr, 0, SIZE);

    // Write some data to the memory
    for (int i = 0; i < 100; i++) {
        ((int *)ptr)[i] = i;
    }

    // Flush the changes to the file
    if (msync(ptr, SIZE, MS_SYNC) == -1) {
        perror("msync");
        return 1;
    }

    // Unmap the memory
    if (munmap(ptr, SIZE) == -1) {
        perror("munmap");
        return 1;
    }

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}