//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128

typedef struct {
    char** headers;
    int num_fields;
} CsvHeader;

typedef struct {
    char** fields;
    int num_fields;
} CsvRow;

typedef struct {
    CsvHeader header;
    CsvRow* rows;
    int num_rows;
} CsvData;

CsvHeader* csv_parse_header(char* line) {
    CsvHeader* header = (CsvHeader*) malloc(sizeof(CsvHeader));
    header->headers = NULL;
    header->num_fields = 0;
    char* token = strtok(line, ",");
    while (token != NULL) {
        header->headers = (char**) realloc(header->headers, sizeof(char*) * (header->num_fields + 1));
        header->headers[header->num_fields] = (char*) malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(header->headers[header->num_fields], token);
        header->num_fields++;
        token = strtok(NULL, ",");
    }
    return header;
}

CsvRow* csv_parse_row(char* line) {
    CsvRow* row = (CsvRow*) malloc(sizeof(CsvRow));
    row->fields = NULL;
    row->num_fields = 0;
    char* token = strtok(line, ",");
    while (token != NULL) {
        row->fields = (char**) realloc(row->fields, sizeof(char*) * (row->num_fields + 1));
        row->fields[row->num_fields] = (char*) malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(row->fields[row->num_fields], token);
        row->num_fields++;
        token = strtok(NULL, ",");
    }
    return row;
}

CsvData* csv_read_file(char* filename) {
    CsvData* data = (CsvData*) malloc(sizeof(CsvData));
    data->header.headers = NULL;
    data->header.num_fields = 0;
    data->rows = NULL;
    data->num_rows = 0;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return data;
    }
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, fp);
    data->header = *csv_parse_header(line);
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        CsvRow* row = csv_parse_row(line);
        data->rows = (CsvRow*) realloc(data->rows, sizeof(CsvRow) * (data->num_rows + 1));
        data->rows[data->num_rows] = *row;
        data->num_rows++;
        free(row);
    }
    fclose(fp);
    return data;
}

void csv_free_data(CsvData* data) {
    for (int i = 0; i < data->header.num_fields; i++) {
        free(data->header.headers[i]);
    }
    free(data->header.headers);
    for (int i = 0; i < data->num_rows; i++) {
        CsvRow row = data->rows[i];
        for (int j = 0; j < row.num_fields; j++) {
            free(row.fields[j]);
        }
        free(row.fields);
    }
    free(data->rows);
    free(data);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Error: must provide filename as argument\n");
        return 1;
    }
    CsvData* data = csv_read_file(argv[1]);
    printf("CSV file has %d rows and %d columns\n", data->num_rows, data->header.num_fields);
    printf("Column headers:\n");
    for (int i = 0; i < data->header.num_fields; i++) {
        printf("%s ", data->header.headers[i]);
    }
    printf("\n");
    printf("Data:\n");
    for (int i = 0; i < data->num_rows; i++) {
        CsvRow row = data->rows[i];
        for (int j = 0; j < row.num_fields; j++) {
            printf("%s ", row.fields[j]);
        }
        printf("\n");
    }
    csv_free_data(data);
    return 0;
}