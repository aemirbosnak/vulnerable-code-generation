//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_NUM_FIELDS 100

typedef struct {
    char *data;
    int size;
} String;

typedef struct {
    int num_fields;
    char delimiter;
    String **fields;
} CSVRow;

CSVRow *read_csv_row(FILE *file) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->fields = malloc(MAX_NUM_FIELDS * sizeof(String*));
    memset(row->fields, 0, MAX_NUM_FIELDS * sizeof(String*));

    char line[MAX_LINE_SIZE];
    fgets(line, MAX_LINE_SIZE, file);
    char *token = strtok(line, ",");
    while (token!= NULL) {
        String *field = malloc(sizeof(String));
        field->data = malloc(strlen(token) + 1);
        strcpy(field->data, token);
        field->size = strlen(token);
        row->fields[row->num_fields] = field;
        row->num_fields++;
        token = strtok(NULL, ",");
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s", row->fields[i]->data);
        if (i < row->num_fields - 1) {
            printf(",");
        }
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]->data);
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSVRow *row = read_csv_row(file);
    while (row!= NULL) {
        print_csv_row(row);
        free_csv_row(row);
        row = read_csv_row(file);
    }

    fclose(file);
    return 0;
}