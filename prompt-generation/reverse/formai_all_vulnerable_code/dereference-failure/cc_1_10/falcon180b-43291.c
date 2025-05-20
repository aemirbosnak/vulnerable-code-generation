//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/syscall.h>

#define SIZE (1024 * 1024)

int main() {
    int fd;
    void *addr;
    int i;
    char *filename = "testfile";
    char c;

    // Create file
    fd = open(filename, O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        printf("Error creating file: %s\n", strerror(errno));
        exit(1);
    }

    // Map file to memory
    addr = mmap(NULL, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        printf("Error mapping file: %s\n", strerror(errno));
        exit(1);
    }

    // Fill memory with data
    for (i = 0; i < SIZE; i++) {
        ((char*)addr)[i] = 'a';
    }

    // Unmap file from memory
    if (munmap(addr, SIZE) < 0) {
        printf("Error unmapping file: %s\n", strerror(errno));
        exit(1);
    }

    // Close file
    if (close(fd) < 0) {
        printf("Error closing file: %s\n", strerror(errno));
        exit(1);
    }

    return 0;
}