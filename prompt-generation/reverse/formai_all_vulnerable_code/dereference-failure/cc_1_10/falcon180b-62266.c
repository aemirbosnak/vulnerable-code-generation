//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int rows;
    int columns;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    if (csv == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    csv->data = (char **)malloc(MAX_LINE_SIZE * MAX_COLUMNS);
    if (csv->data == NULL) {
        printf("Error: Memory allocation failed.\n");
        free(csv);
        return NULL;
    }

    csv->rows = 0;
    csv->columns = 0;

    return csv;
}

void csv_destroy(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->columns; j++) {
            free(csv->data[i * csv->columns + j]);
        }
    }

    free(csv->data);
    free(csv);
}

int csv_read(CSV *csv, const char *filename) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char delimiter;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    csv->columns = ftell(fp) / MAX_LINE_SIZE;

    rewind(fp);
    fgets(line, MAX_LINE_SIZE, fp);
    delimiter = line[0];

    csv->data = (char **)realloc(csv->data, csv->columns * MAX_LINE_SIZE);

    csv->rows = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        csv->rows++;

        csv->data[csv->rows - 1] = (char *)malloc(csv->columns * MAX_LINE_SIZE);

        j = 0;
        for (i = 0; i < strlen(line); i++) {
            if (line[i] == delimiter) {
                line[i] = '\0';
                strcat(csv->data[csv->rows - 1], line);
                j++;
            }
        }
    }

    fclose(fp);

    return 0;
}

int csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->columns; j++) {
            printf("%s ", csv->data[i * csv->columns + j]);
        }
        printf("\n");
    }

    return 0;
}

int main() {
    CSV *csv;
    int ret;

    csv = csv_create();
    if (csv == NULL) {
        return -1;
    }

    ret = csv_read(csv, "example.csv");
    if (ret!= 0) {
        csv_destroy(csv);
        return ret;
    }

    csv_print(csv);

    csv_destroy(csv);

    return 0;
}