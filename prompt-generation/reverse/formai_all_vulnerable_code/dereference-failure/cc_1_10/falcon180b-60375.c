//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    int num_fields;
    field_t fields[MAX_FIELDS];
} row_t;

typedef struct {
    int num_rows;
    row_t rows[MAX_FIELDS];
} csv_t;

csv_t *csv_open(const char *filename) {
    csv_t *csv = malloc(sizeof(csv_t));
    csv->num_rows = 0;
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, file)) {
        row_t row;
        char *token = strtok(line, ",");
        int num_fields = 0;
        while (token) {
            if (num_fields >= MAX_FIELDS) {
                fprintf(stderr, "Too many fields in row\n");
                exit(1);
            }
            field_t field;
            field.name = strdup(token);
            field.value = NULL;
            row.fields[num_fields++] = field;
            token = strtok(NULL, ",");
        }
        row.num_fields = num_fields;
        csv->rows[csv->num_rows++] = row;
    }
    fclose(file);
    return csv;
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_fields; j++) {
            free(csv->rows[i].fields[j].name);
        }
        free(csv->rows[i].fields);
    }
    free(csv->rows);
    free(csv);
}

int main() {
    csv_t *csv = csv_open("example.csv");
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_fields; j++) {
            printf("%s: %s\n", csv->rows[i].fields[j].name, csv->rows[i].fields[j].value);
        }
    }
    csv_close(csv);
    return 0;
}