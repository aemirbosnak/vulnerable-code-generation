//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t buffer_used;
    FILE *fp;
} csv_reader_t;

csv_reader_t *csv_reader_new(FILE *fp) {
    csv_reader_t *reader = malloc(sizeof(csv_reader_t));
    if (reader == NULL) {
        return NULL;
    }

    reader->buffer = malloc(MAX_BUFFER_SIZE);
    if (reader->buffer == NULL) {
        free(reader);
        return NULL;
    }

    reader->buffer_size = MAX_BUFFER_SIZE;
    reader->buffer_used = 0;
    reader->fp = fp;

    return reader;
}

void csv_reader_free(csv_reader_t *reader) {
    if (reader != NULL) {
        free(reader->buffer);
        free(reader);
    }
}

int csv_reader_next_line(csv_reader_t *reader, char **columns, size_t *num_columns) {
    int ch;
    size_t i = 0;
    size_t j = 0;

    while ((ch = fgetc(reader->fp)) != EOF) {
        if (ch == ',' || ch == '\n') {
            if (i >= MAX_COLUMNS) {
                return -1;
            }

            columns[i][j] = '\0';
            i++;
            j = 0;
        } else {
            if (j >= MAX_BUFFER_SIZE) {
                return -1;
            }

            columns[i][j] = ch;
            j++;
        }
    }

    if (i >= MAX_COLUMNS) {
        return -1;
    }

    columns[i][j] = '\0';
    *num_columns = i + 1;

    return 0;
}

int main(int argc, char **argv) {
    FILE *fp;
    csv_reader_t *reader;
    char *columns[MAX_COLUMNS];
    size_t num_columns;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    reader = csv_reader_new(fp);
    if (reader == NULL) {
        fprintf(stderr, "csv_reader_new failed\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < MAX_COLUMNS; i++) {
        columns[i] = malloc(MAX_BUFFER_SIZE);
        if (columns[i] == NULL) {
            fprintf(stderr, "malloc failed\n");
            return EXIT_FAILURE;
        }
    }

    while (csv_reader_next_line(reader, columns, &num_columns) == 0) {
        for (i = 0; i < num_columns; i++) {
            printf("%s ", columns[i]);
        }

        printf("\n");
    }

    csv_reader_free(reader);
    fclose(fp);

    return EXIT_SUCCESS;
}