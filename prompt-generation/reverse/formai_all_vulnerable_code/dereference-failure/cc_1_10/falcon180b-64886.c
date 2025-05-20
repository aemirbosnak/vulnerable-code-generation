//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_FIELDS 100
#define DELIM ","

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *create_csv_row() {
    CSVRow *row = (CSVRow *)malloc(sizeof(CSVRow));
    row->fields = (char **)malloc(MAX_NUM_FIELDS * sizeof(char *));
    row->num_fields = 0;
    for (int i = 0; i < MAX_NUM_FIELDS; i++) {
        row->fields[i] = NULL;
    }
    return row;
}

void destroy_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

CSVRow *read_csv_file(FILE *file) {
    CSVRow *row = create_csv_row();
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, DELIM);
        while (token!= NULL) {
            if (row->num_fields >= MAX_NUM_FIELDS) {
                printf("Error: Maximum number of fields exceeded.\n");
                destroy_csv_row(row);
                return NULL;
            }
            row->fields[row->num_fields] = strdup(token);
            row->num_fields++;
            token = strtok(NULL, DELIM);
        }
    }
    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s%c", row->fields[i], i < row->num_fields - 1? DELIM : '\n');
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }
    CSVRow *row = read_csv_file(file);
    if (row!= NULL) {
        print_csv_row(row);
        destroy_csv_row(row);
    }
    fclose(file);
    return 0;
}