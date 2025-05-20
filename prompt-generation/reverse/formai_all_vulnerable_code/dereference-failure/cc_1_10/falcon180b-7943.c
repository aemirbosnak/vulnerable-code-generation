//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *field[100];
    int num_fields;
} csv_row_t;

csv_row_t *csv_read_row(FILE *fp) {
    csv_row_t *row = (csv_row_t *)malloc(sizeof(csv_row_t));
    char line[MAX_LINE_SIZE];
    int num_fields = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");

        while (token!= NULL) {
            row->field[num_fields] = strdup(token);
            num_fields++;
            token = strtok(NULL, ",");
        }

        break;
    }

    row->num_fields = num_fields;
    return row;
}

void csv_free_row(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->field[i]);
    }

    free(row);
}

int main() {
    FILE *fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    csv_row_t *row = csv_read_row(fp);

    for (int i = 0; i < row->num_fields; i++) {
        printf("%s\n", row->field[i]);
    }

    csv_free_row(row);
    fclose(fp);

    return 0;
}