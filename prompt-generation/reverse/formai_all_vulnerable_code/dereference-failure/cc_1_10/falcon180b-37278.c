//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_ROW_LEN 1000
#define MAX_COL_LEN 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} CSV;

int read_csv_file(const char *filename, CSV *csv) {
    FILE *fp;
    char line[MAX_ROW_LEN];
    char *token;
    int row = 0;
    int col = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s.\n", filename);
        return 1;
    }

    csv->data = (char *)malloc(MAX_ROWS * MAX_COLS * sizeof(char));
    if (csv->data == NULL) {
        printf("Error: Out of memory.\n");
        fclose(fp);
        return 1;
    }

    while (fgets(line, MAX_ROW_LEN, fp)!= NULL) {
        if (row >= MAX_ROWS) {
            printf("Error: Too many rows in file.\n");
            fclose(fp);
            return 1;
        }
        if (col >= MAX_COLS) {
            printf("Error: Too many columns in file.\n");
            fclose(fp);
            return 1;
        }
        csv->rows = row + 1;
        csv->cols = col + 1;
        token = strtok(line, ",");
        while (token!= NULL) {
            if (col >= MAX_COL_LEN) {
                printf("Error: Column too long in file.\n");
                fclose(fp);
                return 1;
            }
            if (strlen(token) >= MAX_COL_LEN) {
                printf("Error: Value too long in file.\n");
                fclose(fp);
                return 1;
            }
            strcpy(csv->data + (row * MAX_COLS + col) * MAX_COL_LEN, token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    fclose(fp);
    return 0;
}

int main() {
    CSV csv;
    int status;

    status = read_csv_file("data.csv", &csv);
    if (status!= 0) {
        return status;
    }

    printf("CSV data:\n");
    for (int i = 0; i < csv.rows; i++) {
        for (int j = 0; j < csv.cols; j++) {
            printf("%s ", csv.data + (i * MAX_COLS + j) * MAX_COL_LEN);
        }
        printf("\n");
    }

    return 0;
}