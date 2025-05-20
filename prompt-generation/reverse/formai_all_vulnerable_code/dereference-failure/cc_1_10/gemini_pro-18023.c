//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    size_t size;
} csv_reader_t;

csv_reader_t *csv_reader_new() {
    csv_reader_t *reader = malloc(sizeof(csv_reader_t));
    reader->data = NULL;
    reader->size = 0;
    return reader;
}

void csv_reader_free(csv_reader_t *reader) {
    for (size_t i = 0; i < reader->size; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int csv_reader_load(csv_reader_t *reader, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *data = strdup(line);
        if (data == NULL) {
            fclose(file);
            return -1;
        }

        char *token = strtok(data, ",");
        while (token != NULL) {
            reader->data = realloc(reader->data, (reader->size + 1) * sizeof(char *));
            reader->data[reader->size++] = strdup(token);
            token = strtok(NULL, ",");
        }

        free(data);
    }

    fclose(file);
    return 0;
}

int main() {
    csv_reader_t *reader = csv_reader_new();
    if (csv_reader_load(reader, "data.csv") == -1) {
        fprintf(stderr, "Error loading CSV file\n");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < reader->size; i++) {
        printf("%s\n", reader->data[i]);
    }

    csv_reader_free(reader);
    return EXIT_SUCCESS;
}