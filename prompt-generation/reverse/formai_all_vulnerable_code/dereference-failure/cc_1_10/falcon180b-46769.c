//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1024

typedef struct {
    char delimiter;
    FILE *file;
    char buffer[MAX_ROW_SIZE];
    int row_index;
} CSVReader;

CSVReader *csv_reader_create(FILE *file, char delimiter) {
    CSVReader *reader = (CSVReader *) malloc(sizeof(CSVReader));
    reader->delimiter = delimiter;
    reader->file = file;
    reader->row_index = 0;
    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    free(reader);
}

int csv_reader_read(CSVReader *reader, char **data) {
    int row_count = 0;
    char *row_data = NULL;

    while (fgets(reader->buffer, MAX_ROW_SIZE, reader->file)!= NULL) {
        row_count++;
        row_data = realloc(row_data, reader->row_index + strlen(reader->buffer) + 1);
        strcat(row_data, reader->buffer);
        if (row_count > 1) {
            char *token = strtok(row_data, reader->delimiter);
            while (token!= NULL) {
                *data = token;
                data += 1;
                token = strtok(NULL, reader->delimiter);
            }
        } else {
            *data = row_data;
        }
        reader->row_index = 0;
    }

    return row_count;
}

int main(int argc, char *argv[]) {
    FILE *file = fopen("data.csv", "r");
    CSVReader *reader = csv_reader_create(file, ',');
    char *data = NULL;

    int row_count = csv_reader_read(reader, &data);

    for (int i = 0; i < row_count; i++) {
        printf("%s\n", data[i]);
    }

    csv_reader_destroy(reader);
    fclose(file);

    return 0;
}