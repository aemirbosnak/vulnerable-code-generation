//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct csv_row {
    char **data;
    int num_columns;
} CSVRow;

CSVRow *csv_read_row(FILE *file) {
    char row[MAX_LENGTH];
    if (fgets(row, MAX_LENGTH, file) == NULL) {
        return NULL;
    }

    CSVRow *csv_row = malloc(sizeof(CSVRow));
    csv_row->num_columns = 0;

    int row_len = strlen(row);
    char *token;
    char *rest = row;

    while ((token = strtok_r(rest, ",", &rest))) {
        if (csv_row->num_columns == 0) {
            csv_row->data = malloc(sizeof(char *));
        } else {
            csv_row->data = realloc(csv_row->data, sizeof(char *) * (csv_row->num_columns + 1));
        }

        int token_len = strlen(token);
        csv_row->data[csv_row->num_columns] = malloc(sizeof(char) * (token_len + 1));
        strcpy(csv_row->data[csv_row->num_columns], token);

        csv_row->num_columns++;
    }

    return csv_row;
}

void csv_free_row(CSVRow *csv_row) {
    for (int i = 0; i < csv_row->num_columns; i++) {
        free(csv_row->data[i]);
    }

    free(csv_row->data);
    free(csv_row);
}

int main() {
    FILE *file = fopen("test.csv", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSVRow *csv_row;

    while ((csv_row = csv_read_row(file)) != NULL) {
        printf("Row with %d columns:\n", csv_row->num_columns);

        for (int i = 0; i < csv_row->num_columns; i++) {
            printf("\t%s\n", csv_row->data[i]);
        }

        csv_free_row(csv_row);
    }

    fclose(file);

    return 0;
}