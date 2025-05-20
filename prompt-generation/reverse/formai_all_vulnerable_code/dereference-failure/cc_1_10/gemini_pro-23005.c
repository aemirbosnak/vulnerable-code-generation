//GEMINI-pro DATASET v1.0 Category: Educational ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple struct to represent a person
typedef struct {
    char *name;
    int age;
} Person;

// A function to create a new person
Person *create_person(char *name, int age) {
    Person *p = malloc(sizeof(Person));
    p->name = strdup(name);
    p->age = age;
    return p;
}

// A function to destroy a person
void destroy_person(Person *p) {
    free(p->name);
    free(p);
}

// A function to print a person
void print_person(Person *p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

// A function to compare two people by age
int compare_people_by_age(const void *p1, const void *p2) {
    Person *person1 = (Person *)p1;
    Person *person2 = (Person *)p2;
    return person1->age - person2->age;
}

// A function to main
int main() {
    // Create an array of people
    Person *people[] = {
        create_person("Alice", 20),
        create_person("Bob", 30),
        create_person("Charlie", 40),
        create_person("Dave", 50),
        create_person("Eve", 60),
    };

    // Print the original array
    printf("Original array:\n");
    for (int i = 0; i < 5; i++) {
        print_person(people[i]);
    }

    // Sort the array by age
    qsort(people, 5, sizeof(Person *), compare_people_by_age);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < 5; i++) {
        print_person(people[i]);
    }

    // Destroy the people
    for (int i = 0; i < 5; i++) {
        destroy_person(people[i]);
    }

    return 0;
}