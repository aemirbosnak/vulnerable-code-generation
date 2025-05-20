//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_FIELD_LENGTH 50

typedef struct {
    char *field;
    int field_length;
} Field;

typedef struct {
    int num_fields;
    Field fields[MAX_FIELDS];
} Metadata;

Metadata* extract_metadata(FILE *file) {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->num_fields = 0;

    char line[MAX_FIELD_LENGTH];
    while (fgets(line, MAX_FIELD_LENGTH, file)) {
        if (metadata->num_fields == MAX_FIELDS) {
            printf("Error: Reached max number of fields\n");
            exit(1);
        }

        Field *field = malloc(sizeof(Field));
        field->field = malloc(strlen(line) + 1);
        strcpy(field->field, line);
        field->field_length = strlen(field->field);

        metadata->fields[metadata->num_fields] = *field;
        metadata->num_fields++;
    }

    return metadata;
}

void print_metadata(Metadata *metadata) {
    for (int i = 0; i < metadata->num_fields; i++) {
        printf("Field %d: %s\n", i + 1, metadata->fields[i].field);
    }
}

int main() {
    FILE *file = fopen("metadata.txt", "r");

    Metadata *metadata = extract_metadata(file);

    print_metadata(metadata);

    free(metadata->fields);
    free(metadata);

    return 0;
}