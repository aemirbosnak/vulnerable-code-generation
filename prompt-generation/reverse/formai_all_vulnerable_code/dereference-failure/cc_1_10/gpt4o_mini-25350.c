//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    size_t rows;
    size_t cols;
} CSVData;

CSVData* readCSV(const char *filename);
void freeCSVData(CSVData *csvData);
void printCSVData(const CSVData *csvData);
char** splitLine(const char *line, size_t *numCols);
void trimWhitespace(char *str);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    CSVData *csvData = readCSV(argv[1]);
    if (csvData == NULL) {
        fprintf(stderr, "Failed to read CSV file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    printCSVData(csvData);
    freeCSVData(csvData);
    
    return EXIT_SUCCESS;
}

CSVData* readCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    CSVData *csvData = malloc(sizeof(CSVData));
    if (!csvData) {
        perror("Failed to allocate memory for CSV data");
        fclose(file);
        return NULL;
    }

    csvData->data = malloc(MAX_COLUMNS * sizeof(char*));
    csvData->rows = 0;
    csvData->cols = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        size_t numCols;
        char **columns = splitLine(line, &numCols);
        
        if (numCols > 0) {
            csvData->data[csvData->rows] = malloc((numCols + 1) * sizeof(char*));
            for (size_t i = 0; i < numCols; i++) {
                csvData->data[csvData->rows][i] = columns[i];
            }
            csvData->data[csvData->rows][numCols] = NULL; // Null-terminate the row
            csvData->rows++;
            csvData->cols = numCols > csvData->cols ? numCols : csvData->cols;
        }
        free(columns);
    }

    fclose(file);
    return csvData;
}

void freeCSVData(CSVData *csvData) {
    for (size_t i = 0; i < csvData->rows; i++) {
        for (size_t j = 0; j < csvData->cols; j++) {
            free(csvData->data[i][j]);
        }
        free(csvData->data[i]);
    }
    free(csvData->data);
    free(csvData);
}

void printCSVData(const CSVData *csvData) {
    for (size_t i = 0; i < csvData->rows; i++) {
        for (size_t j = 0; j < csvData->cols; j++) {
            if (csvData->data[i][j] != NULL) {
                printf("%s", csvData->data[i][j]);
            }
            if (j < csvData->cols - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

char** splitLine(const char *line, size_t *numCols) {
    char *lineCopy = strdup(line);
    if (lineCopy == NULL) {
        return NULL;
    }
    
    char **columns = malloc(MAX_COLUMNS * sizeof(char*));
    if (!columns) {
        free(lineCopy);
        return NULL;
    }
    
    size_t count = 0;
    char *token = strtok(lineCopy, ",");
    while (token != NULL) {
        trimWhitespace(token);
        columns[count++] = strdup(token); // Allocate and copy the token
        token = strtok(NULL, ",");
    }
    
    free(lineCopy);
    *numCols = count;
    return columns;
}

void trimWhitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++; // Trim leading space
    if (*str == 0) return; // All spaces?
    
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--; // Trim trailing space
    *(end + 1) = '\0';
}