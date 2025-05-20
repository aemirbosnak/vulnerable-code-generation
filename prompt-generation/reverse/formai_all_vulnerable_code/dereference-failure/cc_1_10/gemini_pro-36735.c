//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct {
    char *fields[MAX_NUM_FIELDS];
    int num_fields;
} CSVRecord;

CSVRecord *parse_csv_line(char *line) {
    CSVRecord *record = malloc(sizeof(CSVRecord));
    record->num_fields = 0;

    char *field = strtok(line, ",");
    while (field) {
        record->fields[record->num_fields++] = strdup(field);
        field = strtok(NULL, ",");
    }

    return record;
}

void free_csv_record(CSVRecord *record) {
    for (int i = 0; i < record->num_fields; i++) {
        free(record->fields[i]);
    }
    free(record);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        CSVRecord *record = parse_csv_line(line);

        // Process the record here

        free_csv_record(record);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}