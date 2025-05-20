//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_OBJS 10
#define OBJ_SIZE 20

typedef struct obj {
    char name[20];
    int age;
} obj;

void *malloc_with_check(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void free_with_check(void *ptr) {
    free(ptr);
    if (ptr == NULL) {
        fprintf(stderr, "Memory deallocation failed\n");
    }
}

int main() {
    // Create objects
    obj *objs[MAX_OBJS];
    for (int i = 0; i < MAX_OBJS; i++) {
        objs[i] = (obj *)malloc_with_check(sizeof(obj));
        if (objs[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return EXIT_FAILURE;
        }
        strcpy(objs[i]->name, "Object #");
        objs[i]->age = i % 2 == 0 ? 25 : 30;
    }

    // Test memory management functions
    for (int i = 0; i < MAX_OBJS; i++) {
        if (objs[i]->age == 25) {
            printf("Object #%d is 25 years old\n", i);
        } else {
            printf("Object #%d is %d years old\n", i, objs[i]->age);
        }
    }

    // Free objects
    for (int i = 0; i < MAX_OBJS; i++) {
        free_with_check(objs[i]);
    }

    return EXIT_SUCCESS;
}