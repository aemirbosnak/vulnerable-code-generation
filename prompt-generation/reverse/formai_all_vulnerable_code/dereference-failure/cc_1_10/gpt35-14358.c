//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

/* Struct to hold CSV row */
typedef struct {
    char * data;
    int numOfCols;
} CSVRow;

/* Function to split a CSV row into columns */
CSVRow splitRow(char * line, const char * delimiter) {
    CSVRow row;
    row.data = NULL;
    row.numOfCols = 0;
    char * token;
    token = strtok(line, delimiter);
    while (token != NULL) {
        row.data = realloc(row.data, (row.numOfCols + 1) * sizeof(char *));
        row.data[row.numOfCols] = malloc(strlen(token) + 1);
        strcpy(row.data[row.numOfCols], token);
        row.numOfCols++;
        token = strtok(NULL, delimiter);        
    }
    return row;
}

int main() {
    char fileName[] = "data.csv";
    FILE * file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Cannot open %s.\n", fileName);
        return 1;
    }

    /* Read the first line to get headers */
    char line[MAX_LINE_LEN];
    if (fgets(line, MAX_LINE_LEN, file) == NULL) {
        fprintf(stderr, "Cannot read the first line from the file.\n");
        return 1;
    }

    /* Split the first line into headers */
    const char * delimiter = ",";
    CSVRow headers = splitRow(line, delimiter);

    /* Print the headers */
    for (int i = 0; i < headers.numOfCols; i++) {
        printf("%s\t", headers.data[i]);
    }
    printf("\n");

    /* Read the remaining lines and split them into columns */
    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        CSVRow row = splitRow(line, delimiter);

        /* Print the columns */
        for (int i = 0; i < row.numOfCols; i++) {
            printf("%s\t", row.data[i]);
        }
        printf("\n");

        /* Free memory used by row */
        for (int i = 0; i < row.numOfCols; i++) {
            free(row.data[i]);
        }
        free(row.data);
    }

    /* Free memory used by headers */
    for (int i = 0; i < headers.numOfCols; i++) {
        free(headers.data[i]);
    }
    free(headers.data);

    /* Close the file */
    fclose(file);

    return 0;
}