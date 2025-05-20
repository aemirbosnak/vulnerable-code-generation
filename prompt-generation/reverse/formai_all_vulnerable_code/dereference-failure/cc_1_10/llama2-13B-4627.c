//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_OBJS 10

// Structure to represent a person
typedef struct {
    char name[MAX_STR_LEN];
    int age;
} person_t;

// Function to allocate memory for a person
person_t* create_person(void) {
    person_t* p = (person_t*) malloc(sizeof(person_t));
    p->name[0] = '\0';
    p->age = 0;
    return p;
}

// Function to deallocate memory for a person
void destroy_person(person_t** pp) {
    if (*pp != NULL) {
        free((*pp)->name);
        free(*pp);
        *pp = NULL;
    }
}

// Function to allocate memory for an array of people
person_t** create_people(int num_people) {
    person_t** people = (person_t**) malloc(num_people * sizeof(person_t*));
    for (int i = 0; i < num_people; i++) {
        people[i] = create_person();
    }
    return people;
}

// Function to deallocate memory for an array of people
void destroy_people(person_t** people, int num_people) {
    for (int i = 0; i < num_people; i++) {
        destroy_person(&people[i]);
    }
    free(people);
}

int main(void) {
    // Create an array of people
    person_t** people = create_people(MAX_OBJS);

    // Allocate memory for each person in the array
    for (int i = 0; i < MAX_OBJS; i++) {
        people[i] = create_person();
    }

    // Print out the names and ages of each person
    for (int i = 0; i < MAX_OBJS; i++) {
        printf("Person %d: %s, %d\n", i, people[i]->name, people[i]->age);
    }

    // Deallocate memory for each person in the array
    destroy_people(people, MAX_OBJS);

    return 0;
}