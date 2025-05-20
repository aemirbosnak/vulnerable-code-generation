//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAGIC_NUMBER 0xdeadbeef

void * alloc(size_t size) {
    void *ptr = NULL;
    int flags = MAP_ANON | MAP_PRIVATE;
    if (size == 0) {
        flags |= MAP_NORESERVE;
    }
    ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, flags, -1, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }
    *(int *)ptr = MAGIC_NUMBER;
    return ptr;
}

void free(void *ptr) {
    if (ptr == NULL) {
        return;
    }
    int magic = *(int *)ptr;
    if (magic != MAGIC_NUMBER) {
        printf("Trying to free invalid memory\n");
        return;
    }
    munmap(ptr, strlen(ptr));
}

int main() {
    void *ptr1 = alloc(10);
    void *ptr2 = alloc(20);
    void *ptr3 = alloc(30);

    printf("ptr1: %p\n", ptr1);
    printf("ptr2: %p\n", ptr2);
    printf("ptr3: %p\n", ptr3);

    free(ptr1);
    free(ptr2);
    free(ptr3);

    return 0;
}