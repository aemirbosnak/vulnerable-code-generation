//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_LEN 1000

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} CsvData;

int read_csv_file(FILE *fp, CsvData *data) {
    char line[MAX_CELL_LEN];
    char *token;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_LEN, fp)!= NULL) {
        token = strtok(line, ",");
        if (row >= MAX_ROWS || col >= MAX_COLS) {
            printf("Error: CSV file exceeds maximum size.\n");
            return -1;
        }
        data->rows[row] = realloc(data->rows[row], sizeof(char *) * (col + 2));
        data->rows[row][col] = strdup(token);
        col++;
        if (token[strlen(token) - 1] == '\n') {
            row++;
            col = 0;
        }
    }

    data->num_rows = row;
    data->num_cols = col;

    return 0;
}

int main() {
    FILE *fp;
    CsvData data;

    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open CSV file.\n");
        return -1;
    }

    data.rows = malloc(sizeof(char *) * MAX_ROWS);
    data.num_rows = 0;
    data.num_cols = 0;

    if (read_csv_file(fp, &data)!= 0) {
        fclose(fp);
        return -1;
    }

    fclose(fp);

    printf("CSV Data:\n");
    for (int i = 0; i < data.num_rows; i++) {
        for (int j = 0; j < data.num_cols; j++) {
            printf("%s ", data.rows[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < data.num_rows; i++) {
        free(data.rows[i]);
    }
    free(data.rows);

    return 0;
}