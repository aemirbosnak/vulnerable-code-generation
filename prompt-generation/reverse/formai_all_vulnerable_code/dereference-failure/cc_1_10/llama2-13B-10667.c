//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_ARRAY_SIZE 100

typedef struct {
    char *name;
    int age;
} person_t;

void *malloc_wrapper(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

void free_wrapper(void *ptr) {
    free(ptr);
    printf("Memory freed successfully\n");
}

int main() {
    person_t *people = malloc_wrapper(sizeof(person_t) * MAX_ARRAY_SIZE);
    if (people == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        people[i].name = malloc_wrapper(strlen(people[i].name) + 1);
        if (people[i].name == NULL) {
            printf("Error: Memory allocation failed\n");
            exit(1);
        }
        strcpy(people[i].name, "Alice");
        people[i].age = 25;
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        free_wrapper(people[i].name);
    }

    free_wrapper(people);

    return 0;
}