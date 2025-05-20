//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_OBJS 10

typedef struct {
    char *name;
    int age;
} person_t;

void *mem_alloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

void mem_free(void *ptr) {
    free(ptr);
}

person_t *create_person(void) {
    person_t *ptr = (person_t *)mem_alloc(sizeof(person_t));
    ptr->name = (char *)mem_alloc(strlen("John Doe") + 1);
    strcpy(ptr->name, "John Doe");
    ptr->age = 30;
    return ptr;
}

void print_person(person_t *ptr) {
    printf("Name: %s, Age: %d\n", ptr->name, ptr->age);
}

int main() {
    person_t *ptr1, *ptr2, *ptr3;

    // Create three persons
    ptr1 = create_person();
    ptr2 = create_person();
    ptr3 = create_person();

    // Print the persons' details
    print_person(ptr1);
    print_person(ptr2);
    print_person(ptr3);

    // Free the memory allocated for the first two persons
    mem_free(ptr1);
    mem_free(ptr2);

    // Print the remaining person's details
    print_person(ptr3);

    return 0;
}