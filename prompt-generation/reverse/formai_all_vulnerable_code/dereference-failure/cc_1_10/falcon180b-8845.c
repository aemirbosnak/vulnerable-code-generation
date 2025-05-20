//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
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

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    metadata_t metadata;
    int key_index = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <metadata_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (key_index == 0) {
            strcpy(metadata.key, line);
        } else if (key_index == 1) {
            strcpy(metadata.value, line);
            break;
        }
        key_index++;
    }

    if (key_index!= 2) {
        fprintf(stderr, "Invalid metadata format\n");
        exit(1);
    }

    printf("Metadata:\n");
    printf("Key: %s\n", metadata.key);
    printf("Value: %s\n", metadata.value);

    fclose(fp);
    return 0;
}