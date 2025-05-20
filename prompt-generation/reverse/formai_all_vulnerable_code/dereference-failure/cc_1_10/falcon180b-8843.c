//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *name;
    char *value;
} metadata_t;

int is_metadata(char *line) {
    if (strncmp(line, "metadata", strlen("metadata")) == 0) {
        return 1;
    }
    return 0;
}

int is_name_value(char *line) {
    if (strncmp(line, "name=", strlen("name=")) == 0) {
        return 1;
    }
    if (strncmp(line, "value=", strlen("value=")) == 0) {
        return 1;
    }
    return 0;
}

void parse_metadata(char *line, metadata_t *metadata) {
    if (is_name_value(line)) {
        char *key = line + strlen("name=") + 1;
        char *value = line + strlen("value=") + 1;
        if (strlen(key) > MAX_WORD_LENGTH || strlen(value) > MAX_WORD_LENGTH) {
            printf("Error: Metadata key or value too long\n");
            exit(1);
        }
        metadata->name = strdup(key);
        metadata->value = strdup(value);
    } else if (is_metadata(line)) {
        metadata->name = strdup("");
        metadata->value = strdup("");
    }
}

void print_metadata(metadata_t *metadata) {
    if (metadata->name == NULL || metadata->value == NULL) {
        printf("Error: Invalid metadata\n");
        exit(1);
    }
    printf("Name: %s\nValue: %s\n", metadata->name, metadata->value);
}

int main() {
    char line[MAX_LINE_LENGTH];
    metadata_t metadata;
    metadata.name = NULL;
    metadata.value = NULL;

    FILE *file = fopen("metadata.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open metadata file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        parse_metadata(line, &metadata);
        print_metadata(&metadata);
    }

    fclose(file);
    return 0;
}