//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 50
#define MAX_ARRAY_LEN 10

// Structure to represent a person
typedef struct {
    char name[MAX_STR_LEN];
    int age;
    int phoneNumber;
} person_t;

// Function to allocate memory for a person
person_t* createPerson(void) {
    person_t* p = (person_t*) malloc(sizeof(person_t));
    p->name[0] = '\0';
    p->age = 0;
    p->phoneNumber = 0;
    return p;
}

// Function to deallocate memory for a person
void destroyPerson(person_t** pp) {
    if (*pp != NULL) {
        free((*pp)->name);
        free(*pp);
        *pp = NULL;
    }
}

// Function to allocate memory for an array of persons
person_t** createPersonArray(int size) {
    person_t** pp = (person_t**) malloc(size * sizeof(person_t*));
    for (int i = 0; i < size; i++) {
        pp[i] = createPerson();
    }
    return pp;
}

// Function to deallocate memory for an array of persons
void destroyPersonArray(person_t** pp, int size) {
    for (int i = 0; i < size; i++) {
        destroyPerson(&pp[i]);
    }
    free(pp);
}

int main(void) {
    srand(time(NULL)); // For randomizing phone numbers

    // Allocate memory for an array of 5 persons
    person_t** pp = createPersonArray(5);

    // Initialize each person's name and age randomly
    for (int i = 0; i < 5; i++) {
        pp[i]->name[0] = rand() % 26 + 'A';
        pp[i]->age = rand() % 100 + 1;
        pp[i]->phoneNumber = rand() % 10000 + 1;
    }

    // Print the persons' information
    for (int i = 0; i < 5; i++) {
        printf("Person %d: %s, age %d, phone number %d\n", i, pp[i]->name, pp[i]->age, pp[i]->phoneNumber);
    }

    // Deallocate memory for the array of persons
    destroyPersonArray(pp, 5);

    return 0;
}