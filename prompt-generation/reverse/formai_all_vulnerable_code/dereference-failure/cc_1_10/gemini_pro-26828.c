//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **fields;
    int num_fields;
    int num_rows;
} csv_reader;

csv_reader *csv_reader_create(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    csv_reader *reader = malloc(sizeof(csv_reader));
    if (reader == NULL) {
        fclose(fp);
        return NULL;
    }

    reader->fields = NULL;
    reader->num_fields = 0;
    reader->num_rows = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *field = strtok(line, ",");
        while (field) {
            reader->fields = realloc(reader->fields, (reader->num_fields + 1) * sizeof(char *));
            reader->fields[reader->num_fields++] = strdup(field);
            field = strtok(NULL, ",");
        }
        reader->num_rows++;
    }

    fclose(fp);

    return reader;
}

void csv_reader_destroy(csv_reader *reader) {
    for (int i = 0; i < reader->num_fields; i++) {
        free(reader->fields[i]);
    }
    free(reader->fields);
    free(reader);
}

char *csv_reader_get_field(csv_reader *reader, int row, int col) {
    if (row < 0 || row >= reader->num_rows) {
        return NULL;
    }
    if (col < 0 || col >= reader->num_fields) {
        return NULL;
    }
    return reader->fields[row * reader->num_fields + col];
}

int main() {
    csv_reader *reader = csv_reader_create("data.csv");
    if (reader == NULL) {
        return 1;
    }

    for (int i = 0; i < reader->num_rows; i++) {
        for (int j = 0; j < reader->num_fields; j++) {
            printf("%s ", csv_reader_get_field(reader, i, j));
        }
        printf("\n");
    }

    csv_reader_destroy(reader);

    return 0;
}