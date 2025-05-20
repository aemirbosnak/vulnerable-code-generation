//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 100

// Structure to hold a CSV record
typedef struct {
    char **columns;
    int num_columns;
} CsvRecord;

// Function to initialize a CsvRecord
CsvRecord* create_csv_record(int num_columns) {
    CsvRecord *record = malloc(sizeof(CsvRecord));
    record->num_columns = num_columns;
    record->columns = malloc(num_columns * sizeof(char*));
    for (int i = 0; i < num_columns; i++) {
        record->columns[i] = NULL;
    }
    return record;
}

// Function to free a CsvRecord
void free_csv_record(CsvRecord *record) {
    for (int i = 0; i < record->num_columns; i++) {
        free(record->columns[i]);
    }
    free(record->columns);
    free(record);
}

// Function to read a line from a file
char* read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        free(line);
        return NULL;
    }
    return line;
}

// Function to split a line into CSV columns
CsvRecord* split_csv_line(char *line) {
    CsvRecord *record = create_csv_record(MAX_NUM_COLUMNS);
    
    char *token = strtok(line, ",");
    int index = 0;

    while (token != NULL) {
        record->columns[index] = strdup(token);
        token = strtok(NULL, ",");
        index++;
    }
    record->num_columns = index;
    
    return record;
}

// Function to print a CSV record
void print_csv_record(CsvRecord *record) {
    for (int i = 0; i < record->num_columns; i++) {
        printf("Column %d: %s", i + 1, record->columns[i]);
        if (i < record->num_columns - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// The main CSV Reader implementation
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    printf("Reading file: %s\n", argv[1]);
    char *line;
    while ((line = read_line(file)) != NULL) {
        // Trim newline character
        line[strcspn(line, "\n")] = 0;
        
        CsvRecord *record = split_csv_line(line);
        print_csv_record(record);
        free_csv_record(record);
        
        free(line);
    }

    fclose(file);
    return EXIT_SUCCESS;
}