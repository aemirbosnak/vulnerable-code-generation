//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;    // Pointer to an array of strings (rows)
    int rows;       // Number of rows in the CSV
    int columns;    // Number of columns in the CSV
} CSVData;

// Function prototypes
CSVData* loadCSV(const char *filename);
void freeCSVData(CSVData *csv);
void printCSV(CSVData *csv);
void trim(char *str);
char** splitLine(char *line, int *columnCount);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CSVData *csv = loadCSV(argv[1]);
    if (!csv) {
        fprintf(stderr, "Error loading CSV file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printCSV(csv);
    freeCSVData(csv);

    return EXIT_SUCCESS;
}

CSVData* loadCSV(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    CSVData *csv = malloc(sizeof(CSVData));
    if (!csv) {
        fclose(file);
        perror("Error allocating memory for CSVData");
        return NULL;
    }

    csv->data = NULL;
    csv->rows = 0;
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        trim(line);

        int columnCount = 0;
        char **columns = splitLine(line, &columnCount);
        if (columns) {
            csv->data = realloc(csv->data, sizeof(char*) * (csv->rows + 1));
            csv->data[csv->rows] = malloc(sizeof(char) * MAX_COLUMNS);

            for (int i = 0; i < columnCount; i++) {
                snprintf(csv->data[csv->rows] + i * MAX_COLUMNS, MAX_COLUMNS, "%s", columns[i]);
            }
            csv->rows++;
            free(columns);
        }
    }

    fclose(file);
    csv->columns = csv->data ? (strlen(csv->data[0]) / MAX_COLUMNS) : 0; // Guess first line for column count
    return csv;
}

void freeCSVData(CSVData *csv) {
    if (csv) {
        for (int i = 0; i < csv->rows; i++) {
            free(csv->data[i]);
        }
        free(csv->data);
        free(csv);
    }
}

void printCSV(CSVData *csv) {
    for (int i = 0; i < csv->rows; i++) {
        printf("%s\n", csv->data[i]);
    }
}

void trim(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after trimming
    *(end + 1) = '\0';
}

char** splitLine(char *line, int *columnCount) {
    char **result = malloc(sizeof(char*) * MAX_COLUMNS);
    if (!result) return NULL;

    char *token = strtok(line, ",");
    *columnCount = 0;

    while (token != NULL && *columnCount < MAX_COLUMNS) {
        result[*columnCount] = malloc(strlen(token) + 1);
        if (result[*columnCount] == NULL) {
            // Clean up previously allocated memory
            for (int j = 0; j < *columnCount; j++) {
                free(result[j]);
            }
            free(result);
            return NULL;
        }
        strcpy(result[*columnCount], token);
        (*columnCount)++;
        token = strtok(NULL, ",");
    }

    return result;
}