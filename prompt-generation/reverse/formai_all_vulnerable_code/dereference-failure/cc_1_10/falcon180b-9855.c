//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_LINE_LEN 1024

typedef struct {
    char *key;
    char *value;
} metadata_t;

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char file_name[MAX_FILE_NAME_LEN];
    strncpy(file_name, argv[1], MAX_FILE_NAME_LEN - 1);
    file_name[MAX_FILE_NAME_LEN - 1] = '\0';

    metadata_t metadata;
    metadata.key = malloc(MAX_LINE_LEN);
    metadata.value = malloc(MAX_LINE_LEN);

    while (fgets(metadata.key, MAX_LINE_LEN, fp)!= NULL) {
        char *equal_pos = strchr(metadata.key, '=');
        if (equal_pos == NULL) {
            printf("Invalid metadata key in file: %s\n", file_name);
            fclose(fp);
            free(metadata.key);
            free(metadata.value);
            return 1;
        }

        *equal_pos = '\0';
        metadata.value = strdup(equal_pos + 1);

        printf("Metadata key: %s\n", metadata.key);
        printf("Metadata value: %s\n\n", metadata.value);
    }

    fclose(fp);
    free(metadata.key);
    free(metadata.value);
    return 0;
}