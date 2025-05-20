//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_LINE_LEN 1024

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} CSV;

CSV *csv_read(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = NULL;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            if (i >= MAX_COLS) {
                printf("Error: too many columns\n");
                exit(1);
            }
            csv->data[csv->num_rows] = malloc(MAX_LINE_LEN);
            strcpy(csv->data[csv->num_rows], token);
            csv->num_cols = i + 1;
            csv->num_rows++;
            token = strtok(NULL, ",");
            i++;
        }
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp;
    fp = fopen("example.csv", "r");

    CSV *csv = csv_read(fp);
    csv_print(csv);

    csv_free(csv);
    fclose(fp);

    return 0;
}