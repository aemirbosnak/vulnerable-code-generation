//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create() {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read_file(CSV *csv, FILE *fp) {
    char line[1024];
    char delim = ',';
    int row = 0;
    int col = 0;

    csv->data = malloc(sizeof(char *) * 10);

    while (fgets(line, sizeof(line), fp)!= NULL) {
        int len = strlen(line);
        if (len == 0 || line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char *token = strtok(line, &delim);
        while (token!= NULL) {
            csv->data[row] = realloc(csv->data[row], sizeof(char *) * ++csv->cols);
            csv->data[row][col++] = strdup(token);
            token = strtok(NULL, &delim);
        }
        row++;
    }

    csv->rows = row;
}

int main() {
    CSV *csv = csv_create();
    FILE *fp = fopen("data.csv", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    csv_read_file(csv, fp);

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_destroy(csv);
    fclose(fp);

    return 0;
}