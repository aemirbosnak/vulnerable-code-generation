//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DELIMITER ","
#define INITIAL_ROWS 10
#define INITIAL_COLUMNS 10

typedef struct {
    char ***data;
    int rows;
    int columns;
} CSVData;

CSVData* create_csv_data() {
    CSVData *csvData = (CSVData *)malloc(sizeof(CSVData));
    csvData->rows = 0;
    csvData->columns = 0;
    csvData->data = (char ***)malloc(INITIAL_ROWS * sizeof(char **));
    for (int i = 0; i < INITIAL_ROWS; i++) {
        csvData->data[i] = (char **)malloc(INITIAL_COLUMNS * sizeof(char *));
        for (int j = 0; j < INITIAL_COLUMNS; j++) {
            csvData->data[i][j] = NULL;
        }
    }
    return csvData;
}

void free_csv_data(CSVData *csvData) {
    for (int i = 0; i < csvData->rows; i++) {
        for (int j = 0; j < csvData->columns; j++) {
            if (csvData->data[i][j] != NULL) {
                free(csvData->data[i][j]);
            }
        }
        free(csvData->data[i]);
    }
    free(csvData->data);
    free(csvData);
}

void resize_csv_data(CSVData *csvData, int new_rows, int new_columns) {
    csvData->data = realloc(csvData->data, new_rows * sizeof(char **));
    for (int i = 0; i < new_rows; i++) {
        if (i >= csvData->rows) {
            csvData->data[i] = (char **)malloc(new_columns * sizeof(char *));
            for (int j = 0; j < new_columns; j++) {
                csvData->data[i][j] = NULL;
            }
        } else {
            csvData->data[i] = realloc(csvData->data[i], new_columns * sizeof(char *));
            for (int j = csvData->columns; j < new_columns; j++) {
                csvData->data[i][j] = NULL;
            }
        }
    }
    csvData->rows = new_rows;
    csvData->columns = new_columns;
}

void read_csv(const char *filename, CSVData *csvData) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char *token;
        int column_index = 0;

        // Reallocate for incoming data
        if (csvData->rows >= INITIAL_ROWS) {
            resize_csv_data(csvData, csvData->rows + 1, csvData->columns < INITIAL_COLUMNS ? INITIAL_COLUMNS : csvData->columns);
        }

        // Prepare new row
        csvData->data[csvData->rows] = (char **)malloc(INITIAL_COLUMNS * sizeof(char *));
        for (int j = 0; j < INITIAL_COLUMNS; j++) {
            csvData->data[csvData->rows][j] = NULL;
        }

        token = strtok(buffer, DELIMITER);
        while (token) {
            if (column_index >= csvData->columns) {
                // Resize for more columns
                resize_csv_data(csvData, csvData->rows + 1, column_index + 1);
            }
            csvData->data[csvData->rows][column_index] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(csvData->data[csvData->rows][column_index], token);
            token = strtok(NULL, DELIMITER);
            column_index++;
        }
        csvData->rows++;
    }

    fclose(file);
}

void print_csv_data(CSVData *csvData) {
    for (int i = 0; i < csvData->rows; i++) {
        for (int j = 0; j < csvData->columns; j++) {
            if (csvData->data[i][j] != NULL) {
                printf("%s", csvData->data[i][j]);
            }
            if (j < csvData->columns - 1) {
                printf("%s", DELIMITER);
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVData *csvData = create_csv_data();
    read_csv(argv[1], csvData);
    print_csv_data(csvData);
    free_csv_data(csvData);

    return EXIT_SUCCESS;
}