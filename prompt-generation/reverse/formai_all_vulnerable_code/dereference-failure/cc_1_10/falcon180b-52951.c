//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    if (table == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }

    table->data = (char **)malloc(num_rows * sizeof(char *));
    if (table->data == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }

    table->num_rows = num_rows;
    table->num_cols = num_cols;

    for (int i = 0; i < num_rows; i++) {
        table->data[i] = (char *)malloc((num_cols + 1) * sizeof(char));
        if (table->data[i] == NULL) {
            printf("Error: Out of memory!\n");
            exit(1);
        }
        memset(table->data[i], '\0', num_cols + 1);
    }

    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%c", table->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = create_table(5, 3);

    strcpy(table->data[0], "John");
    strcpy(table->data[1], "Doe");
    strcpy(table->data[2], "Jane");
    strcpy(table->data[3], "Smith");
    strcpy(table->data[4], "Alice");

    print_table(table);

    destroy_table(table);

    return 0;
}