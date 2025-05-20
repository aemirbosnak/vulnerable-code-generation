//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 100
#define MAX_OBJS 10

typedef struct {
    char *name;
    int age;
} person_t;

void *malloc_protected(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void free_protected(void *ptr) {
    free(ptr);
    printf("Memory freed successfully\n");
}

int main() {
    person_t *persons = malloc_protected(sizeof(person_t) * MAX_OBJS);
    if (persons == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_OBJS; i++) {
        persons[i].name = malloc_protected(MAX_STRLEN);
        if (persons[i].name == NULL) {
            printf("Error: Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        persons[i].age = i % 2 == 0 ? 25 : 30;
    }

    // Use the protected malloc and free functions
    for (int i = 0; i < MAX_OBJS; i++) {
        printf("Person %d: %s, age %d\n", i, persons[i].name, persons[i].age);
    }

    // Free the memory
    for (int i = 0; i < MAX_OBJS; i++) {
        free_protected(persons[i].name);
    }
    free_protected(persons);

    return 0;
}