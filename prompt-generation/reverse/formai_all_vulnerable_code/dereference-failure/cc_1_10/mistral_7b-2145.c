//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct CsvRecord {
    size_t colCount;
    char **values;
} CsvRecord;

CsvRecord *readCsvLine(FILE *file) {
    size_t colCount = 0;
    char **values = NULL;
    char line[1024];
    char *token = NULL;

    fgets(line, sizeof(line), file);

    if (line[0] == '\n') {
        free(values);
        return NULL;
    }

    token = strtok(line, ",");
    colCount = 1;

    values = calloc(colCount, sizeof(char *));

    while (token != NULL) {
        values[colCount - 1] = strdup(token);
        colCount++;

        values = realloc(values, sizeof(char *) * colCount);

        token = strtok(NULL, ",");
    }

    values[colCount - 1] = NULL;

    return malloc(sizeof(CsvRecord) + (colCount - 1) * sizeof(char *));
}

void freeCsvRecord(CsvRecord *record) {
    size_t i;

    for (i = 0; i < record->colCount; i++) {
        free(record->values[i]);
    }

    free(record->values);
    free(record);
}

int main() {
    FILE *file = fopen("data.csv", "r");
    CsvRecord *record = NULL;
    int i;

    if (file == NULL) {
        perror("Error opening CSV file");
        return EXIT_FAILURE;
    }

    while ((record = readCsvLine(file)) != NULL) {
        printf("\n");

        for (i = 0; i < record->colCount; i++) {
            printf("%s%s", record->values[i], i < record->colCount - 1 ? "," : "\n");
        }

        freeCsvRecord(record);
    }

    fclose(file);

    return EXIT_SUCCESS;
}