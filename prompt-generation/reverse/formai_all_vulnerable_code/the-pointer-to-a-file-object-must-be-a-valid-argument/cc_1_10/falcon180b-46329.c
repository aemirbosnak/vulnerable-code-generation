//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256

typedef struct field {
    char *data;
    int size;
} field_t;

typedef struct row {
    int num_fields;
    field_t *fields;
} row_t;

typedef struct csv_file {
    FILE *fp;
    int num_rows;
    row_t **rows;
} csv_file_t;

csv_file_t *csv_open(const char *filename) {
    csv_file_t *csv_file = (csv_file_t *) malloc(sizeof(csv_file_t));
    csv_file->fp = fopen(filename, "r");
    csv_file->num_rows = 0;
    csv_file->rows = (row_t **) malloc(sizeof(row_t *));
    return csv_file;
}

void csv_close(csv_file_t *csv_file) {
    fclose(csv_file->fp);
    free(csv_file->rows);
    free(csv_file);
}

row_t *csv_read_row(csv_file_t *csv_file) {
    char line[MAX_LINE_SIZE];
    char *data = NULL;
    int size = 0;
    field_t *fields = NULL;
    int num_fields = 0;

    if (fgets(line, MAX_LINE_SIZE, csv_file->fp) == NULL) {
        return NULL;
    }

    data = strtok(line, ",");
    while (data!= NULL) {
        fields = (field_t *) realloc(fields, sizeof(field_t) * ++num_fields);
        fields[num_fields - 1].data = data;
        fields[num_fields - 1].size = strlen(data);
        data = strtok(NULL, ",");
    }

    row_t *row = (row_t *) malloc(sizeof(row_t));
    row->num_fields = num_fields;
    row->fields = fields;
    csv_file->num_rows++;
    csv_file->rows = (row_t **) realloc(csv_file->rows, sizeof(row_t *) * csv_file->num_rows);
    csv_file->rows[csv_file->num_rows - 1] = row;

    return row;
}

void csv_print_row(row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i].data);
    }
    printf("\n");
}

int main() {
    csv_file_t *csv_file = csv_open("example.csv");
    row_t *row;

    while ((row = csv_read_row(csv_file))!= NULL) {
        csv_print_row(row);
    }

    csv_close(csv_file);

    return 0;
}