//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000
#define MAX_CELL_DATA_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int columns;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: failed to open file '%s'\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->columns = 0;

    char line[MAX_CELL_DATA_SIZE];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",");
        int count = 0;
        while (token!= NULL) {
            count++;
            if (csv->columns == 0) {
                csv->columns = count;
            } else if (count!= csv->columns) {
                printf("Error: invalid number of columns in row %d\n", csv->rows + 1);
                exit(1);
            }
            char *cell_data = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(cell_data, token);
            csv->data = realloc(csv->data, sizeof(char *) * (csv->rows + 1));
            csv->data[csv->rows] = cell_data;
            token = strtok(NULL, ",");
        }
        csv->rows++;
        if (csv->rows >= MAX_ROWS) {
            printf("Error: exceeded maximum number of rows (%d)\n", MAX_ROWS);
            exit(1);
        }
    }

    fclose(file);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            printf("%s\t", csv->data[i * csv->columns + j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i * csv->columns]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}