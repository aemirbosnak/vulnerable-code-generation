//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 32
#define MAX_VALUE_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} metadata_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int num_metadata = 0;
    metadata_t *metadata = NULL;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        if (key == NULL || value == NULL) {
            continue;
        }

        if (num_metadata >= MAX_KEY_SIZE) {
            printf("Error: Too many metadata.\n");
            fclose(fp);
            return 1;
        }

        strncpy(metadata[num_metadata].key, key, MAX_KEY_SIZE - 1);
        strncpy(metadata[num_metadata].value, value, MAX_VALUE_SIZE - 1);

        num_metadata++;
    }

    fclose(fp);

    printf("Number of metadata: %d\n", num_metadata);

    for (int i = 0; i < num_metadata; i++) {
        printf("Key: %s, Value: %s\n", metadata[i].key, metadata[i].value);
    }

    free(metadata);

    return 0;
}