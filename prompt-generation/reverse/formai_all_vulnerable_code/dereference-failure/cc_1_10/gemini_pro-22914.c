//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

Person* create_person(const char* name, int age) {
    Person* person = malloc(sizeof(Person));
    if (person == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for person.\n");
        return NULL;
    }

    strncpy(person->name, name, MAX_NAME_LENGTH);
    person->age = age;

    return person;
}

void destroy_person(Person* person) {
    free(person);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Error: Invalid number of arguments.\n");
        fprintf(stderr, "Usage: %s <name> <age>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* name = argv[1];
    int age;
    if (sscanf(argv[2], "%d", &age) != 1) {
        fprintf(stderr, "Error: Invalid age argument.\n");
        fprintf(stderr, "Usage: %s <name> <age>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Person* person = create_person(name, age);
    if (person == NULL) {
        return EXIT_FAILURE;
    }

    printf("Person: %s (%d years old)\n", person->name, person->age);

    destroy_person(person);

    return EXIT_SUCCESS;
}