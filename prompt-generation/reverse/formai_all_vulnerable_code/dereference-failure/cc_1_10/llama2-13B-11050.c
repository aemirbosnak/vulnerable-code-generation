//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 20
#define MAX_OBJ_COUNT 10

// Structure to represent a person
typedef struct {
    char name[MAX_STR_LEN];
    int age;
} person;

// Function to allocate memory for a person
person* allocate_person(void) {
    person* p = (person*) malloc(sizeof(person));
    p->name[0] = '\0';
    p->age = 0;
    return p;
}

// Function to deallocate memory for a person
void deallocate_person(person* p) {
    free(p);
}

// Function to allocate memory for an array of people
person** allocate_people(int count) {
    person** pp = (person**) malloc(count * sizeof(person*));
    for (int i = 0; i < count; i++) {
        pp[i] = allocate_person();
    }
    return pp;
}

// Function to deallocate memory for an array of people
void deallocate_people(person** pp, int count) {
    for (int i = 0; i < count; i++) {
        deallocate_person(pp[i]);
    }
    free(pp);
}

int main() {
    person** people = allocate_people(MAX_OBJ_COUNT);
    for (int i = 0; i < MAX_OBJ_COUNT; i++) {
        people[i] = allocate_person();
        strcpy(people[i]->name, "Person ");
        people[i]->age = i + 1;
    }

    // Use the people array for a while
    for (int i = 0; i < MAX_OBJ_COUNT; i++) {
        printf("Person %d: %s (%d years old)\n", i, people[i]->name, people[i]->age);
    }

    // Deallocate the people array
    deallocate_people(people, MAX_OBJ_COUNT);

    return 0;
}