//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 20
#define MAX_LENGTH 100

typedef struct {
    char field[MAX_LENGTH];
} Field;

typedef struct {
    Field fields[MAX_COLUMNS];
    int num_fields;
} CsvRow;

typedef struct {
    CsvRow* data;
    int length;
} CsvFile;

CsvRow* read_csv_row(char* row_string) {
    CsvRow* row = (CsvRow*)malloc(sizeof(CsvRow));
    row->num_fields = 0;
    char* token = strtok(row_string, ",");
    while(token != NULL) {
        strcpy(row->fields[row->num_fields].field, token);
        row->num_fields++;
        token = strtok(NULL, ",");
    }
    return row;
}

CsvFile* read_csv_file(char* filename) {
    CsvFile* file = (CsvFile*)malloc(sizeof(CsvFile));
    file->length = 0;

    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: unable to open file\n");
        return file;
    }

    char line[MAX_COLUMNS * MAX_LENGTH];
    while(fgets(line, sizeof(line), fp)) {
        CsvRow* row = read_csv_row(line);
        file->data = (CsvRow*)realloc(file->data, sizeof(CsvRow) * (file->length + 1));
        file->data[file->length] = *row;
        file->length++;
        free(row);
    }

    fclose(fp);
    return file;
}

void print_csv_file(CsvFile* file) {
    for(int i = 0; i < file->length; i++) {
        for(int j = 0; j < file->data[i].num_fields; j++) {
            printf("%s ", file->data[i].fields[j].field);
        }
        printf("\n");
    }
}

int main() {
    CsvFile* file = read_csv_file("example.csv");
    print_csv_file(file);
    free(file->data);
    free(file);
    return 0;
}