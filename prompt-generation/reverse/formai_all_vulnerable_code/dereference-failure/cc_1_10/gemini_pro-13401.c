//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct {
    char *data;
    size_t len;
} field_t;

typedef struct {
    field_t *fields;
    size_t num_fields;
    size_t capacity;
} row_t;

typedef struct {
    row_t *rows;
    size_t num_rows;
    size_t capacity;
} csv_t;

csv_t *csv_new() {
    csv_t *csv = malloc(sizeof(csv_t));
    if (csv == NULL) {
        return NULL;
    }

    csv->rows = NULL;
    csv->num_rows = 0;
    csv->capacity = 0;

    return csv;
}

void csv_free(csv_t *csv) {
    if (csv == NULL) {
        return;
    }

    for (size_t i = 0; i < csv->num_rows; i++) {
        row_t *row = &csv->rows[i];
        for (size_t j = 0; j < row->num_fields; j++) {
            field_t *field = &row->fields[j];
            free(field->data);
        }
        free(row->fields);
    }
    free(csv->rows);
    free(csv);
}

static bool csv_grow_rows(csv_t *csv, size_t new_capacity) {
    if (csv == NULL) {
        return false;
    }

    if (new_capacity <= csv->capacity) {
        return true;
    }

    row_t *new_rows = realloc(csv->rows, new_capacity * sizeof(row_t));
    if (new_rows == NULL) {
        return false;
    }

    csv->rows = new_rows;
    csv->capacity = new_capacity;

    return true;
}

static bool csv_grow_fields(row_t *row, size_t new_capacity) {
    if (row == NULL) {
        return false;
    }

    if (new_capacity <= row->capacity) {
        return true;
    }

    field_t *new_fields = realloc(row->fields, new_capacity * sizeof(field_t));
    if (new_fields == NULL) {
        return false;
    }

    row->fields = new_fields;
    row->capacity = new_capacity;

    return true;
}

bool csv_parse_line(csv_t *csv, const char *line) {
    if (csv == NULL || line == NULL) {
        return false;
    }

    size_t line_len = strlen(line);
    if (line_len + 1 > MAX_LINE_LENGTH) {
        return false;
    }

    if (!csv_grow_rows(csv, csv->num_rows + 1)) {
        return false;
    }

    row_t *row = &csv->rows[csv->num_rows];
    row->num_fields = 0;
    row->capacity = 0;
    row->fields = NULL;

    const char *start = line;
    const char *end = line;
    while (*end != '\0') {
        if (*end == ',') {
            if (!csv_grow_fields(row, row->num_fields + 1)) {
                return false;
            }

            field_t *field = &row->fields[row->num_fields];
            field->data = malloc(end - start + 1);
            if (field->data == NULL) {
                return false;
            }

            strncpy(field->data, start, end - start);
            field->data[end - start] = '\0';
            field->len = end - start;

            row->num_fields++;

            start = end + 1;
        }

        end++;
    }

    if (start != end) {
        if (!csv_grow_fields(row, row->num_fields + 1)) {
            return false;
        }

        field_t *field = &row->fields[row->num_fields];
        field->data = malloc(end - start + 1);
        if (field->data == NULL) {
            return false;
        }

        strncpy(field->data, start, end - start);
        field->data[end - start] = '\0';
        field->len = end - start;

        row->num_fields++;
    }

    csv->num_rows++;

    return true;
}

int main() {
    csv_t *csv = csv_new();
    if (csv == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for CSV.\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file \"data.csv\".\n");
        csv_free(csv);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (!csv_parse_line(csv, line)) {
            fprintf(stderr, "Error: Could not parse line \"%s\".\n", line);
            csv_free(csv);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);

    for (size_t i = 0; i < csv->num_rows; i++) {
        row_t *row = &csv->rows[i];
        for (size_t j = 0; j < row->num_fields; j++) {
            field_t *field = &row->fields[j];
            printf("%s", field->data);
            if (j < row->num_fields - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    csv_free(csv);

    return EXIT_SUCCESS;
}