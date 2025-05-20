//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int len;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int num_rows;
} CSVReader;

CSVReader *csv_reader_create(FILE *file) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    if (reader == NULL) {
        return NULL;
    }

    reader->rows = NULL;
    reader->num_rows = 0;

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, file)) != -1) {
        CSVRow row;
        row.len = nread;
        row.data = malloc(row.len + 1);
        if (row.data == NULL) {
            free(reader);
            free(line);
            return NULL;
        }

        memcpy(row.data, line, row.len);
        row.data[row.len] = '\0';

        reader->rows = realloc(reader->rows, (reader->num_rows + 1) * sizeof(CSVRow));
        if (reader->rows == NULL) {
            free(reader);
            free(line);
            free(row.data);
            return NULL;
        }

        reader->rows[reader->num_rows] = row;
        reader->num_rows++;
    }

    free(line);

    return reader;
}

void csv_reader_free(CSVReader *reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        free(reader->rows[i].data);
    }

    free(reader->rows);
    free(reader);
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    CSVReader *reader = csv_reader_create(file);
    if (reader == NULL) {
        perror("Could not create CSV reader");
        fclose(file);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < reader->num_rows; i++) {
        CSVRow row = reader->rows[i];
        printf("%s", row.data);
    }

    csv_reader_free(reader);
    fclose(file);

    return EXIT_SUCCESS;
}