//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 1024
#define MAX_TOKEN_LEN 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

int parse_metadata(char *line, metadata_t *metadata) {
    int i = 0;
    char *token, *value = NULL;
    metadata->name = strdup("");
    metadata->value = strdup("");

    token = strtok(line, ":");
    if (token == NULL) {
        return -1;
    }
    strcpy(metadata->name, token);

    value = strtok(NULL, ":");
    if (value == NULL) {
        return -1;
    }
    strcpy(metadata->value, value);

    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LEN];
    metadata_t metadata;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (parse_metadata(line, &metadata) == 0) {
            printf("Name: %s\nValue: %s\n\n", metadata.name, metadata.value);
        }
    }

    fclose(fp);
    return 0;
}