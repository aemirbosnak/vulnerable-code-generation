//Falcon-180B DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string_t {
    char *ptr;
    size_t len;
} string_t;

void *malloc_wrapper(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void free_wrapper(void *ptr) {
    free(ptr);
}

void *calloc_wrapper(size_t num, size_t size) {
    void *ptr = calloc(num, size);
    if (ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return ptr;
}

void *realloc_wrapper(void *ptr, size_t size) {
    void *new_ptr = realloc(ptr, size);
    if (new_ptr == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    return new_ptr;
}

int main() {
    string_t *str1 = malloc_wrapper(sizeof(string_t));
    str1->ptr = malloc_wrapper(10 * sizeof(char));
    str1->len = 0;
    
    strcat(str1->ptr, "Hello");
    strcat(str1->ptr, " World!");
    
    printf("str1 = %s\n", str1->ptr);
    
    string_t *str2 = calloc_wrapper(2, sizeof(string_t));
    str2[0].ptr = malloc_wrapper(10 * sizeof(char));
    str2[0].len = 0;
    str2[1].ptr = malloc_wrapper(10 * sizeof(char));
    str2[1].len = 0;
    
    strcat(str2[0].ptr, "Hello");
    strcat(str2[0].ptr, " World!");
    strcat(str2[1].ptr, "C Programming");
    
    printf("str2[0] = %s\n", str2[0].ptr);
    printf("str2[1] = %s\n", str2[1].ptr);
    
    realloc_wrapper(str1->ptr, 20 * sizeof(char));
    strcat(str1->ptr, " is fun!");
    
    printf("str1 = %s\n", str1->ptr);
    
    free_wrapper(str1->ptr);
    free_wrapper(str1);
    free_wrapper(str2[0].ptr);
    free_wrapper(str2[1].ptr);
    free_wrapper(str2);
    
    return 0;
}