//Falcon2-11B DATASET v1.0 Category: Metadata Extractor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the metadata
typedef struct {
    char *name;
    int age;
    float height;
} Person;

// Function to read the metadata from a file
Person *read_metadata(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s' for reading.\n", filename);
        exit(1);
    }

    Person *metadata = malloc(sizeof(Person));
    if (metadata == NULL) {
        printf("Error: Out of memory.\n");
        exit(1);
    }

    fscanf(file, "%s %d %f", metadata->name, &metadata->age, &metadata->height);

    fclose(file);

    return metadata;
}

// Function to write the metadata to a file
void write_metadata(char *filename, Person *metadata) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file '%s' for writing.\n", filename);
        exit(1);
    }

    fprintf(file, "%s %d %f\n", metadata->name, metadata->age, metadata->height);

    fclose(file);
}

// Function to display the metadata
void display_metadata(Person *metadata) {
    printf("Name: %s\n", metadata->name);
    printf("Age: %d\n", metadata->age);
    printf("Height: %f\n", metadata->height);
}

// Function to extract metadata from a file and display it
void extract_and_display_metadata(char *filename) {
    Person *metadata = read_metadata(filename);
    if (metadata == NULL) {
        printf("Error: Unable to extract metadata from file '%s'.\n", filename);
        return;
    }

    display_metadata(metadata);
    free(metadata);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    extract_and_display_metadata(argv[1]);

    return 0;
}