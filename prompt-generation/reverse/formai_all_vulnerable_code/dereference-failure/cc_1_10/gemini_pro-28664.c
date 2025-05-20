//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

Person *create_person(char *name, int age, char *occupation) {
    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    person->occupation = strdup(occupation);
    return person;
}

void destroy_person(Person *person) {
    free(person->name);
    free(person->occupation);
    free(person);
}

int main() {
    // Create an array of 100 people.
    Person *people[100];
    for (int i = 0; i < 100; i++) {
        // Generate a random name, age, and occupation.
        char name[32];
        sprintf(name, "Person %d", i);
        int age = rand() % 100;
        char occupation[32];
        sprintf(occupation, "Occupation %d", i);

        // Create a new person and add it to the array.
        people[i] = create_person(name, age, occupation);
    }

    // Print the names of the people.
    for (int i = 0; i < 100; i++) {
        printf("%s\n", people[i]->name);
    }

    // Destroy the people.
    for (int i = 0; i < 100; i++) {
        destroy_person(people[i]);
    }

    return 0;
}