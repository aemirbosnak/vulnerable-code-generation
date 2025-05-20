//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *name;
    int age;
} person;

typedef struct {
    int id;
    char *name;
    int num_people;
    person *people;
} family;

int main() {
    // Create a family
    family family1 = {
        .id = 1,
        .name = "Smith",
        .num_people = 3,
        .people = malloc(sizeof(person) * 3)
    };

    // Add people to the family
    family1.people[0] = (person) {
        .id = 1,
        .name = "John",
        .age = 30
    };
    family1.people[1] = (person) {
        .id = 2,
        .name = "Mary",
        .age = 25
    };
    family1.people[2] = (person) {
        .id = 3,
        .name = "Bob",
        .age = 10
    };

    // Print the family information
    printf("Family ID: %d\n", family1.id);
    printf("Family Name: %s\n", family1.name);
    printf("Number of People in Family: %d\n", family1.num_people);

    // Print the information for each person in the family
    for (int i = 0; i < family1.num_people; i++) {
        printf("\nPerson ID: %d\n", family1.people[i].id);
        printf("Person Name: %s\n", family1.people[i].name);
        printf("Person Age: %d\n", family1.people[i].age);
    }

    // Free the memory allocated for the family
    free(family1.people);

    return 0;
}