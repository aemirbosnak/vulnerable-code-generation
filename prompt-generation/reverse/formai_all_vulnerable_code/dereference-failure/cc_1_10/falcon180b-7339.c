//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 1024
#define DELIM ","

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv(FILE *file);
void print_csv_row(CSVRow *row);
void free_csv_row(CSVRow *row);

int main() {
    FILE *file = fopen("data.csv", "r");
    CSVRow *row;

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((row = read_csv(file))!= NULL) {
        print_csv_row(row);
        free_csv_row(row);
    }

    fclose(file);
    return 0;
}

CSVRow *read_csv(FILE *file) {
    char line[MAX_LINE_SIZE];
    char *token;
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->fields = NULL;

    if (fgets(line, MAX_LINE_SIZE, file) == NULL) {
        return NULL;
    }

    token = strtok(line, DELIM);
    while (token!= NULL) {
        if (row->num_fields >= MAX_FIELD_SIZE) {
            printf("Error: too many fields in row\n");
            exit(1);
        }
        row->fields[row->num_fields] = strdup(token);
        row->num_fields++;
        token = strtok(NULL, DELIM);
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    int i;
    for (i = 0; i < row->num_fields; i++) {
        printf("%s%s", row->fields[i], i < row->num_fields - 1? DELIM : "\n");
    }
}

void free_csv_row(CSVRow *row) {
    int i;
    for (i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}