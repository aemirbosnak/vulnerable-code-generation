//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 10

typedef struct {
    char *data[MAX_COLUMNS];
    int num_columns;
} csv_row;

csv_row *csv_read_row(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    int i, len;
    csv_row *row = malloc(sizeof(csv_row));
    row->num_columns = 0;

    if (fgets(line, sizeof(line), fp) == NULL) {
        return NULL;
    }

    len = strlen(line);
    if (line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }

    char *token = strtok(line, ",");
    while (token != NULL) {
        row->data[row->num_columns] = strdup(token);
        row->num_columns++;
        token = strtok(NULL, ",");
    }

    return row;
}

void csv_free_row(csv_row *row) {
    for (int i = 0; i < row->num_columns; i++) {
        free(row->data[i]);
    }
    free(row);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    csv_row *row;
    while ((row = csv_read_row(fp)) != NULL) {
        for (int i = 0; i < row->num_columns; i++) {
            printf("%s", row->data[i]);
            if (i < row->num_columns - 1) {
                printf(",");
            }
        }
        printf("\n");
        csv_free_row(row);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}