//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CSVRecord;

CSVRecord *read_csv_file(FILE *fp) {
    CSVRecord *record = NULL;
    char line[MAX_LINE_SIZE];
    char *token;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        record = realloc(record, sizeof(CSVRecord) + (num_fields + 1) * sizeof(char *));
        record->num_fields = num_fields;
        token = strtok(line, ",");
        while (token!= NULL) {
            record->fields[num_fields++] = strdup(token);
            token = strtok(NULL, ",");
        }
        record->fields[num_fields] = NULL;
    }

    return record;
}

void print_csv_record(CSVRecord *record) {
    int i;

    for (i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
    }
    printf("\n");
}

void free_csv_record(CSVRecord *record) {
    int i;

    for (i = 0; i < record->num_fields; i++) {
        free(record->fields[i]);
    }
    free(record->fields);
    free(record);
}

int main(int argc, char *argv[]) {
    FILE *fp;
    CSVRecord *record;

    if (argc!= 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    record = read_csv_file(fp);
    if (record == NULL) {
        printf("Error: could not read CSV data from file '%s'\n", argv[1]);
        return 1;
    }

    print_csv_record(record);

    free_csv_record(record);
    fclose(fp);

    return 0;
}