//LLAMA2-13B DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100
#define MAX_GPA 4.0

// Define a struct to hold person info
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    double gpa;
} person_t;

// Function to generate a random name
void generate_name(person_t *person) {
    char *names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    int i = rand() % sizeof(names) / sizeof(names[0]);
    strcpy(person->name, names[i]);
}

// Function to generate a random age
void generate_age(person_t *person) {
    int age = rand() % MAX_AGE;
    person->age = age;
}

// Function to generate a random GPA
void generate_gpa(person_t *person) {
    double gpa = rand() / (double)MAX_GPA;
    person->gpa = gpa;
}

// Function to print person info
void print_person(person_t *person) {
    printf("Name: %s\nAge: %d\nGPA: %f\n", person->name, person->age, person->gpa);
}

int main() {
    person_t person;

    // Generate a random name
    generate_name(&person);

    // Generate a random age
    generate_age(&person);

    // Generate a random GPA
    generate_gpa(&person);

    // Print person info
    print_person(&person);

    return 0;
}