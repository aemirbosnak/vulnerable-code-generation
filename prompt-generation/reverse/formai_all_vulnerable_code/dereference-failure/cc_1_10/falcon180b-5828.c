//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    int num_fields;
    field_t *fields;
} metadata_t;

metadata_t *metadata_create() {
    metadata_t *meta = (metadata_t *)malloc(sizeof(metadata_t));
    meta->num_fields = 0;
    meta->fields = NULL;
    return meta;
}

void metadata_destroy(metadata_t *meta) {
    for (int i = 0; i < meta->num_fields; i++) {
        free(meta->fields[i].name);
        free(meta->fields[i].value);
    }
    free(meta->fields);
    free(meta);
}

field_t *metadata_add_field(metadata_t *meta, char *name, char *value) {
    field_t *field = (field_t *)malloc(sizeof(field_t));
    field->name = strdup(name);
    field->value = strdup(value);
    meta->fields = (field_t *)realloc(meta->fields, sizeof(field_t) * (meta->num_fields + 1));
    meta->fields[meta->num_fields++] = *field;
    return &meta->fields[meta->num_fields - 1];
}

int metadata_get_field_index(metadata_t *meta, char *name) {
    for (int i = 0; i < meta->num_fields; i++) {
        if (strcmp(meta->fields[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void metadata_print(metadata_t *meta) {
    printf("Metadata:\n");
    for (int i = 0; i < meta->num_fields; i++) {
        printf("%s: %s\n", meta->fields[i].name, meta->fields[i].value);
    }
}

void metadata_save(metadata_t *meta, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }
    for (int i = 0; i < meta->num_fields; i++) {
        fprintf(fp, "%s: %s\n", meta->fields[i].name, meta->fields[i].value);
    }
    fclose(fp);
}

int main() {
    metadata_t *meta = metadata_create();

    meta->fields = (field_t *)malloc(sizeof(field_t) * 2);
    meta->num_fields = 2;
    metadata_add_field(meta, "Author", "John Doe");
    metadata_add_field(meta, "Title", "My Book");

    metadata_print(meta);

    metadata_save(meta, "metadata.txt");

    return 0;
}