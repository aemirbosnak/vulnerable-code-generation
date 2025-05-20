//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 20
#define MAX_OBJS 10

// Structure to represent a person
typedef struct {
    char name[MAX_STR_LEN];
    int age;
} person;

// Function to allocate memory for a person
person* alloc_person(void) {
    person* p = (person*) malloc(sizeof(person));
    p->name[0] = '\0';
    p->age = 0;
    return p;
}

// Function to deallocate memory for a person
void free_person(person* p) {
    free(p);
}

// Function to allocate memory for an array of people
person** alloc_people(int n) {
    person** pp = (person**) malloc(n * sizeof(person*));
    for (int i = 0; i < n; i++) {
        pp[i] = alloc_person();
    }
    return pp;
}

// Function to deallocate memory for an array of people
void free_people(person** pp, int n) {
    for (int i = 0; i < n; i++) {
        free_person(pp[i]);
    }
    free(pp);
}

int main() {
    srand(time(NULL)); // For randomizing the ages

    // Allocate memory for an array of people
    person** pp = alloc_people(MAX_OBJS);

    // Initialize the ages randomly
    for (int i = 0; i < MAX_OBJS; i++) {
        pp[i]->age = rand() % 100;
    }

    // Print the allocated memory
    for (int i = 0; i < MAX_OBJS; i++) {
        printf("%d - %s\n", pp[i]->age, pp[i]->name);
    }

    // Deallocate the memory
    free_people(pp, MAX_OBJS);

    return 0;
}