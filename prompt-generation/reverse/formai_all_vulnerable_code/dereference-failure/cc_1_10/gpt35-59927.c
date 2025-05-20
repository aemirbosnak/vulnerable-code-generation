//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 100

typedef struct row {
    char** fields;
    int num_fields;
} Row;

typedef struct csv_data {
    Row* rows;
    int num_rows;
    int num_fields_per_row;
} CSVData;

int get_num_fields(char* line) {
    int num_fields = 0;
    char* field = strtok(line, ",");
    while (field != NULL) {
        num_fields++;
        field = strtok(NULL, ",");
    }
    return num_fields;
}

Row* create_row(char* line, int num_fields) {
    Row* row = (Row*) malloc(sizeof(Row));
    row->fields = (char**) malloc(num_fields * sizeof(char*));
    row->num_fields = num_fields;
    char* token = strtok(line, ",");
    int i = 0;
    while (token != NULL) {
        row->fields[i] = (char*) malloc(MAX_FIELD_LENGTH * sizeof(char));
        strcpy(row->fields[i], token);
        token = strtok(NULL, ",");
        i++;
    }
    return row;
}

CSVData* read_csv(char* filename) {
    char line[MAX_LINE_LENGTH];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    fgets(line, MAX_LINE_LENGTH, fp); // Read header line and ignore
    int num_fields = get_num_fields(line);
    CSVData* csv_data = (CSVData*) malloc(sizeof(CSVData));
    csv_data->rows = (Row*) malloc(MAX_LINE_LENGTH * sizeof(Row));
    csv_data->num_rows = 0;
    csv_data->num_fields_per_row = num_fields;
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        Row* row = create_row(line, num_fields);
        csv_data->rows[csv_data->num_rows] = *row;
        csv_data->num_rows++;
    }
    fclose(fp);
    return csv_data;
}

void print_csv(CSVData* csv_data) {
    for (int i = 0; i < csv_data->num_rows; i++) {
        Row row = csv_data->rows[i];
        for (int j = 0; j < row.num_fields; j++) {
            printf("%s, ", row.fields[j]);
        }
        printf("\n");
    }
}

int main() {
    char* filename = "example.csv";
    CSVData* csv_data = read_csv(filename);
    print_csv(csv_data);
    return 0;
}