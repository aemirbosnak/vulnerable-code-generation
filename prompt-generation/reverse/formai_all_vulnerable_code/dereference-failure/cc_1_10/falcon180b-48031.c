//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_read_file(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_columns = 0;
    csv->data = malloc(sizeof(char *) * MAX_COLUMNS);
    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int i = 0;
        while (token!= NULL) {
            if (i >= MAX_COLUMNS) {
                printf("Error: Too many columns in line %d\n", csv->num_rows + 1);
                exit(1);
            }
            csv->data[i] = token;
            i++;
            token = strtok(NULL, DELIMITER);
        }
        csv->num_columns = i;
        csv->num_rows++;
    }

    return csv;
}

void csv_print_data(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    CSV *csv = csv_read_file(fp);
    csv_print_data(csv);

    fclose(fp);
    return 0;
}