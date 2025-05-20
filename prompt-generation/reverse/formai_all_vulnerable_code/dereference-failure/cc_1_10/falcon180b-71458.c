//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 64

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} metadata_t;

metadata_t *metadata_create() {
    metadata_t *metadata = (metadata_t *)malloc(sizeof(metadata_t));
    metadata->fields = NULL;
    metadata->num_fields = 0;
    return metadata;
}

void metadata_destroy(metadata_t *metadata) {
    int i;
    for (i = 0; i < metadata->num_fields; i++) {
        free(metadata->fields[i].name);
        free(metadata->fields[i].value);
    }
    free(metadata->fields);
    free(metadata);
}

void metadata_add_field(metadata_t *metadata, const char *name, const char *value) {
    field_t *field = (field_t *)malloc(sizeof(field_t));
    field->name = strdup(name);
    field->value = strdup(value);
    metadata->fields = (field_t *)realloc(metadata->fields, sizeof(field_t) * (metadata->num_fields + 1));
    metadata->fields[metadata->num_fields] = *field;
    metadata->num_fields++;
}

void metadata_print(const metadata_t *metadata) {
    int i;
    for (i = 0; i < metadata->num_fields; i++) {
        printf("%s: %s\n", metadata->fields[i].name, metadata->fields[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *token;
    char *name;
    char *value;
    metadata_t *metadata = metadata_create();

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        token = strtok(line, ":");
        while (token!= NULL) {
            name = strtok(NULL, ":");
            value = strtok(NULL, ":");
            if (name!= NULL && value!= NULL) {
                metadata_add_field(metadata, name, value);
            }
            token = strtok(NULL, ":");
        }
    }

    metadata_print(metadata);
    metadata_destroy(metadata);
    return 0;
}