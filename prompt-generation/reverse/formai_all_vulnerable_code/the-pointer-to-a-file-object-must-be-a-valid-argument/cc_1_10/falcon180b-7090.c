//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100
#define MAX_FIELD_LEN 256

typedef struct {
    char *data;
    int len;
} string_t;

typedef struct {
    string_t *fields[MAX_FIELDS];
    int num_fields;
} row_t;

typedef struct {
    FILE *fp;
    int eof;
    row_t current_row;
} csv_t;

csv_t *csv_open(const char *filename) {
    csv_t *csv = malloc(sizeof(csv_t));
    csv->fp = fopen(filename, "r");
    csv->eof = 0;
    csv->current_row.num_fields = 0;
    return csv;
}

void csv_close(csv_t *csv) {
    fclose(csv->fp);
    free(csv);
}

int csv_get_next_row(csv_t *csv, row_t *row) {
    char line[MAX_LINE_LEN];
    char *token;
    char *saveptr;
    int i = 0;

    if (csv->eof) {
        return 0;
    }

    if (fgets(line, MAX_LINE_LEN, csv->fp) == NULL) {
        csv->eof = 1;
        return 0;
    }

    token = strtok_r(line, ",", &saveptr);
    while (token!= NULL) {
        if (i >= MAX_FIELDS) {
            break;
        }
        csv->current_row.fields[i] = malloc(sizeof(string_t));
        csv->current_row.fields[i]->data = strdup(token);
        csv->current_row.fields[i]->len = strlen(token);
        i++;
        token = strtok_r(NULL, ",", &saveptr);
    }
    csv->current_row.num_fields = i;

    *row = csv->current_row;
    return 1;
}

void csv_print_row(const row_t *row) {
    int i;

    for (i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]->data);
    }
    printf("\n");
}

int main() {
    csv_t *csv = csv_open("example.csv");
    row_t row;

    while (csv_get_next_row(csv, &row)) {
        csv_print_row(&row);
    }

    csv_close(csv);

    return 0;
}