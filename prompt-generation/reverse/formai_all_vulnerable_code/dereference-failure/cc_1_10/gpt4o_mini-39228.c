//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to print the contents of the CSV
void printCSV(char ***data, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (data[i][j] != NULL) {
                printf("%s ", data[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to split a line into fields based on the delimiter
int splitLine(char *line, char **fields, const char delimiter) {
    int count = 0;
    char *token = strtok(line, &delimiter);
    while (token != NULL) {
        fields[count++] = strdup(token);
        token = strtok(NULL, &delimiter);
    }
    return count;
}

// The main CSV reader function
void readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    char ***data = malloc(MAX_FIELDS * sizeof(char **));
    int row = 0;
    int columns = 0;

    while (fgets(line, sizeof(line), file)) {
        columns = splitLine(line, fields, ',');
        data[row] = malloc((columns + 1) * sizeof(char*));

        for (int i = 0; i < columns; i++) {
            data[row][i] = fields[i];
        }
        data[row][columns] = NULL; // Null-terminate the fields
        row++;
    }

    fclose(file);

    printf("CSV Contents:\n");
    printCSV(data, row, columns);

    // Clean Up
    for (int i = 0; i < row; i++) {
        for (int j = 0; data[i][j] != NULL; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(fields);
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    readCSV(argv[1]);
    
    return 0;
}