//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int field_count;
} CsvRow;

typedef struct {
    CsvRow *rows;
    int row_count;
    int row_capacity;
} CsvData;

void initialize_csv_data(CsvData *data) {
    data->row_count = 0;
    data->row_capacity = 10;
    data->rows = malloc(data->row_capacity * sizeof(CsvRow));
    for (int i = 0; i < data->row_capacity; i++) {
        data->rows[i].fields = malloc(MAX_FIELDS * sizeof(char *));
        data->rows[i].field_count = 0;
    }
}

void free_csv_data(CsvData *data) {
    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->rows[i].field_count; j++) {
            free(data->rows[i].fields[j]);
        }
        free(data->rows[i].fields);
    }
    free(data->rows);
}

void add_row(CsvData *data, CsvRow row) {
    if (data->row_count >= data->row_capacity) {
        data->row_capacity *= 2;
        data->rows = realloc(data->rows, data->row_capacity * sizeof(CsvRow));
        for (int i = data->row_count; i < data->row_capacity; i++) {
            data->rows[i].fields = malloc(MAX_FIELDS * sizeof(char *));
            data->rows[i].field_count = 0;
        }
    }
    data->rows[data->row_count++] = row;
}

void parse_csv_line(const char *line, CsvRow *row) {
    char *line_copy = strdup(line);
    char *token = strtok(line_copy, ",");
    row->field_count = 0;

    while (token != NULL && row->field_count < MAX_FIELDS) {
        row->fields[row->field_count] = strdup(token);
        row->field_count++;
        token = strtok(NULL, ",");
    }
    free(line_copy);
}

void read_csv_file(const char *filename, CsvData *data) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        CsvRow row;
        parse_csv_line(line, &row);
        add_row(data, row);
    }
    fclose(file);
}

void print_csv_data(const CsvData *data) {
    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->rows[i].field_count; j++) {
            printf("%s", data->rows[i].fields[j]);
            if (j < data->rows[i].field_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CsvData csv_data;
    initialize_csv_data(&csv_data);
    read_csv_file(argv[1], &csv_data);
    print_csv_data(&csv_data);
    free_csv_data(&csv_data);

    return EXIT_SUCCESS;
}