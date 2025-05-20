//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_FIELDS 100

typedef struct {
    char *name;
    int size;
} field_t;

typedef struct {
    int num_fields;
    field_t *fields;
} record_t;

record_t *read_metadata(FILE *file) {
    record_t *record = malloc(sizeof(record_t));
    record->num_fields = 0;
    record->fields = NULL;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') { // metadata line
            char *p = strchr(line, ':');
            if (p!= NULL) {
                p++; // skip ':'
                char *name = malloc(p - line + 1);
                strncpy(name, line, p - line);
                name[p - line] = '\0';

                int size = atoi(p);
                field_t *field = malloc(sizeof(field_t));
                field->name = name;
                field->size = size;
                record->fields = realloc(record->fields, sizeof(field_t) * ++record->num_fields);
                record->fields[record->num_fields - 1] = *field;
                free(field);
            }
        }
    }

    return record;
}

void print_metadata(record_t *record) {
    printf("Record:\n");
    for (int i = 0; i < record->num_fields; i++) {
        printf(" - %s (%d)\n", record->fields[i].name, record->fields[i].size);
    }
}

int main() {
    FILE *file = fopen("metadata.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    record_t *record = read_metadata(file);
    print_metadata(record);

    fclose(file);
    free(record->fields);
    free(record);

    return 0;
}