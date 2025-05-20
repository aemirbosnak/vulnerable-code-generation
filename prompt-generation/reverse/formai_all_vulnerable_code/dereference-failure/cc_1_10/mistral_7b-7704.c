//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 128
#define DELIM ",\\r\\n"

typedef struct {
    int num_fields;
    char **fields;
} csv_row_t;

void csv_parse_line(char *line, csv_row_t *row) {
    int i = 0;
    char *token = strtok(line, DELIM);
    row->num_fields = 0;

    while (token != NULL) {
        if (row->num_fields >= MAX_FIELDS) {
            fprintf(stderr, "Error: too many fields in line\n");
            exit(EXIT_FAILURE);
        }

        row->fields[row->num_fields] = malloc(strlen(token) + 1);
        strcpy(row->fields[row->num_fields], token);
        row->num_fields++;

        token = strtok(NULL, DELIM);
    }
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    csv_row_t row;

    fp = fopen("example.csv", "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: unable to open file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        row.num_fields = 0;
        csv_parse_line(line, &row);

        for (int i = 0; i < row.num_fields; i++) {
            printf("%s%s", row.fields[i],
                   (i + 1 < row.num_fields) ? "," : "\n");
            free(row.fields[i]);
        }

        free(row.fields);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}