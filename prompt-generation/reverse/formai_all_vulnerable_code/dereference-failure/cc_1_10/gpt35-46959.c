//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FIELD_LENGTH 32
#define MAX_FIELDS 10

// Custom data structure to hold CSV data
typedef struct {
    char** fields;
} CSVRow;

// Function to parse a CSV row and populate the fields array
CSVRow parse_row(char* row) {
    CSVRow csv_row;
    csv_row.fields = (char**)malloc(MAX_FIELDS * sizeof(char*));

    char *token, *saved, *remaining;
    int field_count = 0;
    remaining = row;

    while ((token = strtok_r(remaining, ",", &saved))) {
        csv_row.fields[field_count++] = token;
        remaining = NULL;
    }

    return csv_row;
}

// Function to read the CSV file and return an array of CSVRow
CSVRow* read_csv(char* filename, int* n_rows) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open CSV file: %s\n", filename);
        exit(-1);
    }

    char line[MAX_LINE_LENGTH];
    CSVRow* csv_data = (CSVRow*)malloc(1000 * sizeof(CSVRow));
    int count = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        CSVRow row = parse_row(line);
        csv_data[count++] = row;
    }

    fclose(fp);
    *n_rows = count;
    return csv_data;
}

int main() {
    int n_rows;
    CSVRow* csv_data = read_csv("data.csv", &n_rows);

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; csv_data[i].fields[j] != NULL; j++) {
            printf("%s ", csv_data[i].fields[j]);
        }
        printf("\n");
    }

    free(csv_data);
    return 0;
}