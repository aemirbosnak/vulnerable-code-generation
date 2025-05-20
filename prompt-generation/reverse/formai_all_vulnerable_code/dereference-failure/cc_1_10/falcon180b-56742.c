//Falcon-180B DATASET v1.0 Category: Memory management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold our data
typedef struct {
    int id;
    char name[50];
} Person;

// Function to initialize a Person struct
void init_person(Person* p) {
    p->id = -1;
    strcpy(p->name, "");
}

// Function to create a new Person struct
Person* create_person() {
    Person* p = (Person*) malloc(sizeof(Person));
    if (p == NULL) {
        printf("Error: unable to allocate memory for person.\n");
        exit(1);
    }
    init_person(p);
    return p;
}

// Function to copy an existing Person struct
Person* copy_person(Person* src) {
    Person* dest = (Person*) malloc(sizeof(Person));
    if (dest == NULL) {
        printf("Error: unable to allocate memory for person copy.\n");
        exit(1);
    }
    init_person(dest);
    dest->id = src->id;
    strcpy(dest->name, src->name);
    return dest;
}

// Function to free a Person struct
void free_person(Person* p) {
    free(p);
}

// Main function
int main() {
    Person* p1 = create_person();
    init_person(p1);
    p1->id = 1;
    strcpy(p1->name, "John Doe");

    Person* p2 = copy_person(p1);

    printf("Name: %s\n", p1->name);
    printf("ID: %d\n", p1->id);

    printf("\n");

    printf("Name: %s\n", p2->name);
    printf("ID: %d\n", p2->id);

    free_person(p1);
    free_person(p2);

    return 0;
}