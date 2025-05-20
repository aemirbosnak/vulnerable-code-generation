//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char **data;
    int size;
} CSV_Row;

typedef struct {
    CSV_Row **rows;
    int size;
} CSV_Table;

// Function to split a string by a delimiter
char** split_string(char *str, char delimiter, int *size) {
    char **tokens = NULL;
    char *token = strtok(str, &delimiter);
    int i = 0;
    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char*) * (i+1));
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, &delimiter);
    }
    *size = i;
    return tokens;
}

// Function to read a CSV file and return a CSV table
CSV_Table* read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }
    char line[MAX_LINE_SIZE];
    int first_row = 1;
    CSV_Table *table = malloc(sizeof(CSV_Table));
    table->rows = NULL;
    table->size = 0;
    while (fgets(line, MAX_LINE_SIZE, file)) {
        CSV_Row *row = malloc(sizeof(CSV_Row));
        row->data = split_string(line, ',', &row->size);
        if (first_row) {
            first_row = 0;
        } else {
            table->rows = realloc(table->rows, sizeof(CSV_Row*) * (table->size+1));
            table->rows[table->size] = row;
            table->size++;
        }
    }
    fclose(file);
    return table;
}

// Function to print a CSV table to the console
void print_csv_table(CSV_Table *table) {
    for (int i = 0; i < table->size; i++) {
        printf("Row %d:\n", i+1);
        for (int j = 0; j < table->rows[i]->size; j++) {
            printf("%s, ", table->rows[i]->data[j]);
        }
        printf("\n");
    }
}

int main() {
    CSV_Table *table = read_csv_file("example.csv");
    if (table == NULL) {
        return 1;
    }
    printf("Read CSV Table:\n");
    print_csv_table(table);

    // Clean up memory
    for (int i = 0; i < table->size; i++) {
        for (int j = 0; j < table->rows[i]->size; j++) {
            free(table->rows[i]->data[j]);
        }
        free(table->rows[i]->data);
        free(table->rows[i]);
    }
    free(table->rows);
    free(table);
    return 0;
}