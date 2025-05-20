//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100
#define DELIMITER ','

typedef struct {
    char **fields;
    int num_fields;
} csv_row_t;

csv_row_t *csv_read_row(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    csv_row_t *row = malloc(sizeof(csv_row_t));
    row->num_fields = 0;
    row->fields = NULL;

    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        printf("Error reading line from file.\n");
        exit(1);
    }

    char *token = strtok(line, DELIMITER);
    while (token!= NULL) {
        row->num_fields++;
        row->fields = realloc(row->fields, sizeof(char *) * row->num_fields);
        row->fields[row->num_fields - 1] = strdup(token);
        token = strtok(NULL, DELIMITER);
    }

    return row;
}

void csv_print_row(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s%c", row->fields[i], i == row->num_fields - 1? '\n' : ',');
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    csv_row_t *row;
    while ((row = csv_read_row(fp))!= NULL) {
        csv_print_row(row);
        free(row->fields);
        free(row);
    }

    fclose(fp);
    return 0;
}