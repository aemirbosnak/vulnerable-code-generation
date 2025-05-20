//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} metadata_t;

metadata_t *metadata_create(const char *key, const char *value) {
    metadata_t *md = malloc(sizeof(metadata_t));
    strncpy(md->key, key, MAX_KEY_LENGTH);
    strncpy(md->value, value, MAX_VALUE_LENGTH);
    return md;
}

void metadata_destroy(metadata_t *md) {
    free(md);
}

void metadata_print(const metadata_t *md) {
    printf("Key: %s\nValue: %s\n", md->key, md->value);
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    metadata_t *md;

    // Open file
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read file
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        // Extract key-value pair
        key = strtok(line, ":");
        value = strtok(NULL, ":");

        // Create metadata object
        md = metadata_create(key, value);

        // Print metadata object
        metadata_print(md);

        // Destroy metadata object
        metadata_destroy(md);
    }

    // Close file
    fclose(fp);

    return 0;
}