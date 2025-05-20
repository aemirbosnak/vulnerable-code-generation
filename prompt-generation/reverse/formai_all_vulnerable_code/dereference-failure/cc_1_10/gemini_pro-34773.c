//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSVReader;

CSVReader *csv_new(char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    if (!reader) {
        return NULL;
    }

    FILE *f = fopen(filename, "r");
    if (!f) {
        free(reader);
        return NULL;
    }

    int data_size = 100;
    reader->data = malloc(sizeof(char *) * data_size);
    if (!reader->data) {
        fclose(f);
        free(reader);
        return NULL;
    }

    char *line = NULL;
    size_t line_len = 0;
    int row_count = 0;

    while (getline(&line, &line_len, f) >= 0) {
        row_count++;
        if (row_count > data_size) {
            data_size *= 2;
            reader->data = realloc(reader->data, sizeof(char *) * data_size);
            if (!reader->data) {
                fclose(f);
                free(line);
                free(reader);
                return NULL;
            }
        }

        reader->data[row_count - 1] = malloc(strlen(line) + 1);
        if (!reader->data[row_count - 1]) {
            fclose(f);
            free(line);
            free(reader);
            return NULL;
        }

        strcpy(reader->data[row_count - 1], line);
    }

    free(line);
    fclose(f);

    reader->num_rows = row_count;
    reader->num_cols = 0;

    if (reader->num_rows > 0) {
        char *first_row = reader->data[0];
        char *token = strtok(first_row, ",");
        while (token) {
            reader->num_cols++;
            token = strtok(NULL, ",");
        }
    }

    return reader;
}

void csv_free(CSVReader *reader) {
    if (reader) {
        for (int i = 0; i < reader->num_rows; i++) {
            free(reader->data[i]);
        }
        free(reader->data);
        free(reader);
    }
}

char *csv_get(CSVReader *reader, int row, int col) {
    if (reader && row >= 0 && row < reader->num_rows && col >= 0 && col < reader->num_cols) {
        return reader->data[row][col];
    }
    return NULL;
}

int main() {
    CSVReader *reader = csv_new("data.csv");
    if (reader) {
        for (int i = 0; i < reader->num_rows; i++) {
            for (int j = 0; j < reader->num_cols; j++) {
                printf("%s ", csv_get(reader, i, j));
            }
            printf("\n");
        }
        csv_free(reader);
    }
    return 0;
}