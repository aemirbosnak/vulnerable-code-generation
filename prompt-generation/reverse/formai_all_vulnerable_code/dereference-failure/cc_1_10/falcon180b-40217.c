//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100

typedef struct {
    int num_fields;
    char **fields;
} Row;

Row *read_csv(FILE *fp) {
    Row *row = NULL;
    char line[MAX_LINE_LEN];
    char *token = NULL;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        num_fields = 0;
        row = realloc(row, sizeof(Row) + sizeof(char *) * num_fields);
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

void print_row(Row *row) {
    int i;

    for (i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void free_row(Row *row) {
    int i;

    for (i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp;
    Row *row;

    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    row = read_csv(fp);
    if (row == NULL) {
        printf("Error reading file.\n");
        return 1;
    }

    print_row(row);

    free_row(row);
    fclose(fp);

    return 0;
}