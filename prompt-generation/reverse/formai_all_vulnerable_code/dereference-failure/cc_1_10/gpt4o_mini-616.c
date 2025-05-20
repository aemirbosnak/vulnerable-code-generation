//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Structure to hold data from CSV
typedef struct {
    char **data;
    int rows;
    int columns;
} CSVData;

// Function to read CSV file
CSVData* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    CSVData *csv_data = malloc(sizeof(CSVData));
    csv_data->data = malloc(MAX_COLUMNS * sizeof(char *));
    for (int i = 0; i < MAX_COLUMNS; i++) {
        csv_data->data[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    char line[MAX_LINE_LENGTH];
    csv_data->rows = 0;
    while (fgets(line, sizeof(line), file)) {
        strcpy(csv_data->data[csv_data->rows], line);
        csv_data->rows++;
    }

    csv_data->columns = 0; // Reset columns
    fgets(line, sizeof(line), file); // Read first line to calculate columns
    char *token = strtok(line, ",");
    while (token != NULL) {
        csv_data->columns++;
        token = strtok(NULL, ",");
    }
    fseek(file, 0, SEEK_SET); // Reset file pointer to the beginning

    fclose(file);
    return csv_data;
}

// Function to print CSVData
void print_csv(CSVData *csv_data) {
    for (int i = 0; i < csv_data->rows; i++) {
        printf("%s", csv_data->data[i]);
    }
}

// Function to free allocated memory
void free_csv_data(CSVData *csv_data) {
    for (int i = 0; i < MAX_COLUMNS; i++) {
        free(csv_data->data[i]);
    }
    free(csv_data->data);
    free(csv_data);
}

// Main execution point
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    CSVData *csv_data = read_csv(filename);
    if (csv_data != NULL) {
        print_csv(csv_data);
        free_csv_data(csv_data);
    }

    return 0;
}