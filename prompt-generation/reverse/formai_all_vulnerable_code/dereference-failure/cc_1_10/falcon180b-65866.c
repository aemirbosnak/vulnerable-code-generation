//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
    bool gender;
} Person;

// Function to create a new person
Person* create_person(char* name, int age, bool gender) {
    Person* person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->gender = gender;
    return person;
}

// Function to print a person's information
void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Gender: %s\n", person->gender? "Male" : "Female");
}

// Function to compare two people based on their age
int compare_age(Person* a, Person* b) {
    return a->age - b->age;
}

// Function to sort an array of people based on their age
void sort_people(Person** people, int count) {
    qsort(people, count, sizeof(Person*), compare_age);
}

// Main function
int main() {
    Person* people[10];

    // Create 10 people with random names, ages, and genders
    for (int i = 0; i < 10; i++) {
        char name[10] = {0};
        sprintf(name, "Person %d", i);
        people[i] = create_person(name, rand() % 100, rand() % 2);
    }

    // Print the unsorted list of people
    printf("Unsorted list:\n");
    for (int i = 0; i < 10; i++) {
        print_person(people[i]);
    }

    // Sort the list of people by age
    sort_people(people, 10);

    // Print the sorted list of people
    printf("\nSorted list:\n");
    for (int i = 0; i < 10; i++) {
        print_person(people[i]);
    }

    return 0;
}