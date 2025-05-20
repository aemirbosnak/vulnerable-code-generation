//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 50
#define MAX_ARRAY_SIZE 10

typedef struct {
    char *name;
    int age;
} person_t;

void *malloc_custom(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    return ptr;
}

void free_custom(void *ptr) {
    free(ptr);
    printf("Memory freed successfully\n");
}

int main() {
    person_t *people = malloc_custom(MAX_ARRAY_SIZE * sizeof(person_t));
    if (people == NULL) {
        return 1;
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        people[i].name = malloc_custom(strlen(people[i].name) + 1);
        if (people[i].name == NULL) {
            break;
        }
        strcpy(people[i].name, "Alice");
        people[i].age = i * 2;
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("%d: %s, %d\n", i, people[i].name, people[i].age);
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        free_custom(people[i].name);
    }

    free_custom(people);

    return 0;
}