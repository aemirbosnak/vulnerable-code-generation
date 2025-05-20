//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128
#define MAX_FIELDS_PER_LINE 10

typedef struct {
    char **fields;
    int num_fields;
} CsvRecord;

CsvRecord* read_csv_record(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    if (!fgets(line, MAX_LINE_LENGTH, fp)) {
        return NULL;
    }

    CsvRecord *record = malloc(sizeof(CsvRecord));
    record->num_fields = 0;
    record->fields = malloc(sizeof(char*) * MAX_FIELDS_PER_LINE);

    const char *delim = ",";
    char *field = strtok(line, delim);
    while (field != NULL) {
        if (record->num_fields == MAX_FIELDS_PER_LINE) {
            fprintf(stderr, "Error: too many fields in csv record\n");
            exit(1);
        }

        int field_len = strlen(field);
        if (field[field_len-1] == '\n') {
            field[field_len-1] = '\0';
        }

        record->fields[record->num_fields] = malloc(sizeof(char) * MAX_FIELD_LENGTH);
        strcpy(record->fields[record->num_fields], field);

        record->num_fields++;

        field = strtok(NULL, delim);
    }

    return record;
}

void free_csv_record(CsvRecord *record) {
    for (int i = 0; i < record->num_fields; i++) {
        free(record->fields[i]);
    }
    free(record->fields);
    free(record);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", argv[1]);
        exit(1);
    }

    while (1) {
        CsvRecord *record = read_csv_record(input_file);
        if (record == NULL) {
            break;
        }

        printf("Record has %d fields:\n", record->num_fields);
        for (int i = 0; i < record->num_fields; i++) {
            printf("\tField %d: %s\n", i, record->fields[i]);
        }

        free_csv_record(record);
    }

    fclose(input_file);

    return 0;
}