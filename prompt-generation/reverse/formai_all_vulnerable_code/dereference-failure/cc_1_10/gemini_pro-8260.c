//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }

    csv_t *csv = malloc(sizeof(csv_t));
    if (!csv) {
        fclose(fp);
        return NULL;
    }

    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = NULL;

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        csv->num_rows++;

        char *p = line;
        while (*p != '\n') {
            if (*p == ',') {
                csv->num_cols++;
            }
            p++;
        }
    }

    csv->data = malloc(sizeof(char *) * csv->num_rows);
    if (!csv->data) {
        fclose(fp);
        free(line);
        free(csv);
        return NULL;
    }

    rewind(fp);
    int row = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        csv->data[row] = malloc(sizeof(char) * strlen(line) + 1);
        if (!csv->data[row]) {
            fclose(fp);
            free(line);
            for (int i = 0; i < row; i++) {
                free(csv->data[i]);
            }
            free(csv->data);
            free(csv);
            return NULL;
        }

        strcpy(csv->data[row], line);
        row++;
    }

    fclose(fp);
    free(line);
    return csv;
}

void csv_free(csv_t *csv) {
    if (!csv) {
        return;
    }

    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    csv_t *csv = csv_read(argv[1]);
    if (!csv) {
        fprintf(stderr, "Error reading CSV file\n");
        return 1;
    }

    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }

    csv_free(csv);
    return 0;
}