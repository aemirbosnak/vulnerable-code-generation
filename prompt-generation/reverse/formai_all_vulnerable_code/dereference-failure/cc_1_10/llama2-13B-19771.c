//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 1024
#define MAX_ARRAY_SIZE 1024

typedef struct {
    char *name;
    int age;
} person;

void *malloc_func(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void free_func(void *ptr) {
    free(ptr);
}

int main() {
    person *people = malloc_func(sizeof(person) * MAX_ARRAY_SIZE);
    if (people == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        people[i].name = malloc_func(strlen(getenv("NAME")) + 1);
        strcpy(people[i].name, getenv("NAME"));
        people[i].age = atoi(getenv("AGE"));
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%s is %d years old\n", people[i].name, people[i].age);
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        free_func(people[i].name);
    }
    free_func(people);

    return 0;
}