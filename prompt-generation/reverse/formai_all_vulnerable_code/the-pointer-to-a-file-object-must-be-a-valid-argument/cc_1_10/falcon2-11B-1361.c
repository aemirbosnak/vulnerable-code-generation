//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct csv_row {
    char* name;
    char* value;
} csv_row;

typedef struct csv_reader {
    int fd;
    int line_number;
    int error;
    csv_row* rows;
    size_t rows_size;
} csv_reader;

void csv_reader_init(csv_reader* reader, char* filename) {
    reader->fd = open(filename, O_RDONLY);
    if (reader->fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        reader->error = 1;
        return;
    }
    reader->line_number = 0;
    reader->error = 0;
    reader->rows = malloc(sizeof(csv_row));
    reader->rows_size = 0;
}

void csv_reader_destroy(csv_reader* reader) {
    if (reader->rows!= NULL) {
        free(reader->rows);
    }
    close(reader->fd);
}

int csv_reader_read_row(csv_reader* reader, csv_row* row) {
    int columns = 0;
    char* token = NULL;
    char* line = NULL;
    size_t line_size = 0;
    while ((line = fgets(line, sizeof(line), reader->fd))!= NULL) {
        columns = 0;
        token = strtok(line, ",");
        while (token!= NULL) {
            row[columns].name = token;
            row[columns].value = malloc(strlen(token) + 1);
            strcpy(row[columns].value, token);
            columns++;
            token = strtok(NULL, ",");
        }
        reader->rows_size += columns;
        reader->line_number++;
    }
    return reader->error? -1 : 0;
}

int main() {
    csv_reader reader;
    csv_row row;
    char filename[] = "sample.csv";

    csv_reader_init(&reader, filename);
    csv_reader_read_row(&reader, &row);
    printf("Name: %s, Value: %s\n", row.name, row.value);

    csv_reader_destroy(&reader);

    return 0;
}