//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_ROWS 100

typedef struct {
    char *data[MAX_COLUMNS];
} Row;

typedef struct {
    char *column_names[MAX_COLUMNS];
    Row rows[MAX_ROWS];
    int num_rows;
    int num_columns;
} CSV;

CSV *read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    CSV *csv = (CSV *) calloc(1, sizeof(CSV));
    char line[1024];
    char *token;
    int is_first = 1;
    int row_i = 0;

    while (fgets(line, 1024, fp) != NULL) {
        token = strtok(line, ",");
        int col_i = 0;
        while (token != NULL) {
            if (is_first) {
                csv->column_names[col_i] = strdup(token);
            } else {
                csv->rows[row_i].data[col_i] = strdup(token);
            }
            token = strtok(NULL, ",");
            col_i++;
        }
        if (!is_first) {
            csv->rows[row_i].data[col_i] = NULL;
            row_i++;
            csv->num_rows = row_i;
            csv->num_columns = col_i;
        }
        is_first = 0;
    }

    fclose(fp);

    return csv;
}

void print_csv(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_columns; i++) {
        printf("%s", csv->column_names[i]);
        if (i < csv->num_columns - 1) {
            printf(",");
        }
    }
    printf("\n");

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_columns; j++) {
            printf("%s", csv->rows[i].data[j]);
            if (j < csv->num_columns - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    CSV *csv = read_csv(filename);
    if (!csv) {
        return 1;
    }

    print_csv(csv);

    return 0;
}