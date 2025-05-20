//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char *header;
    int num_rows;
    int num_cols;
    char **data;
} Table;

Table *create_table(char *header, int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->header = strdup(header);
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    table->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc(num_cols * sizeof(char));
    }
    return table;
}

void destroy_table(Table *table) {
    free(table->header);
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    printf("+%s+\n", table->header);
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table("Example Table", 3, 3);
    table->data[0][0] = strdup("1");
    table->data[0][1] = strdup("2");
    table->data[0][2] = strdup("3");
    table->data[1][0] = strdup("4");
    table->data[1][1] = strdup("5");
    table->data[1][2] = strdup("6");
    table->data[2][0] = strdup("7");
    table->data[2][1] = strdup("8");
    table->data[2][2] = strdup("9");
    print_table(table);
    destroy_table(table);
    return 0;
}