//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_columns;
    int num_rows;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->num_columns = 0;
    csv->num_rows = 0;
    csv->data = (char **) malloc(MAX_COLUMNS * sizeof(char *));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            csv->num_columns++;
            csv->data = (char **) realloc(csv->data, csv->num_columns * sizeof(char *));
            csv->data[csv->num_columns - 1] = strdup(token);
            token = strtok(NULL, DELIMITER);
        }
        csv->num_rows++;
    }

    fclose(file);

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_columns; i++) {
        printf("%s", csv->data[i]);
        if (i < csv->num_columns - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_columns; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");

    if (csv == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("File opened successfully!\n");
    csv_print(csv);
    csv_close(csv);

    return 0;
}