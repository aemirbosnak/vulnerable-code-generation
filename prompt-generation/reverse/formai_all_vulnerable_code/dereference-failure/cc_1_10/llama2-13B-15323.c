//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 20
#define MAX_ARRAY_SIZE 10

typedef struct {
    char *name;
    int age;
} person;

void *malloc_wrapper(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed! Size: %zu\n", size);
        exit(1);
    }
    return ptr;
}

void free_wrapper(void *ptr) {
    free(ptr);
}

int main() {
    person *people = malloc_wrapper(MAX_ARRAY_SIZE * sizeof(person));
    if (people == NULL) {
        printf("Memory allocation failed for people array\n");
        return 1;
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        people[i].name = malloc_wrapper(20);
        if (people[i].name == NULL) {
            printf("Memory allocation failed for name %d\n", i);
            return 1;
        }
        people[i].age = i % 2 == 0 ? 25 : 30;
    }

    // Use the allocated memory safely
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("Person %d: %s, age %d\n", i, people[i].name, people[i].age);
    }

    // Free the allocated memory
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}