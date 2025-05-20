//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_read(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    char *token = NULL;
    int row = 0;
    int col = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        row++;
        csv->rows++;

        char *data = strdup(line);
        csv->data = realloc(csv->data, sizeof(char *) * row);
        csv->data[row - 1] = data;

        token = strtok(data, DELIMITER);
        while (token!= NULL) {
            col++;
            csv->cols = col > csv->cols? col : csv->cols;

            csv->data[row - 1] = realloc(csv->data[row - 1], sizeof(char) * (strlen(csv->data[row - 1]) + strlen(token) + 2));
            strcat(csv->data[row - 1], token);
            strcat(csv->data[row - 1], DELIMITER);

            token = strtok(NULL, DELIMITER);
        }
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s", csv->data[i]);
            if (j < csv->cols - 1) {
                printf(DELIMITER);
            }
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSV *csv = csv_read(file);
    csv_print(csv);
    csv_free(csv);

    return 0;
}