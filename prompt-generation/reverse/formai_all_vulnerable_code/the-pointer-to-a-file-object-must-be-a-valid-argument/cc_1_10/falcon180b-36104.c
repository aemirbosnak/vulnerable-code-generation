//Falcon-180B DATASET v1.0 Category: Database querying ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_ROW_LENGTH 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

void init_table(Table *table) {
    table->data = NULL;
    table->num_rows = 0;
    table->num_cols = 0;
}

void free_table(Table *table) {
    int i;
    for (i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    table->data = NULL;
}

void add_row(Table *table, char *row) {
    table->data = realloc(table->data, sizeof(char *) * (table->num_rows + 1));
    table->data[table->num_rows] = strdup(row);
    table->num_rows++;
}

int main() {
    Table table;
    init_table(&table);

    FILE *fp = fopen("data.csv", "r");
    char line[MAX_ROW_LENGTH];
    while (fgets(line, MAX_ROW_LENGTH, fp)!= NULL) {
        char *row = strdup(line);
        add_row(&table, row);
    }
    fclose(fp);

    int num_cols = 0;
    char *header = table.data[0];
    char *token = strtok(header, ",");
    while (token!= NULL) {
        num_cols++;
        token = strtok(NULL, ",");
    }
    table.num_cols = num_cols;

    printf("+----+");
    for (int i = 0; i < num_cols; i++) {
        printf("+%s+", table.data[0][i]);
    }
    printf("\n");

    for (int i = 1; i < table.num_rows; i++) {
        printf("|");
        for (int j = 0; j < num_cols; j++) {
            printf(" %s ", table.data[i][j]);
        }
        printf("|\n");
    }

    free_table(&table);
    return 0;
}