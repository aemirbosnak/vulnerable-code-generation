//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 256

typedef struct {
    char *key;
    char *value;
} metadata_t;

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *key, *value;
    metadata_t metadata;

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    metadata.key = NULL;
    metadata.value = NULL;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        key = line;
        value = strchr(line, ':');
        if (value == NULL) {
            printf("Error: invalid metadata format.\n");
            exit(1);
        }

        *value = '\0';
        value++;
        while (isspace(*value)) {
            value++;
        }

        if (metadata.key!= NULL) {
            free(metadata.key);
            free(metadata.value);
        }

        metadata.key = strdup(key);
        metadata.value = strdup(value);

        printf("Key: %s\nValue: %s\n\n", metadata.key, metadata.value);
    }

    fclose(fp);

    free(metadata.key);
    free(metadata.value);

    return 0;
}