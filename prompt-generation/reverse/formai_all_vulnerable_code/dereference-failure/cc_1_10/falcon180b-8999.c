//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 1000

typedef struct {
    char **row_data;
    int num_cols;
    int num_rows;
} CSVFile;

CSVFile *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    CSVFile *csv = (CSVFile *)malloc(sizeof(CSVFile));

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    csv->row_data = (char **)malloc(MAX_ROW_SIZE * sizeof(char *));
    csv->num_cols = 0;
    csv->num_rows = 0;

    char line[MAX_ROW_SIZE];
    char *token = NULL;
    while (fgets(line, MAX_ROW_SIZE, fp)!= NULL) {
        int i = 0;
        csv->num_rows++;

        token = strtok(line, ",");
        while (token!= NULL) {
            csv->row_data[csv->num_cols] = (char *)malloc(strlen(token) + 1);
            strcpy(csv->row_data[csv->num_cols], token);

            csv->num_cols++;
            i++;
            token = strtok(NULL, ",");
        }
    }

    csv->row_data[csv->num_cols] = NULL;

    fclose(fp);

    return csv;
}

void csv_print(CSVFile *csv) {
    int i, j;

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->row_data[j]);
        }
        printf("\n");
    }
}

void csv_close(CSVFile *csv) {
    int i;

    for (i = 0; i < csv->num_cols; i++) {
        free(csv->row_data[i]);
    }
    free(csv->row_data);
    free(csv);
}

int main() {
    CSVFile *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}