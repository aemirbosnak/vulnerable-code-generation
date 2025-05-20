//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
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

// Function Prototypes
CSVData* read_csv(const char *filename);
void free_csv_data(CSVData *data);
void print_csv_data(const CSVData *data);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVData *csv_data = read_csv(argv[1]);
    if (!csv_data) {
        fprintf(stderr, "Failed to read CSV data.\n");
        return EXIT_FAILURE;
    }

    print_csv_data(csv_data);
    free_csv_data(csv_data);
    return EXIT_SUCCESS;
}

CSVData* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    CSVData *data = (CSVData *)malloc(sizeof(CSVData));
    if (!data) {
        perror("Failed to allocate memory for CSVData");
        fclose(file);
        return NULL;
    }

    data->rows = NULL;
    data->row_count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        data->rows = (CSVRow *)realloc(data->rows, sizeof(CSVRow) * (data->row_count + 1));
        if (!data->rows) {
            perror("Failed to reallocate memory for rows");
            free_csv_data(data);
            fclose(file);
            return NULL;
        }

        CSVRow *new_row = &data->rows[data->row_count];
        new_row->fields = NULL;
        new_row->field_count = 0;

        char *token = strtok(line, ",");
        while (token) {
            new_row->fields = (char **)realloc(new_row->fields, sizeof(char *) * (new_row->field_count + 1));
            if (!new_row->fields) {
                perror("Failed to reallocate memory for fields");
                free_csv_data(data);
                fclose(file);
                return NULL;
            }
            new_row->fields[new_row->field_count] = strdup(token);
            new_row->field_count++;
            token = strtok(NULL, ",");
        }

        data->row_count++;
    }

    fclose(file);
    return data;
}

void free_csv_data(CSVData *data) {
    if (data) {
        for (int i = 0; i < data->row_count; i++) {
            for (int j = 0; j < data->rows[i].field_count; j++) {
                free(data->rows[i].fields[j]);
            }
            free(data->rows[i].fields);
        }
        free(data->rows);
        free(data);
    }
}

void print_csv_data(const CSVData *data) {
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