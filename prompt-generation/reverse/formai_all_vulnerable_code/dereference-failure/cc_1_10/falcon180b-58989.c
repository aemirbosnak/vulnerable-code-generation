//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_FIELDS 100

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} record_t;

record_t *parse_record(char *line) {
    record_t *record = malloc(sizeof(record_t));
    record->num_fields = 0;
    record->fields = NULL;

    char *token = strtok(line, ",");
    while (token!= NULL) {
        field_t *field = malloc(sizeof(field_t));
        field->name = strdup(token);
        field->value = strdup("");
        record->fields = realloc(record->fields, sizeof(field_t) * ++record->num_fields);
        record->fields[record->num_fields - 1] = *field;
        free(field);

        token = strtok(NULL, ",");
    }

    return record;
}

void print_record(record_t *record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s: %s\n", record->fields[i].name, record->fields[i].value);
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        record_t *record = parse_record(line);
        print_record(record);
        free(record->fields);
        free(record);
    }

    fclose(fp);
    return 0;
}