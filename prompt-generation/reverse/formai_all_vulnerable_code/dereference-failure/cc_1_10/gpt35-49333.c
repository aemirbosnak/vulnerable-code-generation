//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char** fields;
    int num_fields;
} CSVRow;

typedef struct {
    CSVRow* rows;
    int num_rows;
} CSVTable;

CSVRow* parse_csv_row(char* line, const char* delim) {
    CSVRow* row = (CSVRow*) malloc(sizeof(CSVRow));
    row->fields = (char**) malloc(100 * sizeof(char*));
    row->num_fields = 0;

    char* ptr = strtok(line, delim);
    while(ptr != NULL) {
        row->fields[row->num_fields++] = ptr;
        ptr = strtok(NULL, delim);
    }

    return row;
}

CSVTable* parse_csv_file(const char* filename, const char* delim) {
    FILE* fp;
    char line[MAX_LINE_SIZE];

    fp = fopen(filename, "r");
    if(fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    CSVTable* table = (CSVTable*) malloc(sizeof(CSVTable));
    table->rows = (CSVRow*) malloc(10000 * sizeof(CSVRow));
    table->num_rows = 0;

    while(fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        CSVRow* row = parse_csv_row(line, delim);
        table->rows[table->num_rows++] = *row;
    }

    fclose(fp);

    return table;
}

void print_csv_table(CSVTable* table) {
    for(int i=0; i<table->num_rows; i++) {
        for(int j=0; j<table->rows[i].num_fields; j++) {
            printf("%s", table->rows[i].fields[j]);
            if(j < table->rows[i].num_fields - 1) {
                printf(",");
            } else {
                printf("\n");
            }
        }
    }
}

int main() {
    CSVTable* table = parse_csv_file("example.csv", ",");
    print_csv_table(table);
    free(table);
    return 0;
}