//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Metadata;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Metadata metadata;
        char *key = NULL;
        char *value = NULL;
        char *token = strtok(line, ": ");
        if (token!= NULL) {
            key = strdup(token);
            if (key == NULL) {
                printf("Out of memory.\n");
                return 1;
            }
        }
        token = strtok(NULL, ": ");
        if (token!= NULL) {
            value = strdup(token);
            if (value == NULL) {
                printf("Out of memory.\n");
                return 1;
            }
        }
        if (key!= NULL && value!= NULL) {
            strcpy(metadata.key, key);
            strcpy(metadata.value, value);
            printf("Key: %s\nValue: %s\n", metadata.key, metadata.value);
        }
        free(key);
        free(value);
    }

    fclose(file);
    return 0;
}