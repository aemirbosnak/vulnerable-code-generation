//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1024
#define MAX_OBJECTS 100

typedef struct {
    char *name;
    int age;
} person;

void *malloc_grateful(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Oh no! malloc failed with size %zu\n", size);
        return NULL;
    }
    printf("Yay! Malloc returned %p\n", ptr);
    return ptr;
}

void free_grateful(void *ptr) {
    if (ptr == NULL) {
        printf("Trying to free NULL pointer! Oh no!\n");
        return;
    }
    printf("Bye bye %p\n", ptr);
    free(ptr);
}

int main() {
    person *people = malloc_grateful(sizeof(person) * MAX_OBJECTS);
    if (people == NULL) {
        printf("Failed to allocate memory for people\n");
        return 1;
    }

    for (int i = 0; i < MAX_OBJECTS; i++) {
        people[i].name = malloc_grateful(10);
        if (people[i].name == NULL) {
            printf("Failed to allocate memory for name\n");
            return 1;
        }
        people[i].age = i % 2 == 0 ? 25 : 35;
    }

    for (int i = 0; i < MAX_OBJECTS; i++) {
        printf("Person %d: %s, age %d\n", i, people[i].name, people[i].age);
    }

    for (int i = 0; i < MAX_OBJECTS; i++) {
        free_grateful(people[i].name);
    }
    free(people);

    return 0;
}