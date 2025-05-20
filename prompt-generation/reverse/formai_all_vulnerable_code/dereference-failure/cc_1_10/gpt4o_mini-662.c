//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
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

// Function prototypes
CSVData* read_csv(const char *filename);
void free_csv_data(CSVData *data);
void print_csv_data(CSVData *data);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVData *csv_data = read_csv(argv[1]);
    if (!csv_data) {
        fprintf(stderr, "Error reading CSV file.\n");
        return EXIT_FAILURE;
    }

    print_csv_data(csv_data);
    free_csv_data(csv_data);

    return EXIT_SUCCESS;
}

// Read CSV file and return a CSVData structure
CSVData* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    CSVData *data = malloc(sizeof(CSVData));
    if (!data) {
        fclose(file);
        perror("Memory allocation error");
        return NULL;
    }

    data->rows = NULL;
    data->row_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *line_copy = strdup(line);
        if (!line_copy) {
            free_csv_data(data);
            fclose(file);
            perror("Memory allocation error");
            return NULL;
        }

        // Split the line into fields
        char *field = strtok(line_copy, ",");
        int field_count = 0;
        char **fields = malloc(MAX_FIELDS * sizeof(char*));
        if (!fields) {
            free(line_copy);
            free_csv_data(data);
            fclose(file);
            perror("Memory allocation error");
            return NULL;
        }

        while (field != NULL && field_count < MAX_FIELDS) {
            fields[field_count] = strdup(field);
            if (!fields[field_count]) {
                for (int i = 0; i < field_count; i++) {
                    free(fields[i]);
                }
                free(fields);
                free(line_copy);
                free_csv_data(data);
                fclose(file);
                perror("Memory allocation error");
                return NULL;
            }
            field = strtok(NULL, ",");
            field_count++;
        }

        // Resize data array
        data->rows = realloc(data->rows, (data->row_count + 1) * sizeof(CSVRow));
        if (!data->rows) {
            for (int i = 0; i < field_count; i++) {
                free(fields[i]);
            }
            free(fields);
            free(line_copy);
            free_csv_data(data);
            fclose(file);
            perror("Memory allocation error");
            return NULL;
        }

        data->rows[data->row_count].fields = fields;
        data->rows[data->row_count].field_count = field_count;
        data->row_count++;

        free(line_copy);
    }

    fclose(file);
    return data;
}

// Free allocated CSVData structure
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

// Print the CSV data
void print_csv_data(CSVData *data) {
    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->rows[i].field_count; j++) {
            printf("%s", data->rows[i].fields[j]);
            if (j < data->rows[i].field_count - 1) { // Avoid trailing comma
                printf(", ");
            }
        }
        printf("\n");
    }
}