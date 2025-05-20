//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_read(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_columns = 0;
    csv->data = malloc(MAX_COLUMNS * sizeof(char *));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (csv->num_rows == MAX_COLUMNS) {
            printf("Error: CSV has more than %d columns.\n", MAX_COLUMNS);
            exit(1);
        }
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (csv->num_columns == MAX_COLUMNS) {
                printf("Error: CSV has more than %d columns.\n", MAX_COLUMNS);
                exit(1);
            }
            csv->data[csv->num_columns] = token;
            csv->num_columns++;
            token = strtok(NULL, DELIMITER);
        }
        csv->num_rows++;
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[j]);
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
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    CSV *csv = csv_read(file);
    csv_print(csv);
    csv_free(csv);

    fclose(file);
    return 0;
}