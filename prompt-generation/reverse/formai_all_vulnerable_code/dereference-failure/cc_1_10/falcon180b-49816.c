//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

typedef struct {
    char **fields;
    int num_fields;
    int max_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *file) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->fields = malloc(MAX_FIELDS * sizeof(char *));
    row->num_fields = 0;
    row->max_fields = MAX_FIELDS;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL && i < row->max_fields) {
            row->fields[i] = strdup(token);
            i++;
            token = strtok(NULL, ",");
        }
        row->num_fields = i;
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    CSVRow *row = read_csv_file(file);

    print_csv_row(row);

    free(row->fields);
    free(row);

    fclose(file);
    return 0;
}