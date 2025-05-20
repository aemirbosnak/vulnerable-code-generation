//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_read_file(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = malloc(MAX_LINE_SIZE * MAX_COLUMNS);

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int col_count = 0;
        while (token!= NULL) {
            csv->data[csv->num_rows][col_count] = token;
            col_count++;
            token = strtok(NULL, DELIMITER);
        }
        csv->num_rows++;
        csv->num_cols = col_count > csv->num_cols? col_count : csv->num_cols;
    }

    return csv;
}

void csv_print_data(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    CSV *csv = csv_read_file(fp);
    csv_print_data(csv);
    free(csv->data);
    free(csv);
    fclose(fp);
    return 0;
}