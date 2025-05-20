//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int height;
} Person;

// Function to create a new person
Person* create_person(char* name, int age, int height) {
    Person* new_person = (Person*)malloc(sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_person->name = strdup(name);
    new_person->age = age;
    new_person->height = height;
    return new_person;
}

// Function to print a person's information
void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %d\n", person->height);
}

// Function to compare two people by age
int compare_age(Person* a, Person* b) {
    return a->age - b->age;
}

// Function to sort an array of people by age
void sort_people_by_age(Person** people, int size) {
    qsort(people, size, sizeof(Person*), compare_age);
}

int main() {
    // Create an array of people
    Person* people[MAX_SIZE];
    int num_people = 0;

    // Add some people
    people[num_people++] = create_person("Sir Lancelot", 35, 180);
    people[num_people++] = create_person("King Arthur", 50, 170);
    people[num_people++] = create_person("Merlin", 150, 160);

    // Print the unsorted list
    printf("Unsorted list:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    // Sort the list by age
    sort_people_by_age(people, num_people);

    // Print the sorted list
    printf("\nSorted by age:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    return 0;
}