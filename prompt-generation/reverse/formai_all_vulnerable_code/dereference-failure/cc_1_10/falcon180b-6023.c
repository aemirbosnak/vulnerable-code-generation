//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 1024

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv_row(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char delimiter = ',';
    char quote = '"';
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->fields = NULL;

    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        return NULL;
    }

    char *ptr = line;
    while (*ptr!= '\n') {
        if (*ptr == delimiter) {
            *ptr = '\0';
            char *field = malloc(MAX_FIELD_LENGTH);
            strcpy(field, ptr + 1);
            row->fields = realloc(row->fields, (row->num_fields + 1) * sizeof(char *));
            row->fields[row->num_fields++] = field;
            ptr += strlen(ptr + 1) + 1;
        } else if (*ptr == quote) {
            char *start_ptr = ptr + 1;
            while (*ptr!= quote && *ptr!= delimiter && *ptr!= '\n') {
                ptr++;
            }
            if (*ptr == delimiter || *ptr == '\n') {
                *ptr = '\0';
            }
            char *field = malloc(ptr - start_ptr + 1);
            strncpy(field, start_ptr, ptr - start_ptr);
            row->fields = realloc(row->fields, (row->num_fields + 1) * sizeof(char *));
            row->fields[row->num_fields++] = field;
            ptr += strlen(ptr) + 1;
        } else {
            ptr++;
        }
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
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

    CSVRow *row = read_csv_row(fp);
    while (row!= NULL) {
        print_csv_row(row);
        free_csv_row(row);
        row = read_csv_row(fp);
    }

    fclose(fp);
    return 0;
}