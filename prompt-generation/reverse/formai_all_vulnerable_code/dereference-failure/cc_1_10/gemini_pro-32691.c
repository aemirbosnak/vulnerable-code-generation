//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const char *name = "EphemeralIPC";
    int fd;
    char *addr;

    // Create a shared memory object
    fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, 0666);
    if (fd == -1) {
        perror("shm_open");
        return 1;
    }

    // Set the size of the shared memory object
    if (ftruncate(fd, sizeof(int)) == -1) {
        perror("ftruncate");
        return 1;
    }

    // Map the shared memory object into the process's address space
    addr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write a random value to the shared memory object
    *addr = rand();

    // Unmap the shared memory object from the process's address space
    if (munmap(addr, sizeof(int)) == -1) {
        perror("munmap");
        return 1;
    }

    // Close the file descriptor for the shared memory object
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    // Unlink the shared memory object from the file system
    if (shm_unlink(name) == -1) {
        perror("shm_unlink");
        return 1;
    }

    return 0;
}