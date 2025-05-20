//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 1000
#define MAX_FIELD_LENGTH 1000

typedef struct {
    char *field[MAX_FIELDS];
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    CSVRow *row = malloc(sizeof(CSVRow));
    if (row == NULL) {
        printf("Error: Failed to allocate memory for CSV row.\n");
        exit(1);
    }

    char line[MAX_FIELD_LENGTH];
    char *token;
    int num_fields = 0;

    while (fgets(line, MAX_FIELD_LENGTH, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            row->field[num_fields] = malloc(strlen(token) + 1);
            strcpy(row->field[num_fields], token);
            num_fields++;
            token = strtok(NULL, ",");
        }
    }

    row->num_fields = num_fields;
    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->field[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp;
    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Failed to open CSV file.\n");
        exit(1);
    }

    CSVRow *row;
    while ((row = read_csv_file(fp))!= NULL) {
        print_csv_row(row);
        for (int i = 0; i < row->num_fields; i++) {
            free(row->field[i]);
        }
        free(row);
    }

    fclose(fp);
    return 0;
}