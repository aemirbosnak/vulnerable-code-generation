//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    char *token = strtok(line, ",");

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        if (csv->data == NULL) {
            csv->data = malloc(sizeof(char *) * csv->cols);
            for (int i = 0; i < csv->cols; i++) {
                csv->data[i] = malloc(MAX_CELL_SIZE);
            }
        }

        if (csv->rows == MAX_ROWS - 1) {
            printf("CSV file has too many rows. Aborting.\n");
            exit(1);
        }

        if (csv->cols == MAX_COLS - 1) {
            printf("CSV file has too many columns. Aborting.\n");
            exit(1);
        }

        strcpy(csv->data[csv->cols], token);
        csv->cols++;
    }

    csv->rows = csv->cols;

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[j]);
        }
        printf("\n");
    }
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_create(fp);
    csv_print(csv);
    csv_destroy(csv);
    fclose(fp);

    return 0;
}