//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    size_t nrows;
    size_t ncols;
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

    char *line = NULL;
    size_t len = 0;
    size_t nrows = 0;
    size_t ncols = 0;

    while (getline(&line, &len, fp) != -1) {
        nrows++;

        char *p = line;
        while (*p != '\0') {
            if (*p == ',') {
                ncols++;
            }
            p++;
        }
    }

    csv->data = malloc(nrows * sizeof(char *));
    if (csv->data == NULL) {
        free(csv);
        fclose(fp);
        return NULL;
    }

    csv->nrows = nrows;
    csv->ncols = ncols + 1;

    rewind(fp);

    for (size_t i = 0; i < nrows; i++) {
        getline(&line, &len, fp);

        char *p = line;
        char **data = malloc((ncols + 1) * sizeof(char *));
        if (data == NULL) {
            for (size_t j = 0; j < i; j++) {
                free(csv->data[j]);
            }
            free(csv->data);
            free(csv);
            fclose(fp);
            return NULL;
        }

        size_t j = 0;
        while (*p != '\0') {
            if (*p == ',') {
                *p = '\0';
                data[j++] = strdup(line);
                line = p + 1;
            }
            p++;
        }
        data[j++] = strdup(line);
        csv->data[i] = data;
    }

    fclose(fp);
    return csv;
}

void csv_free(csv_t *csv) {
    if (csv == NULL) {
        return;
    }

    for (size_t i = 0; i < csv->nrows; i++) {
        for (size_t j = 0; j < csv->ncols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    csv_t *csv = csv_read(argv[1]);
    if (csv == NULL) {
        fprintf(stderr, "Error reading CSV file\n");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < csv->nrows; i++) {
        for (size_t j = 0; j < csv->ncols; j++) {
            printf("%s", csv->data[i][j]);
            if (j < csv->ncols - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    csv_free(csv);
    return EXIT_SUCCESS;
}