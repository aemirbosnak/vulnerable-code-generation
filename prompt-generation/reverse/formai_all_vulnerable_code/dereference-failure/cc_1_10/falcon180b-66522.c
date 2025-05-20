//Falcon-180B DATASET v1.0 Category: Database querying ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} Table;

Table *read_table(FILE *file) {
    Table *table = (Table *) malloc(sizeof(Table));
    table->rows = 0;
    table->cols = 0;
    table->data = (char **) malloc(MAX_ROWS * sizeof(char *));

    char line[MAX_DATA];
    while (fgets(line, MAX_DATA, file)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            table->data[table->rows] = (char *) malloc(strlen(token) + 1);
            strcpy(table->data[table->rows], token);
            table->rows++;
            cols++;
            token = strtok(NULL, ",");
        }
        table->cols = cols;
    }

    return table;
}

void print_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        for (int j = 0; j < table->cols; j++) {
            printf("%s ", table->data[i]);
        }
        printf("\n");
    }
}

void free_table(Table *table) {
    for (int i = 0; i < table->rows; i++) {
        free(table->data[i]);
    }
    free(table->data);
    free(table);
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Table *table = read_table(file);
    print_table(table);

    free_table(table);
    fclose(file);

    return 0;
}