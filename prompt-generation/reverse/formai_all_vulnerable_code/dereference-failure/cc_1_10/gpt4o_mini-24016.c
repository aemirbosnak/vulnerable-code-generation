//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVReader;

// Function prototypes
CSVReader* create_csv_reader(const char *filename);
void free_csv_reader(CSVReader *reader);
void print_csv(const CSVReader *reader);
void parse_csv_line(char *line, CSVReader *reader, int row);
char** allocate_memory_for_data(int rows, int columns);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVReader *reader = create_csv_reader(argv[1]);
    if (!reader) {
        fprintf(stderr, "Error reading CSV file.\n");
        return EXIT_FAILURE;
    }

    print_csv(reader);
    free_csv_reader(reader);
    return EXIT_SUCCESS;
}

// Function to create a CSV reader and read the file
CSVReader* create_csv_reader(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    if (!reader) {
        perror("Memory allocation error");
        fclose(file);
        return NULL;
    }

    reader->data = NULL;
    reader->num_rows = 0;
    reader->num_columns = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (reader->num_rows == 0) {
            // First line might contain header; count columns
            char *token = strtok(line, ",");
            while (token) {
                reader->num_columns++;
                token = strtok(NULL, ",");
            }
            // Allocate memory for data
            reader->data = allocate_memory_for_data(100, reader->num_columns); // Initial allocation
        }

        parse_csv_line(line, reader, reader->num_rows);
        reader->num_rows++;
    }

    fclose(file);
    return reader;
}

// Function to print the CSV data
void print_csv(const CSVReader *reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        for (int j = 0; j < reader->num_columns; j++) {
            if (j > 0) {
                printf(",");
            }
            printf("%s", reader->data[i][j]);
        }
        printf("\n");
    }
}

// Function to parse a single line and store data in the reader
void parse_csv_line(char *line, CSVReader *reader, int row) {
    char *token = strtok(line, ",");
    for (int j = 0; j < reader->num_columns; j++) {
        if (token) {
            reader->data[row][j] = strdup(token); // Allocate memory for each value
            token = strtok(NULL, ",");
        }
    }
}

// Function to allocate memory for CSV data
char** allocate_memory_for_data(int rows, int columns) {
    char **data = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        data[i] = (char **)malloc(columns * sizeof(char *));
        for (int j = 0; j < columns; j++) {
            data[i][j] = NULL;
        }
    }
    return data;
}

// Function to free the allocated memory for the CSV reader
void free_csv_reader(CSVReader *reader) {
    if (reader) {
        for (int i = 0; i < reader->num_rows; i++) {
            for (int j = 0; j < reader->num_columns; j++) {
                free(reader->data[i][j]);
            }
            free(reader->data[i]);
        }
        free(reader->data);
        free(reader);
    }
}