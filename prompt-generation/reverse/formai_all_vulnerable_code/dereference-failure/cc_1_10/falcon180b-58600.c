//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_VALUE_PAIRS 100

typedef struct {
    char* key;
    char* value;
} KeyValuePair;

int main(int argc, char** argv) {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    KeyValuePair keyValuePairs[MAX_KEY_VALUE_PAIRS];
    int numKeyValuePairs = 0;

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, ":");

        if (key == NULL || value == NULL) {
            printf("Error: Invalid line format\n");
            exit(1);
        }

        if (numKeyValuePairs >= MAX_KEY_VALUE_PAIRS) {
            printf("Error: Maximum number of key-value pairs exceeded\n");
            exit(1);
        }

        keyValuePairs[numKeyValuePairs].key = strdup(key);
        keyValuePairs[numKeyValuePairs].value = strdup(value);
        numKeyValuePairs++;
    }

    fclose(inputFile);

    printf("Key-Value Pairs:\n");
    for (int i = 0; i < numKeyValuePairs; i++) {
        printf("Key: %s\nValue: %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }

    for (int i = 0; i < numKeyValuePairs; i++) {
        free(keyValuePairs[i].key);
        free(keyValuePairs[i].value);
    }

    return 0;
}