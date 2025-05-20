//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_read_file(FILE *fp) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = (char **) malloc(sizeof(char *));

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            csv->num_cols = i + 1;
            csv->data = (char **) realloc(csv->data, csv->num_cols * sizeof(char *));
            csv->data[i] = strdup(token);
            token = strtok(NULL, ",");
            i++;
        }
        csv->num_rows++;
    }

    return csv;
}

void csv_print_data(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i * csv->num_cols + j]);
        }
        printf("\n");
    }
}

void csv_free_data(CSV *csv) {
    int i;
    for (i = 0; i < csv->num_rows; i++) {
        free(csv->data[i * csv->num_cols]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_read_file(fp);
    csv_print_data(csv);
    csv_free_data(csv);
    fclose(fp);
    return 0;
}