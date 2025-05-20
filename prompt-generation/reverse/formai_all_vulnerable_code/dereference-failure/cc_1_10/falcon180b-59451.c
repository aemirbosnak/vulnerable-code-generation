//Falcon-180B DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void init() {
    printf("Initializing memory...\n");
}

void *my_malloc(size_t size) {
    printf("Allocating %d bytes of memory...\n", size);
    return malloc(size);
}

void *my_calloc(size_t count, size_t size) {
    printf("Allocating %d elements of %d bytes each...\n", count, size);
    return calloc(count, size);
}

void *my_realloc(void *ptr, size_t size) {
    printf("Reallocating %d bytes of memory...\n", size);
    return realloc(ptr, size);
}

void my_free(void *ptr) {
    printf("Freeing %p...\n", ptr);
    free(ptr);
}

int main() {
    init();

    Person *person = (Person *)my_malloc(sizeof(Person));
    person->name = (char *)my_malloc(MAX_SIZE);
    strcpy(person->name, "John Doe");
    person->age = 30;

    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);

    my_free(person->name);
    my_free(person);

    return 0;
}