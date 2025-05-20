//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int number_of_fields;
} CSVRow;

CSVRow* create_row(int field_count);
void free_row(CSVRow *row);
void print_row(CSVRow *row);
int split_line(const char *line, char delimiter, CSVRow *row);
void read_csv(const char *filename);

int main() {
    const char *filename = "data.csv"; // Replace with your CSV file path
    read_csv(filename);
    return 0;
}

CSVRow* create_row(int field_count) {
    CSVRow *row = (CSVRow *)malloc(sizeof(CSVRow));
    if (!row) {
        perror("Failed to allocate memory for CSVRow");
        exit(EXIT_FAILURE);
    }
    row->fields = (char **)malloc(field_count * sizeof(char *));
    if (!row->fields) {
        free(row);
        perror("Failed to allocate memory for fields");
        exit(EXIT_FAILURE);
    }
    row->number_of_fields = 0;
    return row;
}

void free_row(CSVRow *row) {
    if (row) {
        for (int i = 0; i < row->number_of_fields; i++) {
            free(row->fields[i]);
        }
        free(row->fields);
        free(row);
    }
}

void print_row(CSVRow *row) {
    for (int i = 0; i < row->number_of_fields; i++) {
        printf("%s", row->fields[i]);
        if (i < row->number_of_fields - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int split_line(const char *line, char delimiter, CSVRow *row) {
    char *token;
    char *line_copy = strdup(line);
    if (!line_copy) {
        perror("Failed to copy line");
        exit(EXIT_FAILURE);
    }

    token = strtok(line_copy, &delimiter);
    while (token && row->number_of_fields < MAX_FIELDS) {
        row->fields[row->number_of_fields] = strdup(token);
        if (!row->fields[row->number_of_fields]) {
            free(line_copy);
            perror("Failed to allocate memory for token");
            exit(EXIT_FAILURE);
        }
        row->number_of_fields++;
        token = strtok(NULL, &delimiter);
    }
    free(line_copy);
    return row->number_of_fields; // Return the number of fields obtained
}

void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Cannot open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        CSVRow *row = create_row(MAX_FIELDS);

        if (split_line(line, ',', row) > 0) {
            print_row(row);
        }
        
        free_row(row);
    }

    fclose(file);
}