//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Curious Metadata Extractor (CME) v0.0.1

typedef struct {
    char name[32];
    int age;
    float height;
} Person;

void extract_person_metadata(const char* buffer, size_t size, Person* person) {
    // Curious parsing logic
    if (size < 40) {
        printf("Buffer too small for person metadata.\n");
        return;
    }

    strncpy(person->name, buffer, sizeof(person->name) - 1);
    person->name[sizeof(person->name) - 1] = '\0';

    if (sscanf(buffer + strlen(person->name), "%d %f", &person->age, &person->height) != 2) {
        printf("Invalid person metadata format.\n");
        return;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <binary_data>\n", argv[0]);
        return 1;
    }

    // Allocate memory for person metadata
    Person person;
    size_t buffer_size = strlen(argv[1]) + 1;
    char* buffer = malloc(buffer_size);

    // Read binary data into buffer
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Could not open binary file.\n");
        free(buffer);
        return 1;
    }
    fread(buffer, 1, buffer_size, file);
    fclose(file);

    // Extract person metadata
    extract_person_metadata(buffer, buffer_size, &person);

    // Print extracted metadata
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Height: %.2f\n", person.height);

    // Free allocated memory
    free(buffer);

    return 0;
}