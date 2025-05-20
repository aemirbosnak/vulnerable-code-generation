//Falcon-180B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for our data
typedef struct {
    char *name;
    int age;
} Person;

// Function to create a new person
Person* create_person(char *name, int age) {
    Person *p = malloc(sizeof(Person));
    if (p == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    p->name = strdup(name);
    p->age = age;
    return p;
}

// Function to print a person's information
void print_person(Person *p) {
    printf("Name: %s\nAge: %d\n", p->name, p->age);
}

// Function to free a person's memory
void free_person(Person *p) {
    free(p->name);
    free(p);
}

int main() {
    // Create some people
    Person *p1 = create_person("Alice", 25);
    Person *p2 = create_person("Bob", 30);
    Person *p3 = create_person("Charlie", 20);

    // Print their information
    print_person(p1);
    print_person(p2);
    print_person(p3);

    // Free their memory
    free_person(p1);
    free_person(p2);
    free_person(p3);

    return 0;
}