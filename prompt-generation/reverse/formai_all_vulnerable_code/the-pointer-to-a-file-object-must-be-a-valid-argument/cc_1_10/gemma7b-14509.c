//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSVReader {
    FILE *fp;
    char **buffer;
    int buffer_size;
    int current_row;
    int current_column;
} CSVReader;

CSVReader *csv_reader_init(const char *filename) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->buffer = NULL;
    reader->buffer_size = MAX_BUFFER_SIZE;
    reader->current_row = 0;
    reader->current_column = 0;
    return reader;
}

void csv_reader_free(CSVReader *reader) {
    fclose(reader->fp);
    free(reader->buffer);
    free(reader);
}

char **csv_reader_get_data(CSVReader *reader) {
    char **data = NULL;
    int num_columns = csv_reader_get_num_columns(reader);
    data = malloc(sizeof(char *) * reader->current_row);
    for (int i = 0; i < reader->current_row; i++) {
        data[i] = malloc(sizeof(char) * num_columns);
    }
    return data;
}

int csv_reader_get_num_columns(CSVReader *reader) {
    char line[MAX_BUFFER_SIZE];
    int num_columns = 0;
    fgets(line, MAX_BUFFER_SIZE, reader->fp);
    char *column_headers = strtok(line, ",");
    while (column_headers) {
        num_columns++;
        column_headers = strtok(NULL, ",");
    }
    return num_columns;
}

int main() {
    CSVReader *reader = csv_reader_init("data.csv");
    char **data = csv_reader_get_data(reader);
    for (int i = 0; i < reader->current_row; i++) {
        for (int j = 0; j < reader->current_column; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }
    csv_reader_free(reader);
    return 0;
}