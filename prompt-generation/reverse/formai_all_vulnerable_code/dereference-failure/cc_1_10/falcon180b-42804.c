//Falcon-180B DATASET v1.0 Category: Error handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
} person;

// Function to create a new person
person* create_person(char* name, int age) {
    person* new_person = (person*) malloc(sizeof(person));
    if (new_person == NULL) {
        printf("Error: Failed to allocate memory for new person.\n");
        exit(1);
    }

    strcpy(new_person->name, name);
    new_person->age = age;

    return new_person;
}

// Function to print a person's information
void print_person(person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

// Function to update a person's age
void update_age(person* person, int new_age) {
    person->age = new_age;
}

// Main function
int main() {
    person* john = create_person("John", 25);
    person* jane = create_person("Jane", 30);

    print_person(john);
    print_person(jane);

    update_age(john, 26);
    update_age(jane, 31);

    print_person(john);
    print_person(jane);

    free(john);
    free(jane);

    return 0;
}