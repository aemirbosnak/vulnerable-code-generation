//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256

typedef struct {
    char *name;
    int age;
    char *occupation;
} person_t;

person_t *create_person(char *name, int age, char *occupation) {
    person_t *person = malloc(sizeof(person_t));
    if (person == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for person.\n");
        return NULL;
    }

    person->name = malloc(strlen(name) + 1);
    if (person->name == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for person's name.\n");
        free(person);
        return NULL;
    }
    strcpy(person->name, name);

    person->age = age;

    person->occupation = malloc(strlen(occupation) + 1);
    if (person->occupation == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for person's occupation.\n");
        free(person->name);
        free(person);
        return NULL;
    }
    strcpy(person->occupation, occupation);

    return person;
}

void free_person(person_t *person) {
    free(person->name);
    free(person->occupation);
    free(person);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments was provided.
    if (argc != 4) {
        fprintf(stderr, "Error: Incorrect number of arguments.\n");
        fprintf(stderr, "Usage: %s <name> <age> <occupation>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Check if the age argument is a valid integer.
    int age;
    if (sscanf(argv[2], "%d", &age) != 1) {
        fprintf(stderr, "Error: Invalid age argument.\n");
        return EXIT_FAILURE;
    }

    // Check if the name argument is too long.
    if (strlen(argv[1]) > MAX_NAME_LENGTH) {
        fprintf(stderr, "Error: Name argument is too long.\n");
        return EXIT_FAILURE;
    }

    // Create a person struct using the provided arguments.
    person_t *person = create_person(argv[1], age, argv[3]);
    if (person == NULL) {
        return EXIT_FAILURE;
    }

    // Print the person's information.
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);

    // Free the memory allocated for the person struct.
    free_person(person);

    return EXIT_SUCCESS;
}