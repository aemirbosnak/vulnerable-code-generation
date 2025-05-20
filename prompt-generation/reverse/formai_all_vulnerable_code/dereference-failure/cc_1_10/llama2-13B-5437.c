//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <fcntl.h>

#define MAGIC_NUMBER 0xDEADBEEF

int main(void) {
    // Step 1: Create a virtual memory region
    void* vaddr = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (vaddr == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Step 2: Write the magic number to the memory region
    *(int*)vaddr = MAGIC_NUMBER;

    // Step 3: Create a file and write the memory region to it
    int fd = open("magic_number.file", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open() failed");
        return 1;
    }
    if (write(fd, vaddr, 4096) != 4096) {
        perror("write() failed");
        return 1;
    }

    // Step 4: Make the memory region read-only
    if (mprotect(vaddr, 4096, PROT_READ | PROT_EXEC) == -1) {
        perror("mprotect() failed");
        return 1;
    }

    // Step 5: Execute the program and check if it prints the magic number
    char* argv[] = {"/bin/sh", NULL};
    if (execve(NULL, argv, NULL) == -1) {
        perror("execve() failed");
        return 1;
    }

    // Step 6: Check if the magic number is still present in the memory region
    void* p = mmap(NULL, 4096, PROT_READ, MAP_PRIVATE, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }
    int found = 0;
    for (size_t i = 0; i < 4096; i++) {
        if (*(int*)p == MAGIC_NUMBER) {
            found = 1;
            break;
        }
        p += sizeof(int);
    }
    if (!found) {
        perror("Magic number not found");
        return 1;
    }

    return 0;
}