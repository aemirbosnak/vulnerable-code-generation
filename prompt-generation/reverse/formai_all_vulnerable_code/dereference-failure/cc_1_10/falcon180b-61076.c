//Falcon-180B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a person
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// Function to initialize a person with default values
void initPerson(Person* p) {
    strcpy(p->name, "");
    p->age = 0;
    p->height = 0.0;
}

// Function to print a person's information
void printPerson(Person* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %f\n", p->height);
}

// Function to allocate memory for a person
Person* createPerson() {
    Person* p = (Person*) malloc(sizeof(Person));
    if (p == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    initPerson(p);
    return p;
}

// Function to free memory allocated for a person
void deletePerson(Person* p) {
    free(p);
}

// Function to copy one person's information to another
void copyPerson(Person* dest, Person* src) {
    strcpy(dest->name, src->name);
    dest->age = src->age;
    dest->height = src->height;
}

int main() {
    Person* p1 = createPerson();
    Person* p2 = createPerson();

    printPerson(p1);
    printPerson(p2);

    copyPerson(p1, p2);

    printPerson(p1);
    printPerson(p2);

    deletePerson(p1);
    deletePerson(p2);

    return 0;
}