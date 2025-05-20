//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to represent a person
typedef struct {
    char name[50];
    int age;
    int height;
} person_t;

// Function to print a person's details
void print_person(person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %d cm\n", person->height);
}

// Function to create a new person
person_t *create_person(char *name, int age, int height) {
    person_t *new_person = malloc(sizeof(person_t));
    strcpy(new_person->name, name);
    new_person->age = age;
    new_person->height = height;
    return new_person;
}

// Function to calculate the BMI of a person
double calculate_bmi(person_t *person) {
    double weight = person->height * 100; // assume weight is 100 kg/m^2
    double bmi = weight / (person->height * person->height);
    return bmi;
}

int main() {
    // Create a new person
    person_t *person = create_person("Alice", 25, 160);

    // Print the person's details
    print_person(person);

    // Calculate the BMI of the person
    double bmi = calculate_bmi(person);
    printf("BMI: %f\n", bmi);

    // Free the memory allocated for the person
    free(person);

    return 0;
}