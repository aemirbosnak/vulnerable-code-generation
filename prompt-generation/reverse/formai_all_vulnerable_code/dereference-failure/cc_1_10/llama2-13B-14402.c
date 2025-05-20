//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEMORY 1024
#define MAX_OBJECTS 100

typedef struct {
    char *name;
    int age;
} person;

void *malloc_function(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void free_function(void *ptr) {
    free(ptr);
}

int main() {
    person *people = malloc_function(MAX_OBJECTS * sizeof(person));
    if (people == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_OBJECTS; i++) {
        people[i].name = malloc_function(20);
        people[i].age = rand() % 100;
    }

    for (int i = 0; i < MAX_OBJECTS; i++) {
        printf("Person %d: %s (%d years old)\n", i, people[i].name, people[i].age);
    }

    for (int i = 0; i < MAX_OBJECTS; i++) {
        free(people[i].name);
    }

    free(people);

    return 0;
}