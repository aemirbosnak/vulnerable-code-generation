//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_COLS 1000 // Maximum columns in CSV file
#define MAX_CSV_ROWS 1000 // Maximum rows in CSV file

typedef struct {
    char **values; // Array of strings representing the CSV values
    int num_cols; // Number of columns in CSV file
    int num_rows; // Number of rows in CSV file
} CSV;

void init_csv(CSV *csv) {
    csv->values = NULL;
    csv->num_cols = 0;
    csv->num_rows = 0;
}

void destroy_csv(CSV *csv) {
    int i;
    for (i = 0; i < csv->num_cols; i++) {
        free(csv->values[i]);
    }
    free(csv->values);
    csv->values = NULL;
    csv->num_cols = 0;
    csv->num_rows = 0;
}

void read_csv(CSV *csv, char *filename) {
    FILE *fp;
    char line[4096];
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    csv->num_cols = 0;
    csv->num_rows = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int num_tokens = 0;

        while (token!= NULL) {
            num_tokens++;
            if (csv->num_cols <= MAX_CSV_COLS && num_tokens > csv->num_cols) {
                csv->num_cols = num_tokens;
            }
            if (csv->num_rows <= MAX_CSV_ROWS) {
                csv->num_rows++;
            }

            if (csv->values == NULL) {
                csv->values = (char **)malloc(csv->num_cols * sizeof(char *));
            } else {
                csv->values = (char **)realloc(csv->values, csv->num_cols * sizeof(char *));
            }

            csv->values[csv->num_cols - 1] = strdup(token);

            token = strtok(NULL, ",");
        }

        if (csv->values == NULL) {
            csv->values = (char **)malloc(csv->num_cols * sizeof(char *));
        } else {
            csv->values = (char **)realloc(csv->values, csv->num_cols * sizeof(char *));
        }

        csv->values[csv->num_cols - 1] = NULL; // Set last element to NULL
    }

    fclose(fp);
}

void print_csv(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->values[j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    CSV csv;

    init_csv(&csv);
    read_csv(&csv, "example.csv");
    print_csv(&csv);

    destroy_csv(&csv);

    return 0;
}