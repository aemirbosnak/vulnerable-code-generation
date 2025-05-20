//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    size_t capacity;
    size_t size;
    char** data;
} CsvTable;

CsvTable* csv_table_new(size_t row_capacity, size_t col_capacity) {
    CsvTable* table = calloc(1, sizeof(CsvTable));
    table->capacity = row_capacity;
    table->size = 0;
    table->data = calloc(row_capacity, sizeof(char*));
    for (size_t i = 0; i < row_capacity; i++) {
        table->data[i] = calloc(col_capacity, sizeof(char));
    }
    return table;
}

void csv_table_destroy(CsvTable* table) {
    for (size_t i = 0; i < table->size; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void csv_parse_line(char* line, size_t* cols, size_t col_capacity) {
    size_t num_cols = 0;
    char** cols_ptr = cols;
    char* token = strtok(line, ",");
    while (token != NULL) {
        if (num_cols >= col_capacity) {
            col_capacity *= 2;
            *cols_ptr = realloc(*cols_ptr, col_capacity * sizeof(char*));
        }
        (*cols_ptr) = token;
        cols_ptr++;
        num_cols++;
        token = strtok(NULL, ",");
    }
    *cols_ptr = NULL;
}

int main(void) {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    CsvTable* table = csv_table_new(10, 5);
    size_t cols[10];
    while (getline(&table->data[table->size], table->capacity * sizeof(char*), file) > 0) {
        size_t num_cols;
        csv_parse_line(table->data[table->size], cols, 5);
        table->size++;
        if (table->size >= table->capacity) {
            table->capacity *= 2;
            table->data = realloc(table->data, table->capacity * sizeof(char*));
        }
    }
    fclose(file);

    for (size_t i = 0; i < table->size; i++) {
        for (size_t j = 0; j < table->data[i][0] - 1; j++) {
            putchar(toupper(table->data[i][j]) == table->data[i][j + 1] ? '\t' : ' ');
            putchar(table->data[i][j]);
        }
        putchar('\n');
    }

    csv_table_destroy(table);

    return EXIT_SUCCESS;
}