//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <semaphore.h>

#define MEMORY_SIZE (1024 * 1024 * 10)  // 10 MB
#define BUFFER_SIZE (1024 * 1024 * 2)  // 2 MB

sem_t sem;
char *buffer;

void init_semaphore() {
    sem_init(&sem, 0, 1);
}

void *malloc_usable_size(size_t size) {
    return malloc(size);
}

void free_usable_size(void *ptr, size_t size) {
    free(ptr);
}

void print_usage() {
    printf("RAM Usage: %d MB / %d MB (%.2f%%)\n",
           (int)(sysconf( _SC_PHYS_PAGES) * sizeof(long) / 1024 / 1024),
           MEMORY_SIZE,
           (double)sysconf( _SC_PHYS_PAGES) * sizeof(long) / 1024 / 1024 * 100);
}

void* alloc_buffer(size_t size) {
    void *ptr;
    if ((ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0)) == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void dealloc_buffer(void *ptr, size_t size) {
    if (munmap(ptr, size) == -1) {
        perror("munmap");
    }
}

int main() {
    init_semaphore();

    // Allocate a 10 MB buffer
    void *buffer_ptr = alloc_buffer(MEMORY_SIZE);
    if (buffer_ptr == MAP_FAILED) {
        perror("alloc_buffer");
        exit(EXIT_FAILURE);
    }

    // Use some of the buffer
    char *ptr = buffer_ptr;
    for (size_t i = 0; i < BUFFER_SIZE; i++) {
        *ptr = 'a' + i % 26;
        ptr++;
    }

    // Print RAM usage before and after usage
    print_usage();

    // Acquire the semaphore
    sem_wait(&sem);

    // Use the rest of the buffer
    for (size_t i = 0; i < MEMORY_SIZE - BUFFER_SIZE; i++) {
        *(ptr + i) = 'a' + i % 26;
    }

    // Release the semaphore
    sem_post(&sem);

    // Print RAM usage again
    print_usage();

    // Deallocate the buffer
    dealloc_buffer(buffer_ptr, MEMORY_SIZE);

    return 0;
}