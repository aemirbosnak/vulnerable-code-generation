//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} csv_row_t;

csv_row_t *csv_read_file(FILE *fp) {
    csv_row_t *row = NULL;
    char line[MAX_LINE_LEN];
    char *token;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        num_fields = 0;
        row = (csv_row_t *) realloc(row, sizeof(csv_row_t) + num_fields * sizeof(char *));
        if (row == NULL) {
            perror("realloc");
            exit(1);
        }
        row->num_fields = num_fields;

        token = strtok(line, ",");
        while (token!= NULL) {
            row->fields[num_fields] = strdup(token);
            num_fields++;
            token = strtok(NULL, ",");
        }
    }

    return row;
}

void csv_print_row(csv_row_t *row) {
    int i;

    for (i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void csv_free_row(csv_row_t *row) {
    int i;

    for (i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main(int argc, char **argv) {
    FILE *fp;
    csv_row_t *row;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    row = csv_read_file(fp);
    if (row == NULL) {
        return 1;
    }

    csv_print_row(row);

    csv_free_row(row);
    fclose(fp);

    return 0;
}