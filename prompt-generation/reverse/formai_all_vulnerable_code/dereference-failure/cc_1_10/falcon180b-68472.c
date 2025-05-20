//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_FIELD_SIZE 256

typedef struct {
    char *field[MAX_FIELDS];
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp))!= -1) {
        if (read == 0) {
            row->field[row->num_fields++] = strdup("");
        } else {
            char *token = strtok(line, ",");
            while (token!= NULL) {
                row->field[row->num_fields++] = strdup(token);
                token = strtok(NULL, ",");
            }
        }
    }
    if (line!= NULL) {
        free(line);
    }
    return row;
}

void print_csv_row(CSVRow *row) {
    printf("[");
    for (int i = 0; i < row->num_fields; i++) {
        printf("\"%s\", ", row->field[i]);
    }
    printf("]\n");
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    CSVRow *row = read_csv_file(fp);
    while (row!= NULL) {
        print_csv_row(row);
        row = read_csv_file(fp);
    }
    fclose(fp);
    return 0;
}