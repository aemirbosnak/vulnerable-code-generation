//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100

typedef struct {
    char **data;
    int num_fields;
} csv_row_t;

csv_row_t *csv_read_file(FILE *fp) {
    csv_row_t *row = malloc(sizeof(csv_row_t));
    row->data = malloc(MAX_FIELDS * sizeof(char *));
    row->num_fields = 0;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            row->data[row->num_fields] = strdup(token);
            row->num_fields++;
            token = strtok(NULL, ",");
        }
    }

    return row;
}

void csv_print_row(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->data[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    csv_row_t *row = csv_read_file(fp);
    csv_print_row(row);

    for (int i = 0; i < row->num_fields; i++) {
        free(row->data[i]);
    }
    free(row->data);
    free(row);

    fclose(fp);
    return 0;
}