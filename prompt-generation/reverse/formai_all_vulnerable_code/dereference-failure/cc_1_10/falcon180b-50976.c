//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 100

typedef struct {
    char *data;
    int length;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} row_t;

typedef struct {
    row_t *rows;
    int num_rows;
} csv_t;

csv_t *csv_open(char *filename) {
    csv_t *csv = malloc(sizeof(csv_t));
    csv->rows = NULL;
    csv->num_rows = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        row_t *row = malloc(sizeof(row_t));
        row->fields = NULL;
        row->num_fields = 0;

        char *token = strtok(line, ",");
        while (token!= NULL) {
            field_t *field = malloc(sizeof(field_t));
            field->data = strdup(token);
            field->length = strlen(token);
            row->fields = realloc(row->fields, sizeof(field_t) * ++row->num_fields);
            row->fields[row->num_fields - 1] = *field;

            token = strtok(NULL, ",");
        }

        csv->rows = realloc(csv->rows, sizeof(row_t) * ++csv->num_rows);
        csv->rows[csv->num_rows - 1] = *row;
    }

    fclose(file);
    return csv;
}

void csv_print(csv_t *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        row_t *row = csv->rows + i;
        for (int j = 0; j < row->num_fields; j++) {
            field_t *field = row->fields + j;
            printf("%s\t", field->data);
        }
        printf("\n");
    }
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        row_t *row = csv->rows + i;
        for (int j = 0; j < row->num_fields; j++) {
            field_t *field = row->fields + j;
            free(field->data);
            free(field);
        }
        free(row->fields);
        free(row);
    }
    free(csv->rows);
    free(csv);
}

int main() {
    csv_t *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}