//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYS 100
#define MAX_VALUES 100

typedef struct {
    char *key;
    char *value;
} KeyValue;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <metadata file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int num_keys = 0;
    KeyValue keys[MAX_KEYS];

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *key, *value;
        if (sscanf(line, "%s=%s", key, value) == 2) {
            if (num_keys >= MAX_KEYS) {
                printf("Error: Too many keys in metadata file\n");
                fclose(fp);
                return 1;
            }

            keys[num_keys].key = strdup(key);
            keys[num_keys].value = strdup(value);
            num_keys++;
        }
    }

    fclose(fp);

    printf("Metadata:\n");
    for (int i = 0; i < num_keys; i++) {
        printf("%s: %s\n", keys[i].key, keys[i].value);
    }

    for (int i = 0; i < num_keys; i++) {
        free(keys[i].key);
        free(keys[i].value);
    }

    return 0;
}