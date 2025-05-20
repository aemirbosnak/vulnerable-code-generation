//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **fields;
    int num_fields;
} csv_row;

typedef struct {
    csv_row **rows;
    int num_rows;
} csv_table;

csv_table *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    csv_table *table = malloc(sizeof(csv_table));
    table->num_rows = 0;
    table->rows = NULL;

    while ((read = getline(&line, &len, fp)) != -1) {
        csv_row *row = malloc(sizeof(csv_row));
        row->num_fields = 0;
        row->fields = NULL;

        char *field = strtok(line, ",");
        while (field != NULL) {
            row->fields = realloc(row->fields, (row->num_fields + 1) * sizeof(char *));
            row->fields[row->num_fields++] = strdup(field);

            field = strtok(NULL, ",");
        }

        table->rows = realloc(table->rows, (table->num_rows + 1) * sizeof(csv_row *));
        table->rows[table->num_rows++] = row;
    }

    free(line);
    fclose(fp);

    return table;
}

void csv_free(csv_table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        csv_row *row = table->rows[i];
        for (int j = 0; j < row->num_fields; j++) {
            free(row->fields[j]);
        }
        free(row);
    }
    free(table->rows);
    free(table);
}

int main(void) {
    csv_table *table = csv_read("data.csv");
    if (table == NULL) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < table->num_rows; i++) {
        csv_row *row = table->rows[i];
        for (int j = 0; j < row->num_fields; j++) {
            printf("%s ", row->fields[j]);
        }
        printf("\n");
    }

    csv_free(table);

    return EXIT_SUCCESS;
}