//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 256

typedef struct {
    char **fields;
    int num_fields;
} csv_row_t;

csv_row_t *csv_read_line(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char *delimiter = ",";
    csv_row_t *row = malloc(sizeof(csv_row_t));
    row->num_fields = 0;
    row->fields = malloc(MAX_FIELDS * sizeof(char*));

    fgets(line, MAX_LINE_LENGTH, fp);
    char *token = strtok(line, delimiter);
    while (token!= NULL) {
        row->fields[row->num_fields] = strdup(token);
        row->num_fields++;
        token = strtok(NULL, delimiter);
    }
    row->fields[row->num_fields] = NULL;

    return row;
}

void csv_print_row(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void csv_free_row(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    csv_row_t *row;
    while ((row = csv_read_line(fp))!= NULL) {
        csv_print_row(row);
        csv_free_row(row);
    }

    fclose(fp);
    return 0;
}