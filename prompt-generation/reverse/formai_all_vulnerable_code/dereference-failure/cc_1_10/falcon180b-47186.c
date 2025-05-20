//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FIELDS 100
#define MAX_FIELD_LEN 100

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} metadata_t;

metadata_t *parse_metadata(char *metadata_str) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->num_fields = 0;
    metadata->fields = NULL;

    char *cur_field = strtok(metadata_str, ",");
    while (cur_field!= NULL) {
        field_t *field = malloc(sizeof(field_t));
        field->name = strdup(cur_field);
        field->value = strdup("");
        metadata->fields = realloc(metadata->fields, sizeof(field_t) * ++metadata->num_fields);
        metadata->fields[metadata->num_fields - 1] = *field;
        cur_field = strtok(NULL, ",");
    }

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_fields; i++) {
        printf("%s: %s\n", metadata->fields[i].name, metadata->fields[i].value);
    }
}

void free_metadata(metadata_t *metadata) {
    for (int i = 0; i < metadata->num_fields; i++) {
        free(metadata->fields[i].name);
        free(metadata->fields[i].value);
    }
    free(metadata->fields);
    free(metadata);
}

int main() {
    char *metadata_str = "Author: John Doe,Title: The Catcher in the Rye,Genre: Fiction";
    metadata_t *metadata = parse_metadata(metadata_str);
    print_metadata(metadata);
    free_metadata(metadata);
    return 0;
}