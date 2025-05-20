//Falcon-180B DATASET v1.0 Category: Database querying ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_LEN 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

Table *create_table(int num_rows, int num_cols) {
    Table *table = malloc(sizeof(Table));
    table->data = malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        table->data[i] = malloc(sizeof(char) * num_cols);
        memset(table->data[i], '\0', num_cols);
    }
    table->num_rows = num_rows;
    table->num_cols = num_cols;
    return table;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            printf("%s ", table->data[i]);
        }
        printf("\n");
    }
}

void free_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

void read_table_from_file(Table *table, FILE *file) {
    char line[MAX_DATA_LEN];
    while (fgets(line, MAX_DATA_LEN, file)!= NULL) {
        for (int i = 0; i < table->num_rows; i++) {
            for (int j = 0; j < table->num_cols; j++) {
                if (strlen(line) > j) {
                    strncpy(table->data[i] + j * MAX_DATA_LEN, line, MAX_DATA_LEN);
                } else {
                    strcpy(table->data[i] + j * MAX_DATA_LEN, "");
                }
            }
        }
    }
}

void write_table_to_file(Table *table, FILE *file) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            fprintf(file, "%s ", table->data[i]);
        }
        fprintf(file, "\n");
    }
}

int main() {
    Table *table = create_table(3, 3);
    table->data[0] = strdup("1");
    table->data[1] = strdup("2");
    table->data[2] = strdup("3");
    print_table(table);

    FILE *file = fopen("table.txt", "w");
    write_table_to_file(table, file);
    fclose(file);

    Table *new_table = create_table(3, 3);
    read_table_from_file(new_table, fopen("table.txt", "r"));
    print_table(new_table);

    free_table(table);
    free_table(new_table);
    return 0;
}