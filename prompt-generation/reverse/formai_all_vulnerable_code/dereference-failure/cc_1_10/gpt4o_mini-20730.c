//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
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

void free_csv_data(CSVData *csv_data) {
    for (int i = 0; i < csv_data->row_count; i++) {
        for (int j = 0; j < csv_data->rows[i].field_count; j++) {
            free(csv_data->rows[i].fields[j]);
        }
        free(csv_data->rows[i].fields);
    }
    free(csv_data->rows);
}

CSVData read_csv(const char *filename) {
    CSVData csv_data;
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    csv_data.rows = NULL;
    csv_data.row_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        csv_data.rows = realloc(csv_data.rows, sizeof(CSVRow) * (csv_data.row_count + 1));
        CSVRow *current_row = &csv_data.rows[csv_data.row_count];
        
        current_row->fields = malloc(sizeof(char *) * MAX_FIELDS);
        current_row->field_count = 0;

        char *token = strtok(line, ",\n");
        while (token != NULL) {
            current_row->fields[current_row->field_count] = malloc(strlen(token) + 1);
            strcpy(current_row->fields[current_row->field_count], token);
            current_row->field_count++;
            token = strtok(NULL, ",\n");
        }

        csv_data.row_count++;
    }
    fclose(file);
    return csv_data;
}

void print_csv_data(const CSVData *csv_data) {
    for (int i = 0; i < csv_data->row_count; i++) {
        for (int j = 0; j < csv_data->rows[i].field_count; j++) {
            printf("%s", csv_data->rows[i].fields[j]);
            if (j < csv_data->rows[i].field_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVData csv_data = read_csv(argv[1]);
    print_csv_data(&csv_data);
    free_csv_data(&csv_data);

    return EXIT_SUCCESS;
}