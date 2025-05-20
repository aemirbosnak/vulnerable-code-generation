//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t len;
} csv_row;

typedef struct {
    csv_row *rows;
    size_t nrows;
} csv_table;

csv_table *csv_read(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    csv_table *table = malloc(sizeof(csv_table));
    if (!table) {
        return NULL;
    }

    table->nrows = 0;
    table->rows = NULL;

    while ((read = getline(&line, &len, fp)) != -1) {
        char *p = line;
        csv_row *row = malloc(sizeof(csv_row));
        if (!row) {
            free(table);
            free(line);
            return NULL;
        }

        row->len = len;
        row->data = malloc(len + 1);
        if (!row->data) {
            free(table);
            free(line);
            free(row);
            return NULL;
        }

        while (*p) {
            if (*p == ',') {
                *p = '\0';
            }
            p++;
        }

        strcpy(row->data, line);
        table->rows = realloc(table->rows, (table->nrows + 1) * sizeof(csv_row));
        if (!table->rows) {
            free(table);
            free(line);
            free(row);
            return NULL;
        }

        table->rows[table->nrows] = *row;
        table->nrows++;
    }

    free(line);
    return table;
}

void csv_free(csv_table *table) {
    for (size_t i = 0; i < table->nrows; i++) {
        free(table->rows[i].data);
    }

    free(table->rows);
    free(table);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    csv_table *table = csv_read(fp);
    if (!table) {
        perror("csv_read");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < table->nrows; i++) {
        printf("%s\n", table->rows[i].data);
    }

    csv_free(table);
    fclose(fp);
    return EXIT_SUCCESS;
}