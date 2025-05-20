//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} csv_row_t;

typedef struct {
    csv_row_t **rows;
    int num_rows;
} csv_table_t;

csv_row_t *csv_row_new() {
    csv_row_t *row = malloc(sizeof(csv_row_t));
    row->fields = NULL;
    row->num_fields = 0;
    return row;
}

void csv_row_free(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

csv_table_t *csv_table_new() {
    csv_table_t *table = malloc(sizeof(csv_table_t));
    table->rows = NULL;
    table->num_rows = 0;
    return table;
}

void csv_table_free(csv_table_t *table) {
    for (int i = 0; i < table->num_rows; i++) {
        csv_row_free(table->rows[i]);
    }
    free(table->rows);
    free(table);
}

int csv_table_read_file(csv_table_t *table, FILE *fp) {
    char line[MAX_LINE_SIZE];
    csv_row_t *row = NULL;
    char *token;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (row == NULL) {
            row = csv_row_new();
            table->rows[table->num_rows++] = row;
        }

        token = strtok(line, ",");
        while (token!= NULL) {
            row->fields[num_fields++] = strdup(token);
            token = strtok(NULL, ",");
        }

        row->num_fields = num_fields;
        num_fields = 0;
    }

    if (row!= NULL) {
        csv_row_free(row);
    }

    return num_fields;
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    csv_table_t table;
    csv_table_read_file(&table, fp);
    fclose(fp);

    for (int i = 0; i < table.num_rows; i++) {
        for (int j = 0; j < table.rows[i]->num_fields; j++) {
            printf("%s\t", table.rows[i]->fields[j]);
        }
        printf("\n");
    }

    csv_table_free(&table);
    return 0;
}