//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RAM_SIZE 1024 * 1024 // 1MB
#define MONITOR_SIZE 128

char monitor[MONITOR_SIZE];
volatile int ram_used = 0;
volatile int ram_allocated = 0;

void *my_malloc(size_t size) {
    void *ptr;
    if (ram_allocated + size > RAM_SIZE) {
        fprintf(stderr, "***** SHOCKED *****\n");
        fprintf(stderr, "RAM USAGE OVERFLOW!\n");
        fprintf(stderr, "CURRENT USAGE: %d/%d bytes\n", ram_used, RAM_SIZE);
        exit(1);
    }
    ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (ptr == MAP_FAILED) {
        fprintf(stderr, "***** SHOCKED *****\n");
        fprintf(stderr, "MALLOC FAILED!\n");
        exit(1);
    }
    ram_allocated += size;
    ram_used += size;
    sprintf(monitor, "RAM USAGE: %d/%d bytes", ram_used, RAM_SIZE);
    printf("%s\n", monitor);
    return ptr;
}

void my_free(void *ptr, size_t size) {
    if (ptr == NULL) {
        fprintf(stderr, "***** SHOCKED *****\n");
        fprintf(stderr, "INVALID POINTER!\n");
        exit(1);
    }
    munmap(ptr, size);
    ram_used -= size;
    ram_allocated -= size;
    sprintf(monitor, "RAM USAGE: %d/%d bytes", ram_used, RAM_SIZE);
    printf("%s\n", monitor);
}

int main() {
    int *a, *b, *c;
    int i;

    a = (int *)my_malloc(sizeof(int) * 1000);
    b = (int *)my_malloc(sizeof(int) * 2000);
    c = (int *)my_malloc(sizeof(int) * 3000);

    for (i = 0; i < 1000; i++) {
        a[i] = i;
    }

    for (i = 0; i < 2000; i++) {
        b[i] = i * 2;
    }

    for (i = 0; i < 3000; i++) {
        c[i] = i * 3;
    }

    my_free(b, sizeof(int) * 2000);
    my_free(c, sizeof(int) * 3000);
    my_free(a, sizeof(int) * 1000);

    return 0;
}