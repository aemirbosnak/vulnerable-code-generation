//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            csv->data = realloc(csv->data, sizeof(char *) * (++csv->cols));
            csv->data[cols] = strdup(token);
            token = strtok(NULL, ",");
            ++cols;
        }
        ++csv->rows;
    }

    fclose(file);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; ++i) {
        for (int j = 0; j < csv->cols; ++j) {
            printf("%s ", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; ++i) {
        for (int j = 0; j < csv->cols; ++j) {
            free(csv->data[i * csv->cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    CSV *csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);

    return 0;
}