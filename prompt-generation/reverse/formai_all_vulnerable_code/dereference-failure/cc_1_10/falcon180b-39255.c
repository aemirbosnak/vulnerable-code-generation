//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUE_PAIRS 100

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;
    int numKeyValuePairs = 0;
    KeyValuePair *keyValuePairs = NULL;

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        lineNumber++;

        // Check for metadata in the form of "key: value"
        char *metadata = strstr(line, ": ");
        if (metadata!= NULL) {
            // Extract key-value pair
            char *key = line;
            char *value = metadata + 2;

            // Add to array of key-value pairs
            if (numKeyValuePairs >= MAX_KEY_VALUE_PAIRS) {
                fprintf(stderr, "Error: too many key-value pairs (line %d)\n", lineNumber);
                exit(1);
            }
            keyValuePairs = realloc(keyValuePairs, sizeof(KeyValuePair) * (numKeyValuePairs + 1));
            keyValuePairs[numKeyValuePairs].key = strdup(key);
            keyValuePairs[numKeyValuePairs].value = strdup(value);
            numKeyValuePairs++;
        }
    }

    fclose(inputFile);

    if (numKeyValuePairs == 0) {
        fprintf(stderr, "Error: no metadata found in file '%s'\n", argv[1]);
        exit(1);
    }

    // Print extracted metadata
    printf("Metadata:\n");
    for (int i = 0; i < numKeyValuePairs; i++) {
        printf("%s: %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }

    // Free memory
    for (int i = 0; i < numKeyValuePairs; i++) {
        free(keyValuePairs[i].key);
        free(keyValuePairs[i].value);
    }
    free(keyValuePairs);

    return 0;
}