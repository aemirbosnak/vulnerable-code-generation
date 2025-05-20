//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 32
#define MAX_VALUE_LENGTH 256
#define MAX_NUM_KEY_VALUE_PAIRS 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} KeyValuePair;

int numKeyValuePairs = 0;
KeyValuePair keyValuePairs[MAX_NUM_KEY_VALUE_PAIRS];

void addKeyValuePair(char* key, char* value) {
    if (numKeyValuePairs >= MAX_NUM_KEY_VALUE_PAIRS) {
        printf("Error: Too many key-value pairs.\n");
        exit(1);
    }

    strncpy(keyValuePairs[numKeyValuePairs].key, key, MAX_KEY_LENGTH - 1);
    strncpy(keyValuePairs[numKeyValuePairs].value, value, MAX_VALUE_LENGTH - 1);

    numKeyValuePairs++;
}

void printKeyValuePairs() {
    printf("Key-Value Pairs:\n");
    for (int i = 0; i < numKeyValuePairs; i++) {
        printf("%s: %s\n", keyValuePairs[i].key, keyValuePairs[i].value);
    }
}

char* readLine(FILE* file) {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    char* line = readLine(inputFile);
    while (line!= NULL) {
        if (line[0] == '#') {
            // Comment line, skip
        } else if (line[0] == '[') {
            // Section header, start new metadata
            char* sectionNameEnd = strchr(line, ']');
            if (sectionNameEnd == NULL) {
                printf("Error: Invalid section header.\n");
                fclose(inputFile);
                fclose(outputFile);
                return 1;
            }
            *sectionNameEnd = '\0';
            sectionNameEnd++;

            addKeyValuePair(line + 1, sectionNameEnd);
        } else {
            // Key-value pair line
            char* equalsSign = strchr(line, '=');
            if (equalsSign == NULL) {
                printf("Error: Invalid key-value pair.\n");
                fclose(inputFile);
                fclose(outputFile);
                return 1;
            }
            *equalsSign = '\0';

            char* key = line;
            char* value = equalsSign + 1;

            while (isspace(*value)) {
                value++;
            }

            addKeyValuePair(key, value);
        }

        line = readLine(inputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printKeyValuePairs();

    return 0;
}