//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_LEN 1000

typedef struct {
    char **data;
    int num_cols;
    int num_rows;
} Table;

Table *create_table(int num_cols, int num_rows) {
    Table *table = malloc(sizeof(Table));
    table->data = malloc(num_cols * sizeof(char*));
    table->num_cols = num_cols;
    table->num_rows = num_rows;
    for (int i = 0; i < num_cols; i++) {
        table->data[i] = malloc(MAX_DATA_LEN);
        memset(table->data[i], 0, MAX_DATA_LEN);
    }
    return table;
}

void destroy_table(Table *table) {
    for (int i = 0; i < table->num_cols; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

int main() {
    Table *table = create_table(3, 5);
    char *data1 = "John";
    char *data2 = "Doe";
    char *data3 = "25";
    strcpy(table->data[0], data1);
    strcpy(table->data[1], data2);
    strcpy(table->data[2], data3);
    printf("Table:\n");
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[j]);
        }
        printf("\n");
    }
    destroy_table(table);
    return 0;
}