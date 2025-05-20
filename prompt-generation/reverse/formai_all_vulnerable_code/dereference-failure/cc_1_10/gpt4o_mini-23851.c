//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int field_count;
} DataRow;

typedef struct {
    DataRow *rows;
    int row_count;
} DataSet;

DataSet* create_data_set(int initial_size) {
    DataSet *dataset = malloc(sizeof(DataSet));
    dataset->rows = malloc(sizeof(DataRow) * initial_size);
    dataset->row_count = 0;
    return dataset;
}

void free_data_set(DataSet *dataset) {
    for (int i = 0; i < dataset->row_count; i++) {
        for (int j = 0; j < dataset->rows[i].field_count; j++) {
            free(dataset->rows[i].fields[j]);
        }
        free(dataset->rows[i].fields);
    }
    free(dataset->rows);
    free(dataset);
}

void add_row_to_dataset(DataSet *dataset, char *line) {
    DataRow row;
    row.field_count = 0;
    row.fields = malloc(sizeof(char*) * MAX_FIELDS);
    
    char *token = strtok(line, ",");
    while (token != NULL) {
        row.fields[row.field_count] = malloc(strlen(token) + 1);
        strcpy(row.fields[row.field_count], token);
        row.field_count++;
        token = strtok(NULL, ",");
    }
    
    dataset->rows[dataset->row_count++] = row;
}

void print_statistics(DataSet *dataset) {
    printf("Total Rows: %d\n", dataset->row_count);
    if (dataset->row_count == 0) {
        return;
    }
    // Print number of fields in the first row
    printf("Fields in first row: %d\n", dataset->rows[0].field_count);
}

void read_data_from_csv(DataSet *dataset, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        add_row_to_dataset(dataset, line);
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    DataSet *dataset = create_data_set(100); // Initial size of 100
    read_data_from_csv(dataset, argv[1]);
    print_statistics(dataset);
    
    free_data_set(dataset);
    return EXIT_SUCCESS;
}