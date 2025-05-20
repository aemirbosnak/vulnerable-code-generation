//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *field;
    size_t len;
} field_t;

typedef struct {
    field_t *fields;
    size_t num_fields;
} row_t;

typedef struct {
    row_t *rows;
    size_t num_rows;
} csv_t;

csv_t *csv_new() {
    csv_t *csv = malloc(sizeof(csv_t));
    if (!csv) {
        return NULL;
    }
    csv->rows = NULL;
    csv->num_rows = 0;
    return csv;
}

void csv_free(csv_t *csv) {
    if (!csv) {
        return;
    }
    for (size_t i = 0; i < csv->num_rows; i++) {
        for (size_t j = 0; j < csv->rows[i].num_fields; j++) {
            free(csv->rows[i].fields[j].field);
        }
        free(csv->rows[i].fields);
    }
    free(csv->rows);
    free(csv);
}

int csv_read(csv_t *csv, FILE *fp) {
    if (!csv || !fp) {
        return -1;
    }
    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        size_t line_len = strlen(line);
        if (line_len > 0 && line[line_len - 1] == '\n') {
            line_len--;
        }
        row_t row;
        row.num_fields = 0;
        row.fields = NULL;
        for (size_t i = 0; i < line_len; i++) {
            if (line[i] == ',') {
                row.num_fields++;
            }
        }
        row.fields = malloc(sizeof(field_t) * row.num_fields);
        if (!row.fields) {
            csv_free(csv);
            return -1;
        }
        size_t field_start = 0;
        size_t field_end = 0;
        for (size_t i = 0; i < line_len; i++) {
            if (line[i] == ',') {
                field_end = i;
                row.fields[row.num_fields - 1].len = field_end - field_start;
                row.fields[row.num_fields - 1].field = malloc(row.fields[row.num_fields - 1].len + 1);
                if (!row.fields[row.num_fields - 1].field) {
                    csv_free(csv);
                    return -1;
                }
                memcpy(row.fields[row.num_fields - 1].field, &line[field_start], row.fields[row.num_fields - 1].len);
                row.fields[row.num_fields - 1].field[row.fields[row.num_fields - 1].len] = '\0';
                field_start = i + 1;
            }
        }
        field_end = line_len;
        row.fields[row.num_fields - 1].len = field_end - field_start;
        row.fields[row.num_fields - 1].field = malloc(row.fields[row.num_fields - 1].len + 1);
        if (!row.fields[row.num_fields - 1].field) {
            csv_free(csv);
            return -1;
        }
        memcpy(row.fields[row.num_fields - 1].field, &line[field_start], row.fields[row.num_fields - 1].len);
        row.fields[row.num_fields - 1].field[row.fields[row.num_fields - 1].len] = '\0';
        csv->num_rows++;
        csv->rows = realloc(csv->rows, sizeof(row_t) * csv->num_rows);
        if (!csv->rows) {
            csv_free(csv);
            return -1;
        }
        csv->rows[csv->num_rows - 1] = row;
    }
    return 0;
}

int csv_write(csv_t *csv, FILE *fp) {
    if (!csv || !fp) {
        return -1;
    }
    for (size_t i = 0; i < csv->num_rows; i++) {
        for (size_t j = 0; j < csv->rows[i].num_fields; j++) {
            fprintf(fp, "%s", csv->rows[i].fields[j].field);
            if (j < csv->rows[i].num_fields - 1) {
                fprintf(fp, ",");
            }
        }
        fprintf(fp, "\n");
    }
    return 0;
}

int main() {
    csv_t *csv = csv_new();
    if (!csv) {
        return -1;
    }
    FILE *fp = fopen("input.csv", "r");
    if (!fp) {
        csv_free(csv);
        return -1;
    }
    if (csv_read(csv, fp) != 0) {
        csv_free(csv);
        fclose(fp);
        return -1;
    }
    fclose(fp);
    fp = fopen("output.csv", "w");
    if (!fp) {
        csv_free(csv);
        return -1;
    }
    if (csv_write(csv, fp) != 0) {
        csv_free(csv);
        fclose(fp);
        return -1;
    }
    fclose(fp);
    csv_free(csv);
    return 0;
}