//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int numFields;
} CsvRow;

void freeCsvRow(CsvRow *row) {
    for (int i = 0; i < row->numFields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
}

CsvRow *parseCsvLine(char *line) {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->fields = malloc(MAX_FIELDS * sizeof(char*));
    row->numFields = 0;

    char *token = strtok(line, ",");
    while (token != NULL) {
        row->fields[row->numFields] = malloc(strlen(token) + 1);
        strcpy(row->fields[row->numFields], token);
        row->numFields++;
        token = strtok(NULL, ",");
    }
    return row;
}

void printCsvRow(CsvRow *row) {
    for (int i = 0; i < row->numFields; i++) {
        printf("%s", row->fields[i]);
        if (i < row->numFields - 1) {
            printf(" | ");
        }
    }
    printf("\n");
}

void readCsvFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove the newline character
        line[strcspn(line, "\n")] = 0;

        CsvRow *row = parseCsvLine(line);
        printCsvRow(row);
        freeCsvRow(row);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Reading CSV file: %s\n", argv[1]);
    readCsvFile(argv[1]);

    return EXIT_SUCCESS;
}