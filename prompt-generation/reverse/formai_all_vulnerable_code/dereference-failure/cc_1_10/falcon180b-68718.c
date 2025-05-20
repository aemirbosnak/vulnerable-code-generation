//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define a metadata structure
typedef struct {
    char* name;
    int age;
    float height;
    char* occupation;
} PersonMetadata;

// Function to extract person metadata from a given text file
PersonMetadata extractPersonMetadata(FILE* file) {
    PersonMetadata metadata = {NULL, 0, 0.0, NULL};
    char line[1024];
    char* token;

    // Extract name
    fgets(line, sizeof(line), file);
    token = strtok(line, ",");
    metadata.name = strdup(token);

    // Extract age
    fgets(line, sizeof(line), file);
    token = strtok(line, ",");
    metadata.age = atoi(token);

    // Extract height
    fgets(line, sizeof(line), file);
    token = strtok(line, ",");
    metadata.height = atof(token);

    // Extract occupation
    fgets(line, sizeof(line), file);
    token = strtok(line, ",");
    metadata.occupation = strdup(token);

    return metadata;
}

// Function to print person metadata
void printPersonMetadata(PersonMetadata metadata) {
    printf("Name: %s\n", metadata.name);
    printf("Age: %d\n", metadata.age);
    printf("Height: %f\n", metadata.height);
    printf("Occupation: %s\n", metadata.occupation);
}

// Main function
int main() {
    FILE* file = fopen("person.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    PersonMetadata metadata = extractPersonMetadata(file);
    printPersonMetadata(metadata);

    fclose(file);
    return 0;
}