//Falcon-180B DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char *name;
    int age;
} person_t;

person_t *create_person(const char *name, int age) {
    person_t *person = malloc(sizeof(person_t));
    if (person == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for person.\n");
        exit(EXIT_FAILURE);
    }

    person->name = strdup(name);
    if (person->name == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for person's name.\n");
        free(person);
        exit(EXIT_FAILURE);
    }

    person->age = age;
    return person;
}

void delete_person(person_t *person) {
    free(person->name);
    free(person);
}

void print_person(const person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    person_t *person1 = create_person("John", 30);
    person_t *person2 = create_person("Jane", 25);

    print_person(person1);
    print_person(person2);

    delete_person(person1);
    delete_person(person2);

    return 0;
}