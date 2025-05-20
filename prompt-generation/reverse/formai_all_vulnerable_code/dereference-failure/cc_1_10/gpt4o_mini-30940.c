//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CsvRow;

typedef struct {
    CsvRow *rows;
    int num_rows;
} CsvData;

CsvData read_csv(const char *filename) {
    // Open the CSV file
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    CsvData data;
    data.rows = NULL;
    data.num_rows = 0;

    while (fgets(line, sizeof(line), file)) {
        data.rows = realloc(data.rows, sizeof(CsvRow) * (data.num_rows + 1));
        CsvRow *current_row = &data.rows[data.num_rows];

        current_row->fields = malloc(sizeof(char*) * MAX_FIELDS);
        current_row->num_fields = 0;

        char *token = strtok(line, ",\n");
        while (token != NULL && current_row->num_fields < MAX_FIELDS) {
            current_row->fields[current_row->num_fields] = malloc(MAX_FIELD_LENGTH);
            strncpy(current_row->fields[current_row->num_fields], token, MAX_FIELD_LENGTH);
            current_row->num_fields++;
            token = strtok(NULL, ",\n");
        }
        data.num_rows++;
    }

    fclose(file);
    return data;
}

void free_csv_data(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->rows[i].num_fields; j++) {
            free(data->rows[i].fields[j]);
        }
        free(data->rows[i].fields);
    }
    free(data->rows);
}

void print_csv_data(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->rows[i].num_fields; j++) {
            printf("%s", data->rows[i].fields[j]);
            if (j < data->rows[i].num_fields - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CsvData csv_data = read_csv(argv[1]);
    print_csv_data(&csv_data);
    free_csv_data(&csv_data);

    return EXIT_SUCCESS;
}