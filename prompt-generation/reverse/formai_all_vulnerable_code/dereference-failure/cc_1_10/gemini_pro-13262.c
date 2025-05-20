//GEMINI-pro DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdint.h>

#define PAGE_SIZE 4096

// Allocate a page of memory in the protected style
void *alloc_page(void) {
    void *ptr;

    // Allocate a page of memory
    ptr = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    // Mark the page as protected
    if (mprotect(ptr, PAGE_SIZE, PROT_READ) == -1) {
        perror("mprotect");
        exit(1);
    }

    return ptr;
}

// Free a page of memory
void free_page(void *ptr) {
    // Unprotect the page
    if (mprotect(ptr, PAGE_SIZE, PROT_READ | PROT_WRITE) == -1) {
        perror("mprotect");
        exit(1);
    }

    // Free the page
    if (munmap(ptr, PAGE_SIZE) == -1) {
        perror("munmap");
        exit(1);
    }
}

// Write to a protected page
void write_to_protected_page(void *ptr) {
    // Try to write to the protected page
    *(uint32_t *)ptr = 0x12345678;

    // If we get here, the write was successful
    printf("Successfully wrote to the protected page!\n");
}

int main(void) {
    // Allocate a page of memory
    void *ptr = alloc_page();

    // Write to the protected page
    write_to_protected_page(ptr);

    // Free the page
    free_page(ptr);

    return 0;
}