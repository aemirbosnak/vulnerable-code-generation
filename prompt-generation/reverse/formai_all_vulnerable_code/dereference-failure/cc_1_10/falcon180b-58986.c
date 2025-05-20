//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char *name;
    int length;
} Field;

typedef struct {
    int num_fields;
    Field *fields;
} Row;

typedef struct {
    int num_rows;
    Row *rows;
} CSV;

int read_csv(FILE *fp, CSV *csv) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int field_count = 0;
    Row *row = csv->rows + csv->num_rows;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int length = strlen(line);
        if (length == 0 || line[length - 1] == '\r') {
            continue;
        }
        token = strtok(line, ",");
        while (token!= NULL) {
            if (field_count >= MAX_FIELDS) {
                printf("Error: Too many fields in row.\n");
                return 1;
            }
            row->fields[field_count].name = strdup(token);
            row->fields[field_count].length = strlen(token);
            field_count++;
            token = strtok(NULL, ",");
        }
        csv->num_rows++;
        row = csv->rows + csv->num_rows;
        field_count = 0;
    }

    return 0;
}

int print_csv(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->rows[i].num_fields; j++) {
            printf("%s ", csv->rows[i].fields[j].name);
        }
        printf("\n");
    }
    return 0;
}

int main() {
    CSV csv;
    FILE *fp;

    csv.num_rows = 0;
    csv.rows = malloc(sizeof(Row) * MAX_FIELDS);

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    read_csv(fp, &csv);

    fclose(fp);

    print_csv(&csv);

    free(csv.rows);

    return 0;
}