//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int num_columns;
    int num_rows;
} CSV;

CSV *csv_create(void) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_columns = 0;
    csv->num_rows = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    int i;
    for (i = 0; i < csv->num_columns; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_read_file(CSV *csv, const char *filename) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *token;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return 1;
    }

    csv->num_columns = 0;
    csv->num_rows = 0;
    csv->data = malloc(sizeof(char *) * MAX_COLUMNS);

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        i = 0;
        token = strtok(line, ",");
        while (token!= NULL) {
            csv->data[i] = strdup(token);
            i++;
            token = strtok(NULL, ",");
        }
        csv->num_columns = i;
        csv->num_rows++;
    }

    fclose(fp);
    return 0;
}

void csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_columns; i++) {
        printf("%s ", csv->data[i]);
    }
    printf("\n");
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv;
    int ret;

    csv = csv_create();
    ret = csv_read_file(csv, "data.csv");
    if (ret!= 0) {
        csv_destroy(csv);
        return 1;
    }

    csv_print(csv);

    csv_destroy(csv);
    return 0;
}