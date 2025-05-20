//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 50

typedef struct {
    char **data;
    int rows;
    int columns;
} CSVData;

CSVData* create_csv_data(int rows, int columns) {
    CSVData* csv = (CSVData*)malloc(sizeof(CSVData));
    csv->data = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        csv->data[i] = (char*)malloc(columns * MAX_LINE_LENGTH * sizeof(char));
    }
    csv->rows = rows;
    csv->columns = columns;
    return csv;
}

void free_csv_data(CSVData* csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void trim_newline(char* str) {
    str[strcspn(str, "\n")] = 0;
}

void read_csv(const char* filename, CSVData* csv) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int row = 0;
    
    while (fgets(line, sizeof(line), file) && row < csv->rows) {
        trim_newline(line);
        char* token = strtok(line, ",");
        int column = 0;

        while (token != NULL && column < csv->columns) {
            strcpy(csv->data[row * csv->columns + column], token);
            token = strtok(NULL, ",");
            column++;
        }
        row++;
    }
    
    fclose(file);
}

void print_csv(CSVData* csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            printf("%s", csv->data[i * csv->columns + j]);
            if (j < csv->columns - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVData* csv = create_csv_data(100, MAX_COLUMNS);
    read_csv(argv[1], csv);
    print_csv(csv);
    free_csv_data(csv);

    return EXIT_SUCCESS;
}