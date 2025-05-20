//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 128

typedef struct csv_row {
    char **fields;
    int field_count;
} csv_row_t;

csv_row_t *read_csv_row(FILE *fp) {
    char line[MAX_LINE_SIZE];
    char *fields[MAX_FIELD_SIZE];
    int i = 0;

    if (!fgets(line, MAX_LINE_SIZE, fp)) {
        return NULL;
    }

    csv_row_t *row = (csv_row_t *)malloc(sizeof(csv_row_t));

    char *token = strtok(line, ",");
    while (token != NULL && i < MAX_FIELD_SIZE) {
        fields[i] = strdup(token);
        token = strtok(NULL, ",");
        i++;
    }

    row->field_count = i;
    row->fields = (char **)malloc(sizeof(char *) * i);
    for (int j = 0; j < i; j++) {
        row->fields[j] = fields[j];
    }

    return row;
}

void free_csv_row(csv_row_t *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    csv_row_t *row;
    while ((row = read_csv_row(fp)) != NULL) {
        printf("Fields: ");
        for (int i = 0; i < row->field_count; i++) {
            printf("%s ", row->fields[i]);
        }
        printf("\n");
        free_csv_row(row);
    }

    fclose(fp);
    return 0;
}