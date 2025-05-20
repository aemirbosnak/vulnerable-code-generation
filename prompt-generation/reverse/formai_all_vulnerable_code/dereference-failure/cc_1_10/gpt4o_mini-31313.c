//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int field_count;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int row_count;
} CSVData;

CSVData *create_csv_data(int max_rows) {
    CSVData *data = malloc(sizeof(CSVData));
    data->row_count = 0;
    data->rows = malloc(max_rows * sizeof(CSVRow));
    for (int i = 0; i < max_rows; i++) {
        data->rows[i].fields = malloc(MAX_FIELDS * sizeof(char *));
        for (int j = 0; j < MAX_FIELDS; j++) {
            data->rows[i].fields[j] = malloc(MAX_FIELD_LENGTH * sizeof(char));
        }
        data->rows[i].field_count = 0;
    }
    return data;
}

void free_csv_data(CSVData *data) {
    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->rows[i].field_count; j++) {
            free(data->rows[i].fields[j]);
        }
        free(data->rows[i].fields);
    }
    free(data->rows);
    free(data);
}

CSVRow parse_csv_row(char *line) {
    CSVRow row;
    row.field_count = 0;

    char *token = strtok(line, ",");
    while (token != NULL && row.field_count < MAX_FIELDS) {
        strcpy(row.fields[row.field_count], token);
        row.field_count++;
        token = strtok(NULL, ",");
    }

    return row;
}

CSVData *read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return NULL;
    }

    CSVData *data = create_csv_data(100);
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        CSVRow row = parse_csv_row(line);
        data->rows[data->row_count] = row;
        data->row_count++;
    }

    fclose(file);
    return data;
}

void print_csv_data(CSVData *data) {
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
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    CSVData *data = read_csv(filename);
    if (!data) {
        return EXIT_FAILURE;
    }

    printf("Contents of %s:\n", filename);
    print_csv_data(data);
    free_csv_data(data);

    return EXIT_SUCCESS;
}