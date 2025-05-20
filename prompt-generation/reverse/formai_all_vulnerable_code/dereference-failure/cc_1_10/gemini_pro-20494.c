//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *email;
} person_t;

int main(int argc, char **argv) {
    person_t person;

    // Parse command line arguments.
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <name> <age> <email>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Allocate memory for the person's name.
    person.name = malloc(strlen(argv[1]) + 1);
    if (person.name == NULL) {
        fprintf(stderr, "Error allocating memory for person's name.\n");
        return EXIT_FAILURE;
    }

    // Copy the person's name from the command line argument.
    strcpy(person.name, argv[1]);

    // Parse the person's age.
    person.age = atoi(argv[2]);

    // Allocate memory for the person's email address.
    person.email = malloc(strlen(argv[3]) + 1);
    if (person.email == NULL) {
        fprintf(stderr, "Error allocating memory for person's email address.\n");
        return EXIT_FAILURE;
    }

    // Copy the person's email address from the command line argument.
    strcpy(person.email, argv[3]);

    // Print the person's information.
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Email: %s\n", person.email);

    // Free the memory allocated for the person's name and email address.
    free(person.name);
    free(person.email);

    return EXIT_SUCCESS;
}