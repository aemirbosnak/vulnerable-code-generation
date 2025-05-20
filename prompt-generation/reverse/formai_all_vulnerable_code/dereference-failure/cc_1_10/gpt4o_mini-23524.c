//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 64

typedef struct {
    char **fields;
    int field_count;
} CsvRow;

typedef struct {
    CsvRow *rows;
    int row_count;
} CsvFile;

void free_csv(CsvFile *csv) {
    for (int i = 0; i < csv->row_count; i++) {
        free(csv->rows[i].fields);
    }
    free(csv->rows);
}

CsvFile read_csv(const char *filename) {
    CsvFile csv;
    csv.row_count = 0;
    csv.rows = NULL;

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        csv.rows = realloc(csv.rows, sizeof(CsvRow) * (csv.row_count + 1));
        CsvRow *current_row = &csv.rows[csv.row_count];
        current_row->fields = malloc(sizeof(char *) * MAX_FIELDS);
        current_row->field_count = 0;

        char *token = strtok(line, ",");
        while (token != NULL) {
            current_row->fields[current_row->field_count] = strdup(token);
            current_row->field_count++;
            token = strtok(NULL, ",");
        }
        csv.row_count++;
    }

    fclose(file);
    return csv;
}

void print_csv(const CsvFile *csv) {
    for (int i = 0; i < csv->row_count; i++) {
        CsvRow *row = &csv->rows[i];
        for (int j = 0; j < row->field_count; j++) {
            printf("%s", row->fields[j]);
            if (j < row->field_count - 1) {
                printf(" | ");
            }
        }
        printf("\n");
    }
}

void write_csv(const char *filename, const CsvFile *csv) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error writing file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < csv->row_count; i++) {
        CsvRow *row = (CsvRow *)&csv->rows[i];
        for (int j = 0; j < row->field_count; j++) {
            fprintf(file, "%s", row->fields[j]);
            if (j < row->field_count - 1) {
                fprintf(file, ",");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    CsvFile csv = read_csv(filename);
    
    printf("Read CSV file: %s\n", filename);
    print_csv(&csv);
    
    const char *output_filename = "output.csv";
    write_csv(output_filename, &csv);
    printf("Output written to: %s\n", output_filename);
    
    free_csv(&csv);
    return EXIT_SUCCESS;
}