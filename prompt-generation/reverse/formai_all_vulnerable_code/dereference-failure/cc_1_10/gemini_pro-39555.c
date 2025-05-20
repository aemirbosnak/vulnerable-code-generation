//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CSVRow {
    int numFields;
    char **fields;
} CSVRow;

CSVRow *readCSVRow(FILE *fp) {
    // Read the line
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        return NULL;
    }

    // Count the number of fields
    int numFields = 0;
    char *field = strtok(line, ",");
    while (field != NULL) {
        numFields++;
        field = strtok(NULL, ",");
    }

    // Allocate memory for the CSV row
    CSVRow *row = malloc(sizeof(CSVRow));
    row->numFields = numFields;
    row->fields = malloc(sizeof(char *) * numFields);

    // Store the fields
    field = strtok(line, ",");
    int i = 0;
    while (field != NULL) {
        row->fields[i] = strdup(field);
        field = strtok(NULL, ",");
        i++;
    }

    // Return the CSV row
    return row;
}

void freeCSVRow(CSVRow *row) {
    // Free the fields
    for (int i = 0; i < row->numFields; i++) {
        free(row->fields[i]);
    }

    // Free the CSV row
    free(row);
}

int main() {
    // Open the CSV file
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening CSV file");
        return EXIT_FAILURE;
    }

    // Read the CSV rows
    CSVRow *row;
    while ((row = readCSVRow(fp)) != NULL) {
        // Print the CSV row
        for (int i = 0; i < row->numFields; i++) {
            printf("%s", row->fields[i]);
            if (i < row->numFields - 1) {
                printf(",");
            }
        }
        printf("\n");

        // Free the CSV row
        freeCSVRow(row);
    }

    // Close the CSV file
    fclose(fp);

    return EXIT_SUCCESS;
}