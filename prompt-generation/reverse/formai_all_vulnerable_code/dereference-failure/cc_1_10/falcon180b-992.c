//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 1000
#define MAX_LINE_LENGTH 4096

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (csv->num_rows == MAX_ROWS) {
            printf("Error: maximum number of rows exceeded\n");
            exit(1);
        }
        if (csv->num_columns == MAX_COLUMNS) {
            printf("Error: maximum number of columns exceeded\n");
            exit(1);
        }
        token = strtok(line, ",");
        while (token!= NULL) {
            if (csv->num_columns == MAX_COLUMNS) {
                printf("Error: maximum number of columns exceeded\n");
                exit(1);
            }
            csv->data[csv->num_rows][csv->num_columns++] = strdup(token);
            token = strtok(NULL, ",");
        }
        csv->num_rows++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_columns; j++) {
            printf("%s\t", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_columns; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char *argv[]) {
    CSV *csv;
    csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);
    return 0;
}