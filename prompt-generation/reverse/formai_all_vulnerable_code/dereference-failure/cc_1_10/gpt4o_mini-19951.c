//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int field_count;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int row_count;
} CSVData;

CSVData* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    CSVData *data = malloc(sizeof(CSVData));
    data->rows = NULL;
    data->row_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character at the end
        line[strcspn(line, "\n")] = 0;

        // Allocate new row
        data->rows = realloc(data->rows, sizeof(CSVRow) * (data->row_count + 1));
        CSVRow *current_row = &data->rows[data->row_count];
        current_row->fields = malloc(sizeof(char*) * MAX_FIELDS);
        current_row->field_count = 0;

        // Tokenize the line using comma as the delimiter
        char *token = strtok(line, ",");
        while (token) {
            current_row->fields[current_row->field_count] = strdup(token);
            current_row->field_count++;
            token = strtok(NULL, ",");
        }

        data->row_count++;
    }

    fclose(file);
    return data;
}

void print_csv_data(CSVData *data) {
    if (data == NULL) {
        printf("No data to display.\n");
        return;
    }

    for (int i = 0; i < data->row_count; i++) {
        CSVRow *row = &data->rows[i];
        for (int j = 0; j < row->field_count; j++) {
            printf("%s", row->fields[j]);
            if (j < row->field_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

void free_csv_data(CSVData *data) {
    if (data) {
        for (int i = 0; i < data->row_count; i++) {
            CSVRow *row = &data->rows[i];
            for (int j = 0; j < row->field_count; j++) {
                free(row->fields[j]);
            }
            free(row->fields);
        }
        free(data->rows);
        free(data);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    CSVData *csv_data = read_csv(filename);

    print_csv_data(csv_data);
    free_csv_data(csv_data);

    return EXIT_SUCCESS;
}