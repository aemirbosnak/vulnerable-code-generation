//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    int num_fields;
    field_t fields[MAX_FIELDS];
} record_t;

void add_field(record_t *record, char *name, char *value) {
    if (record->num_fields >= MAX_FIELDS) {
        printf("Error: Too many fields in record.\n");
        exit(1);
    }

    record->fields[record->num_fields].name = strdup(name);
    record->fields[record->num_fields].value = strdup(value);

    record->num_fields++;
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *token;
    record_t record = { 0 };

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            printf("Error: Invalid line format.\n");
            exit(1);
        }

        add_field(&record, token, strtok(NULL, ":"));
    }

    printf("Name: %s\n", record.fields[0].value);
    printf("Email: %s\n", record.fields[1].value);
    printf("Phone: %s\n", record.fields[2].value);

    for (int i = 3; i < record.num_fields; i++) {
        printf("Custom Field %d: %s\n", i - 2, record.fields[i].value);
    }

    return 0;
}