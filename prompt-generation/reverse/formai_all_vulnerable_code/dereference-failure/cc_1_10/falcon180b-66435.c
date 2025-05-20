//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

typedef struct {
    char *header;
    int num_fields;
    char **fields;
} csv_row_t;

csv_row_t *read_csv(FILE *fp) {
    csv_row_t *row = NULL;
    int num_fields = 0;
    char line[MAX_LINE_LENGTH];
    char *header = NULL;
    char **fields = NULL;
    char *token;

    // Read header line
    fgets(line, MAX_LINE_LENGTH, fp);
    header = strdup(line);
    token = strtok(header, ",");
    while (token!= NULL) {
        num_fields++;
        token = strtok(NULL, ",");
    }
    fields = malloc(num_fields * sizeof(char *));
    for (int i = 0; i < num_fields; i++) {
        fields[i] = NULL;
    }

    // Read data lines
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, ",");
        for (int i = 0; i < num_fields; i++) {
            fields[i] = strdup(token);
            token = strtok(NULL, ",");
        }
        row = malloc(sizeof(csv_row_t));
        row->header = header;
        row->num_fields = num_fields;
        row->fields = fields;
        break;
    }

    return row;
}

void print_csv_row(csv_row_t *row) {
    printf("%s\n", row->header);
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s\n", row->fields[i]);
    }
}

void free_csv_row(csv_row_t *row) {
    free(row->header);
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp;
    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    csv_row_t *row = read_csv(fp);
    if (row == NULL) {
        printf("Error reading CSV file.\n");
        exit(1);
    }

    print_csv_row(row);

    free_csv_row(row);
    fclose(fp);

    return 0;
}