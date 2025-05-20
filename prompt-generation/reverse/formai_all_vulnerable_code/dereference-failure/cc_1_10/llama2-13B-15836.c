//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_STRLEN 100
#define MAX_OBJS 10

typedef struct {
    char *name;
    int age;
} person_t;

void *malloc_with_debug(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: malloc failed\n");
        abort();
    }
    printf("Allocated %zu bytes at %p\n", size, ptr);
    return ptr;
}

void free_with_debug(void *ptr) {
    if (ptr == NULL) {
        printf("Error: free called with NULL pointer\n");
        abort();
    }
    printf("Freed %p\n", ptr);
    free(ptr);
}

int main() {
    person_t *persons = malloc_with_debug(sizeof(person_t) * MAX_OBJS);
    if (persons == NULL) {
        printf("Error: malloc failed\n");
        return 1;
    }

    // Initialize persons
    for (int i = 0; i < MAX_OBJS; i++) {
        persons[i].name = malloc_with_debug(MAX_STRLEN);
        if (persons[i].name == NULL) {
            printf("Error: malloc failed\n");
            return 1;
        }
        snprintf(persons[i].name, MAX_STRLEN, "Person %d", i);
        persons[i].age = i % 2 == 0 ? 25 : 30;
    }

    // Use persons
    for (int i = 0; i < MAX_OBJS; i++) {
        printf("Person %d: %s, %d\n", i, persons[i].name, persons[i].age);
    }

    // Free persons
    for (int i = 0; i < MAX_OBJS; i++) {
        free_with_debug(persons[i].name);
    }
    free(persons);

    return 0;
}