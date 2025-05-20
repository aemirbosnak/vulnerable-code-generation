//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_Reader {
    char **data;
    int rows;
    int cols;
} CSV_Reader;

CSV_Reader *csv_reader_init(int rows, int cols) {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->data = malloc(sizeof(char *) * rows);
    for (int r = 0; r < rows; r++) {
        reader->data[r] = malloc(sizeof(char) * cols);
    }
    reader->rows = rows;
    reader->cols = cols;
    return reader;
}

void csv_reader_read(CSV_Reader *reader, char *csv_data) {
    char **lines = NULL;
    int num_lines = 0;
    char *line = strtok(csv_data, "\n");
    while (line) {
        lines = realloc(lines, (num_lines + 1) * sizeof(char *));
        lines[num_lines++] = line;
        line = strtok(NULL, "\n");
    }

    reader->rows = num_lines;
    reader->data = realloc(reader->data, sizeof(char *) * num_lines);
    for (int r = 0; r < num_lines; r++) {
        reader->data[r] = realloc(reader->data[r], sizeof(char) * reader->cols);
    }

    int i = 0;
    for (char **l = lines; *l; l++) {
        char **c = reader->data;
        for (char **r = *l; *r; r++) {
            strcpy(c[i++], *r);
        }
    }

    free(lines);
}

int main() {
    CSV_Reader *reader = csv_reader_init(MAX_ROWS, MAX_COLS);
    char csv_data[] = "a,b,c\nd,e,f\ng,h,i";
    csv_reader_read(reader, csv_data);

    for (int r = 0; r < reader->rows; r++) {
        for (int c = 0; c < reader->cols; c++) {
            printf("%s ", reader->data[r][c]);
        }
        printf("\n");
    }

    free(reader->data);
    free(reader);

    return 0;
}