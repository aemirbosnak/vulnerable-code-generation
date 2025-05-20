//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *data;
    int size;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} record_t;

record_t *records = NULL;
int num_records = 0;

void add_field(field_t *field) {
    field->data = malloc(MAX_FIELD_SIZE);
    field->size = 0;
}

void add_record() {
    record_t *new_record = malloc(sizeof(record_t));
    new_record->num_fields = 0;
    new_record->fields = malloc(MAX_RECORDS * sizeof(field_t));
    records = realloc(records, sizeof(record_t) * ++num_records);
    records[num_records - 1] = *new_record;
    free(new_record);
}

void add_char(char c) {
    if (records[num_records - 1].num_fields >= MAX_RECORDS) {
        add_record();
    }
    field_t *current_field = &records[num_records - 1].fields[records[num_records - 1].num_fields - 1];
    if (current_field->size >= MAX_FIELD_SIZE) {
        current_field->data = realloc(current_field->data, MAX_FIELD_SIZE * 2);
    }
    current_field->data[current_field->size++] = c;
}

void add_string(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        add_char(str[i]);
    }
    add_char('\0');
}

void print_record(int index) {
    for (int i = 0; i < records[index].num_fields; i++) {
        field_t *field = &records[index].fields[i];
        printf("%s", field->data);
    }
    printf("\n");
}

int main() {
    add_record();
    add_string("John Doe");
    add_string("123 Main St.");
    print_record(0);
    add_record();
    add_string("Jane Smith");
    add_string("456 Elm Ave.");
    print_record(1);
    return 0;
}