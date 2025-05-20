//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    csv_t *csv = malloc(sizeof(csv_t));
    if (csv == NULL) {
        fclose(fp);
        return NULL;
    }

    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        // Remove trailing newline
        char *newline = strchr(line, '\n');
        if (newline) *newline = '\0';

        // Count the number of columns
        int cols = 1;
        for (char *p = line; *p; p++) {
            if (*p == ',') cols++;
        }

        // Allocate memory for the row
        csv->data = realloc(csv->data, (csv->rows + 1) * sizeof(char *));
        csv->data[csv->rows] = malloc((cols + 1) * sizeof(char));

        // Parse the row
        char *p = line;
        char *start = p;
        int col = 0;
        while (*p) {
            if (*p == ',') {
                csv->data[csv->rows][col++] = strndup(start, p - start);
                start = p + 1;
            }
            p++;
        }
        csv->data[csv->rows][col++] = strndup(start, p - start);
        csv->cols = cols;
        csv->rows++;
    }

    fclose(fp);

    return csv;
}

void csv_free(csv_t *csv) {
    if (csv == NULL) return;
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    csv_t *csv = csv_read(argv[1]);
    if (csv == NULL) {
        printf("Error reading CSV file\n");
        return 1;
    }

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_free(csv);

    return 0;
}