//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} metadata_t;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    char *key = NULL;
    char *value = NULL;
    metadata_t metadata;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Check if line is a metadata
        if (line[0] == '#') {
            // Extract key-value pair
            char *ptr = strchr(line, ':');
            if (ptr == NULL) {
                fprintf(stderr, "Invalid metadata format: %s\n", line);
                exit(1);
            }
            *ptr = '\0';
            key = strtok(line, ": \t");
            value = strtok(NULL, ": \t");

            // Add metadata to list
            strncpy(metadata.key, key, MAX_KEY_SIZE);
            strncpy(metadata.value, value, MAX_VALUE_SIZE);
            metadata.key[MAX_KEY_SIZE - 1] = '\0';
            metadata.value[MAX_VALUE_SIZE - 1] = '\0';

            printf("Key: %s\nValue: %s\n\n", metadata.key, metadata.value);
        }
    }

    fclose(file);
    return 0;
}