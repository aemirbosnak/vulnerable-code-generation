//Falcon-180B DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} Table;

void read_csv(FILE *fp, Table *table) {
    char line[1024];
    int num_rows = 0;
    int num_cols = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;

        while (token!= NULL) {
            if (num_cols == 0) {
                table->num_cols = i + 1;
            }

            if (num_rows == 0) {
                table->data = (char **)malloc(table->num_cols * sizeof(char *));
            }

            table->data[num_rows] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(table->data[num_rows], token);

            num_cols = i + 1;
            num_rows++;

            token = strtok(NULL, ",");
            i++;
        }
    }

    table->num_rows = num_rows;
}

void print_table(Table *table) {
    int i, j;

    for (i = 0; i < table->num_rows; i++) {
        for (j = 0; j < table->num_cols; j++) {
            printf("%s\t", table->data[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    Table table;

    fp = fopen("data.csv", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_csv(fp, &table);

    fclose(fp);

    print_table(&table);

    return 0;
}