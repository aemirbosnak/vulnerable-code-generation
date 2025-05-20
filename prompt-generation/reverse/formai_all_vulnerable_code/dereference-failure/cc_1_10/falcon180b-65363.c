//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_CSV_COLUMNS 100
#define MAX_CSV_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_read(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;

    char line[MAX_LINE_SIZE];
    char *token;
    int num_columns = 0;
    int row = 0;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        row++;
        if (row == 1) { // header row
            token = strtok(line, ",");
            while (token!= NULL) {
                num_columns++;
                csv->data = realloc(csv->data, sizeof(char *) * num_columns);
                csv->data[num_columns - 1] = strdup(token);
                token = strtok(NULL, ",");
            }
        } else { // data rows
            token = strtok(line, ",");
            int col = 0;
            while (token!= NULL && col < num_columns) {
                csv->data[col] = strdup(token);
                token = strtok(NULL, ",");
                col++;
            }
        }
    }

    csv->num_rows = row;
    csv->num_columns = num_columns;

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s\t", csv->data[j * csv->num_rows + i]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->num_columns; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSV *csv = csv_read(file);
    if (csv == NULL) {
        printf("Error reading file.\n");
        fclose(file);
        return 1;
    }

    csv_print(csv);

    csv_free(csv);
    fclose(file);

    return 0;
}