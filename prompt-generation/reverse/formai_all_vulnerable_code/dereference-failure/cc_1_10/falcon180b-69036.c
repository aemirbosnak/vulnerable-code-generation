//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 256

// Struct to hold metadata information
typedef struct {
    char* key;
    char* value;
} Metadata;

// Function to extract metadata from a line of text
void extractMetadata(char* line, Metadata* metadata) {
    char* key = NULL;
    char* value = NULL;

    // Extract key
    key = strtok(line, ":");

    // Extract value
    value = strtok(NULL, "\n");

    // Remove leading/trailing spaces from key/value
    while (isspace(*value)) {
        value++;
    }
    while (isspace(*key)) {
        key++;
    }

    // Allocate memory for key/value and copy strings
    metadata->key = malloc(strlen(key) + 1);
    strcpy(metadata->key, key);

    metadata->value = malloc(strlen(value) + 1);
    strcpy(metadata->value, value);
}

// Function to print metadata
void printMetadata(Metadata* metadata) {
    printf("Key: %s\nValue: %s\n", metadata->key, metadata->value);
}

// Function to free metadata memory
void freeMetadata(Metadata* metadata) {
    free(metadata->key);
    free(metadata->value);
}

int main() {
    FILE* file;
    char line[MAX_LINE_SIZE];
    Metadata metadata;

    // Open file for reading
    file = fopen("example.txt", "r");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read lines from file and extract metadata
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        extractMetadata(line, &metadata);
        printMetadata(&metadata);
        freeMetadata(&metadata);
    }

    // Close file
    fclose(file);

    return 0;
}