//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    metadata_t *metadata = NULL;
    int num_metadata = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        key = strtok(line, ":");
        if (key == NULL) {
            continue;
        }
        value = strtok(NULL, "\n");
        if (value == NULL) {
            continue;
        }
        value[strcspn(value, "\n")] = '\0'; // remove newline character

        // check if key already exists
        int i;
        for (i = 0; i < num_metadata; i++) {
            if (strcmp(metadata[i].key, key) == 0) {
                break;
            }
        }
        if (i == num_metadata) {
            // key does not exist, add new metadata
            metadata = realloc(metadata, sizeof(metadata_t) * (num_metadata + 1));
            metadata[num_metadata].key = strdup(key);
            metadata[num_metadata].value = strdup(value);
            num_metadata++;
        } else {
            // key already exists, overwrite value
            free(metadata[i].value);
            metadata[i].value = strdup(value);
        }
    }

    fclose(fp);

    // print metadata
    for (int i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    free(metadata);
    return 0;
}