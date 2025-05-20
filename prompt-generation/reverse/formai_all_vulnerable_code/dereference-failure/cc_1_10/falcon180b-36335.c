//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} Table;

void paranoid_init(Table *table) {
    table->num_rows = 0;
    table->num_cols = 0;
    table->data = NULL;
}

void paranoid_destroy(Table *table) {
    if (table->data!= NULL) {
        for (int i = 0; i < table->num_rows; i++) {
            for (int j = 0; j < table->num_cols; j++) {
                free(table->data[i][j]);
            }
            free(table->data[i]);
        }
        free(table->data);
    }
}

void paranoid_read_csv(Table *table, FILE *fp) {
    char line[MAX_DATA_SIZE];
    char *token;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_DATA_SIZE, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (col >= table->num_cols) {
                table->num_cols++;
                for (int i = 0; i < table->num_rows; i++) {
                    table->data[i] = (char **)realloc(table->data[i], table->num_cols * sizeof(char *));
                    table->data[i][table->num_cols - 1] = NULL;
                }
            }
            if (row >= table->num_rows) {
                table->num_rows++;
                table->data = (char **)realloc(table->data, table->num_rows * sizeof(char *));
                table->data[row] = (char *)malloc(table->num_cols * sizeof(char));
                for (int j = 0; j < table->num_cols; j++) {
                    table->data[row][j] = NULL;
                }
            }
            strcpy(table->data[row][col], token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }
}

void paranoid_write_csv(Table *table, FILE *fp) {
    for (int i = 0; i < table->num_rows; i++) {
        for (int j = 0; j < table->num_cols; j++) {
            fprintf(fp, "%s,", table->data[i][j]);
        }
        fprintf(fp, "\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_fp = fopen(argv[1], "r");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output_fp = fopen(argv[2], "w");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_fp);
        return 1;
    }

    Table table;
    paranoid_init(&table);

    paranoid_read_csv(&table, input_fp);

    fclose(input_fp);
    fclose(output_fp);

    return 0;
}