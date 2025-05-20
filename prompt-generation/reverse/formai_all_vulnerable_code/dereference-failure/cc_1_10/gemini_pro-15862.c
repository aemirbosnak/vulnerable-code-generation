//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
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

typedef struct {
    int id;
    char *name;
    int num_families;
    family *families;
} city;

int main() {
    // Create a city
    city oakland = {1, "Oakland", 0, NULL};

    // Add some families to the city
    family smith = {1, "Smith", 0, NULL};
    family johnson = {2, "Johnson", 0, NULL};
    oakland.families = realloc(oakland.families, (oakland.num_families + 2) * sizeof(family));
    oakland.families[oakland.num_families++] = smith;
    oakland.families[oakland.num_families++] = johnson;

    // Add some people to the Smith family
    person john = {1, "John", 30};
    person mary = {2, "Mary", 25};
    smith.people = realloc(smith.people, (smith.num_people + 2) * sizeof(person));
    smith.people[smith.num_people++] = john;
    smith.people[smith.num_people++] = mary;

    // Add some people to the Johnson family
    person bob = {1, "Bob", 40};
    person alice = {2, "Alice", 35};
    johnson.people = realloc(johnson.people, (johnson.num_people + 2) * sizeof(person));
    johnson.people[johnson.num_people++] = bob;
    johnson.people[johnson.num_people++] = alice;

    // Print the city's information
    printf("City: %s\n", oakland.name);
    for (int i = 0; i < oakland.num_families; i++) {
        family family = oakland.families[i];
        printf("  Family: %s\n", family.name);
        for (int j = 0; j < family.num_people; j++) {
            person person = family.people[j];
            printf("    Person: %s, %d\n", person.name, person.age);
        }
    }

    return 0;
}