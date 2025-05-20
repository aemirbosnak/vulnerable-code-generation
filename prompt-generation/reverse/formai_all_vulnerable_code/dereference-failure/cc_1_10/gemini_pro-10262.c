//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_table;

csv_table *csv_read(const char *filename, char delimiter) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    csv_table *table = malloc(sizeof(csv_table));
    table->data = NULL;
    table->num_rows = 0;
    table->num_cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        table->num_rows++;

        char *row_data = strdup(line);
        char *token = strtok(row_data, &delimiter);
        while (token) {
            table->num_cols++;
            table->data = realloc(table->data, sizeof(char *) * table->num_rows * table->num_cols);
            table->data[table->num_rows - 1][table->num_cols - 1] = strdup(token);
            token = strtok(NULL, &delimiter);
        }
        free(row_data);
    }

    fclose(file);

    return table;
}

void csv_free(csv_table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            free(table->data[i][j]);
        }
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

int main() {
    csv_table *table = csv_read("data.csv", ',');
    if (table == NULL) {
        printf("Error reading CSV file.\n");
        return 1;
    }

    printf("Table has %d rows and %d columns.\n", table->num_rows, table->num_cols);

    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }

    csv_free(table);

    return 0;
}