//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_reader(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char **row_data = malloc(MAX_COLUMNS * sizeof(char *));
        int num_cols = 0;

        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            row_data[num_cols] = strdup(token);
            num_cols++;
            token = strtok(NULL, DELIMITER);
        }

        csv->data = realloc(csv->data, sizeof(char *) * csv->num_rows * csv->num_cols);
        for (int i = 0; i < csv->num_rows; i++) {
            csv->data[i * csv->num_cols + num_cols - 1] = strdup("");
        }

        csv->num_rows++;
        csv->num_cols = num_cols > csv->num_cols? num_cols : csv->num_cols;
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            free(csv->data[i * csv->num_cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    CSV *csv = csv_reader(fp);

    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[i * csv->num_cols + j]);
        }
        printf("\n");
    }

    csv_destroy(csv);
    fclose(fp);

    return 0;
}