//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

typedef struct {
    size_t size;
    char *ptr;
} MyHeap;

MyHeap *my_heap;
size_t my_heap_size = 0;

void my_init() {
    my_heap = mmap(NULL, 1024 * 1024, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    if (my_heap == MAP_FAILED) {
        fprintf(stderr, "Failed to initialize heap\n");
        exit(EXIT_FAILURE);
    }
    my_heap_size = 1024 * 1024;
}

void my_terminate() {
    if (munmap(my_heap, my_heap_size) == -1) {
        fprintf(stderr, "Failed to deallocate heap\n");
        exit(EXIT_FAILURE);
    }
}

char *my_alloc(size_t size) {
    char *ptr;
    if (my_heap->size < size + sizeof(MyHeap)) {
        if (my_heap_size <= my_heap->size) {
            my_terminate();
            my_init();
        }
        ptr = my_heap->ptr + my_heap->size;
        my_heap->size += sizeof(MyHeap) + size;
    } else {
        ptr = my_heap->ptr + my_heap->size - size - sizeof(MyHeap);
    }
    my_heap->ptr = ptr;
    return (char *)my_heap + sizeof(MyHeap);
}

void my_free(char *ptr) {
    if (ptr >= (char *)my_heap + sizeof(MyHeap) && ptr < (char *)my_heap + my_heap->size) {
        my_heap->size -= (size_t)(ptr - (char *)my_heap);
        my_heap->ptr = (char *)my_heap + sizeof(MyHeap) + my_heap->size;
    }
}

int main() {
    my_init();

    char *str1 = my_alloc(20);
    strcpy(str1, "Hello, World!");

    char *str2 = my_alloc(15);
    strcpy(str2, "Foo Bar Baz");

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    char *str3 = my_alloc(sizeof("Hello, World!") + sizeof("Foo Bar Baz") + 1);
    strcpy(str3, "Combined string: ");
    strcat(str3, str1);
    strcat(str3, str2);

    printf("Combined string: %s\n", str3);

    my_free(str1);
    my_free(str2);
    my_free(str3);

    my_terminate();

    return 0;
}