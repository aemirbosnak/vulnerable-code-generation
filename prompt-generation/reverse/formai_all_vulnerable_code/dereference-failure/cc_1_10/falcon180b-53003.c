//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUE_PAIRS 100

typedef struct {
    char key[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
} KeyValuePair;

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    char delimiter = ':';
    int numKeyValuePairs = 0;
    KeyValuePair keyValuePairs[MAX_KEY_VALUE_PAIRS];

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        char *key = strtok(line, &delimiter);
        char *value = strtok(NULL, &delimiter);

        if (key == NULL || value == NULL) {
            printf("Error: Invalid line format.\n");
            return 1;
        }

        strcpy(keyValuePairs[numKeyValuePairs].key, key);
        strcpy(keyValuePairs[numKeyValuePairs].value, value);
        numKeyValuePairs++;

        if (numKeyValuePairs == MAX_KEY_VALUE_PAIRS) {
            printf("Error: Reached maximum number of key-value pairs.\n");
            return 1;
        }
    }

    fclose(inputFile);

    printf("Metadata:\n");
    for (int i = 0; i < numKeyValuePairs; i++) {
        printf("%s: %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }

    return 0;
}