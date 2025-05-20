//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char* name;
    char* value;
} metadata_t;

metadata_t* parse_metadata(char* line) {
    char* name_start = strchr(line, ':');
    if (name_start == NULL) {
        return NULL;
    }

    *name_start = '\0';
    char* name = strdup(line);
    char* value_start = name_start + 1;
    char* value = strdup(value_start);

    metadata_t* meta = malloc(sizeof(metadata_t));
    meta->name = name;
    meta->value = value;

    return meta;
}

void print_metadata(metadata_t* meta) {
    printf("Name: %s\nValue: %s\n", meta->name, meta->value);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        metadata_t* meta = parse_metadata(line);
        if (meta!= NULL) {
            print_metadata(meta);
            free(meta->name);
            free(meta->value);
            free(meta);
        }
    }

    fclose(file);
    return 0;
}