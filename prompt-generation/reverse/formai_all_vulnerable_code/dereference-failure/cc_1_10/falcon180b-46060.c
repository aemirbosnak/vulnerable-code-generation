//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for our data
typedef struct {
    char *name;
    int age;
    float height;
} Person;

// Function to create a new person
Person *create_person(char *name, int age, float height) {
    Person *person = (Person *)malloc(sizeof(Person));

    if (person == NULL) {
        printf("Error: Unable to allocate memory for person\n");
        exit(1);
    }

    person->name = strdup(name);
    person->age = age;
    person->height = height;

    return person;
}

// Function to print a person's information
void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %f\n", person->height);
}

// Function to free a person's memory
void free_person(Person *person) {
    free(person->name);
    free(person);
}

int main() {
    Person *person1 = create_person("John", 25, 1.8);
    Person *person2 = create_person("Jane", 30, 1.6);

    print_person(person1);
    print_person(person2);

    free_person(person1);
    free_person(person2);

    return 0;
}