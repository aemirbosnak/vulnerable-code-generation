//Falcon-180B DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    Person *person1 = NULL;
    Person *person2 = NULL;

    // Allocate memory for person1
    person1 = (Person *) malloc(sizeof(Person));
    if (person1 == NULL) {
        printf("Error: Unable to allocate memory for person1.\n");
        exit(1);
    }

    // Set person1's name and age
    person1->name = strdup("John");
    person1->age = 25;

    // Allocate memory for person2
    person2 = (Person *) malloc(sizeof(Person));
    if (person2 == NULL) {
        printf("Error: Unable to allocate memory for person2.\n");
        exit(1);
    }

    // Set person2's name and age
    person2->name = strdup("Jane");
    person2->age = 30;

    // Print out person1's information
    print_person(person1);

    // Print out person2's information
    print_person(person2);

    // Free memory for person1 and person2
    free(person1->name);
    free(person1);
    free(person2->name);
    free(person2);

    return 0;
}