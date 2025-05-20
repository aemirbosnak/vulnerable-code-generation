//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAX_OBJS 10

typedef struct {
    char *name;
    int age;
} person;

void *malloc_with_name(size_t size, const char *name) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Memory allocated at address %p with name %s\n", ptr, name);
    return ptr;
}

void free_with_name(void *ptr, const char *name) {
    if (ptr == NULL) {
        printf("Invalid pointer\n");
        return;
    }
    printf("Freeing memory at address %p with name %s\n", ptr, name);
    free(ptr);
}

int main() {
    person *persons = NULL;
    int i;

    // Create some persons
    for (i = 0; i < MAX_OBJS; i++) {
        persons[i].name = malloc_with_name(strlen("John Doe") + 1, "John Doe");
        persons[i].age = rand() % 100;
    }

    // Print the persons
    for (i = 0; i < MAX_OBJS; i++) {
        printf("%d. %s (%d years old)\n", i + 1, persons[i].name, persons[i].age);
    }

    // Free the persons
    for (i = 0; i < MAX_OBJS; i++) {
        free_with_name(persons[i].name, "John Doe");
    }

    return 0;
}