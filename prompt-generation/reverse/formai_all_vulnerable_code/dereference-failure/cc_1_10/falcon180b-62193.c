//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEYS 10
#define MAX_VALUES 50

typedef struct {
    char key[MAX_LINE_SIZE];
    char value[MAX_LINE_SIZE];
} metadata_t;

int main(int argc, char *argv[]) {
    char filename[MAX_LINE_SIZE];
    FILE *file;
    metadata_t metadata[MAX_KEYS];
    int num_metadata = 0;
    int i;

    // Get filename from command line argument
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    strcpy(filename, argv[1]);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read metadata from file
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *key = strtok(line, ":");
        if (key == NULL) {
            continue;
        }
        char *value = strtok(NULL, ":");
        if (value == NULL) {
            continue;
        }
        strcpy(metadata[num_metadata].key, key);
        strcpy(metadata[num_metadata].value, value);
        num_metadata++;
        if (num_metadata >= MAX_KEYS) {
            break;
        }
    }

    // Close file
    fclose(file);

    // Print metadata
    for (i = 0; i < num_metadata; i++) {
        printf("Key: %s\nValue: %s\n", metadata[i].key, metadata[i].value);
    }

    return 0;
}