//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 100

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

typedef struct {
    CSVRow **rows;
    int num_rows;
} CSVTable;

CSVTable* read_csv(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        exit(1);
    }
    CSVTable* table = (CSVTable*) malloc(sizeof(CSVTable));
    table->rows = (CSVRow**) malloc(sizeof(CSVRow*));
    table->num_rows = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        int num_fields = 1;
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == ',') {
                num_fields++;
            }
        }
        CSVRow* row = (CSVRow*) malloc(sizeof(CSVRow));
        row->fields = (char**) malloc(num_fields * sizeof(char*));
        row->num_fields = num_fields;
        char* field = strtok(line, ",\n");
        int i = 0;
        while (field != NULL) {
            row->fields[i] = (char*) malloc(MAX_FIELD_LENGTH * sizeof(char));
            strncpy(row->fields[i], field, MAX_FIELD_LENGTH);
            i++;
            field = strtok(NULL, ",\n");
        }
        table->rows = (CSVRow**) realloc(table->rows, (table->num_rows + 1) * sizeof(CSVRow*));
        table->rows[table->num_rows++] = row;
    }
    fclose(fp);
    return table;
}

void free_csv(CSVTable* table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->rows[i]->num_fields; j++) {
            free(table->rows[i]->fields[j]);
        }
        free(table->rows[i]->fields);
        free(table->rows[i]);
    }
    free(table->rows);
    free(table);
}

int main() {
    CSVTable* table = read_csv("example.csv");
    printf("Number of rows: %d\n", table->num_rows);
    for (int i = 0; i < table->num_rows; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < table->rows[i]->num_fields; j++) {
            printf("%s", table->rows[i]->fields[j]);
            if (j != table->rows[i]->num_fields - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
    free_csv(table);
    return 0;
}