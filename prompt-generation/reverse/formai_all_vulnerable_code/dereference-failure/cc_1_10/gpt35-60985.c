//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FIELDS 20

typedef struct record {
    char **fields;
    int field_count;
} Record;

Record* create_record(int field_count) {
    Record *record = malloc(sizeof(Record));
    record->field_count = field_count;
    record->fields = malloc(field_count * sizeof(char *));
    for (int i = 0; i < field_count; i++) {
        record->fields[i] = malloc(BUFFER_SIZE * sizeof(char));
    }
    return record;
}

void destroy_record(Record *record) {
    for (int i = 0; i < record->field_count; i++) {
        free(record->fields[i]);
    }
    free(record->fields);
    free(record);
}

typedef struct csv_reader {
    FILE* file;
    char delimiter;
} CSVReader;

CSVReader* create_csv_reader(char* filename, char delimiter) {
    CSVReader *csv_reader = malloc(sizeof(CSVReader));
    csv_reader->file = fopen(filename, "r");
    if (csv_reader->file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }
    csv_reader->delimiter = delimiter;
    return csv_reader;
}

void destroy_csv_reader(CSVReader *csv_reader) {
    fclose(csv_reader->file);
    free(csv_reader);
}

char* read_field(FILE *file, char delimiter) {
    char *field = malloc(BUFFER_SIZE * sizeof(char));
    int i = 0;
    char c = fgetc(file);
    while (c != EOF && c != delimiter && c != '\n') {
        field[i++] = c;
        c = fgetc(file);
    }
    field[i] = '\0';
    return field;
}

Record* read_record(CSVReader *csv_reader) {
    FILE *file = csv_reader->file;
    char delimiter = csv_reader->delimiter;

    Record *record = create_record(MAX_FIELDS);
    char *field = read_field(file, delimiter);
    int i = 0;
    while (field != NULL && i < MAX_FIELDS) {
        strcpy(record->fields[i++], field);
        free(field);
        field = read_field(file, delimiter);
    }
    if (field != NULL) {
        free(field);
    }
    record->field_count = i;
    return record;
}

int main() {
    CSVReader *csv_reader = create_csv_reader("data.csv", ',');
    Record *record = read_record(csv_reader);
    while (record != NULL) {
        for (int i = 0; i < record->field_count; i++) {
            printf("%s ", record->fields[i]);
        }
        printf("\n");
        destroy_record(record);
        record = read_record(csv_reader);
    }
    destroy_csv_reader(csv_reader);
    return 0;
}