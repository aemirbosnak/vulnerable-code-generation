//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 128

typedef struct {
    char **data;
    int num_fields;
} CsvRecord;

typedef struct {
    CsvRecord **record_data;
    int num_records;
    int num_fields;
} CsvFile;

CsvRecord* parse_csv_record(char *line) {
    CsvRecord *record = (CsvRecord*)malloc(sizeof(CsvRecord));
    record->data = (char**)malloc(sizeof(char*)*MAX_LINE_SIZE);
    int field_index = 0;
    char *field = strtok(line, ",");
    while (field != NULL) {
        record->data[field_index] = (char*)malloc(sizeof(char)*MAX_FIELD_SIZE);
        strcpy(record->data[field_index], field);
        field_index++;
        field = strtok(NULL, ",");
    }
    record->num_fields = field_index;
    return record;
}

CsvFile* open_csv_file(char *filename) {
    CsvFile *csv_file = (CsvFile*)malloc(sizeof(CsvFile));
    char line[MAX_LINE_SIZE];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", filename);
        exit(1);
    }
    fgets(line, MAX_LINE_SIZE, fp);
    csv_file->num_fields = 0;
    char *field = strtok(line, ",");
    while (field != NULL) {
        csv_file->num_fields++;
        field = strtok(NULL, ",");
    }
    csv_file->record_data = (CsvRecord**)malloc(sizeof(CsvRecord*)*MAX_LINE_SIZE);
    int record_index = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        CsvRecord *record = parse_csv_record(line);
        csv_file->record_data[record_index] = record;
        record_index++;
    }
    csv_file->num_records = record_index;
    fclose(fp);
    return csv_file;
}

void close_csv_file(CsvFile* csv_file) {
    int i, j;
    for (i = 0; i < csv_file->num_records; i++) {
        for (j = 0; j < csv_file->num_fields; j++) {
            free(csv_file->record_data[i]->data[j]);
        }
        free(csv_file->record_data[i]->data);
        free(csv_file->record_data[i]);
    }
    free(csv_file->record_data);
    free(csv_file);
}

int main() {
    CsvFile *csv_file = open_csv_file("example.csv");
    int i, j;
    for (i = 0; i < csv_file->num_records; i++) {
        for (j = 0; j < csv_file->num_fields; j++) {
            printf("%s ", csv_file->record_data[i]->data[j]);
        }
        printf("\n");
    }
    close_csv_file(csv_file);
    return 0;
}