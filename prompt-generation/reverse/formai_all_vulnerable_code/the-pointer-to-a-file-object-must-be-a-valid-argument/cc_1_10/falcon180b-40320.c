//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
// Ada Lovelace Style CSV Reader Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(FILE *file) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (csv->rows == 0) {
            int count = 0;
            char *token = strtok(line, ",");
            while (token!= NULL) {
                count++;
                token = strtok(NULL, ",");
            }
            csv->cols = count;
            csv->data = (char **) malloc(sizeof(char *) * csv->cols);
        } else {
            int count = 0;
            char *token = strtok(line, ",");
            while (token!= NULL) {
                csv->data[count] = token;
                count++;
                token = strtok(NULL, ",");
            }
        }
        csv->rows++;
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i*csv->cols+j]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i*csv->cols+j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *file = fopen("data.csv", "r");
    CSV *csv = csv_create(file);
    csv_print(csv);
    csv_free(csv);
    fclose(file);
    return 0;
}