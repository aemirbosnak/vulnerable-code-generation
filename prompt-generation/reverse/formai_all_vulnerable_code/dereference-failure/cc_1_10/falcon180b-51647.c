//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_ELEM_LEN 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_file_t;

csv_file_t *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char line[MAX_ELEM_LEN];
    csv_file_t *csv = (csv_file_t *) malloc(sizeof(csv_file_t));
    csv->data = (char **) malloc(sizeof(char *) * MAX_ROWS);
    csv->num_rows = 0;
    csv->num_cols = 0;

    while (fgets(line, MAX_ELEM_LEN, fp)!= NULL) {
        char *row = strdup(line);
        char *token = strtok(row, ",");
        int col_count = 0;
        while (token!= NULL) {
            csv->num_cols = (col_count > csv->num_cols)? col_count : csv->num_cols;
            csv->data[csv->num_rows] = (char *) malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(csv->data[csv->num_rows], token);
            csv->num_rows++;
            token = strtok(NULL, ",");
            col_count++;
        }
        free(row);
    }

    csv->data[csv->num_rows] = NULL;
    fclose(fp);

    return csv;
}

void csv_close(csv_file_t *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(csv_file_t *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main() {
    csv_file_t *csv = csv_open("data.csv");
    if (csv!= NULL) {
        csv_print(csv);
        csv_close(csv);
    }

    return 0;
}