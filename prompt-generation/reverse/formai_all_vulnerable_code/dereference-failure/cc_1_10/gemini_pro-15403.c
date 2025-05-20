//GEMINI-pro DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    char *occupation;
} person_t;

void print_person(person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);
}

int main() {
    // Create a file pointer
    FILE *file = fopen("people.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file line by line
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the line into a person struct
        char *name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        char *occupation = strtok(NULL, ",");

        // Create a new person struct
        person_t *person = malloc(sizeof(person_t));
        person->name = strdup(name);
        person->age = age;
        person->occupation = strdup(occupation);

        // Print the person struct
        print_person(person);

        // Free the memory allocated for the person struct
        free(person->name);
        free(person->occupation);
        free(person);
    }

    // Close the file
    fclose(file);

    return EXIT_SUCCESS;
}