//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 50
#define MAX_FIELD_LEN 100

typedef struct {
    char* fields[MAX_FIELDS];
    int num_fields;
} CSVRow;

typedef struct {
    FILE* fp;
    int last_char;
    int eof;
    char delimiter;
} CSVReader;

CSVReader* create_csv_reader(char* filename, char delimiter) {
    CSVReader* reader = (CSVReader*) malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->eof = 0;
    reader->delimiter = delimiter;
    reader->last_char = fgetc(reader->fp);

    return reader;
}

CSVRow* read_csv_row(CSVReader* reader) {
    CSVRow* row = (CSVRow*) malloc(sizeof(CSVRow));
    row->num_fields = 0;

    while (!reader->eof && row->num_fields < MAX_FIELDS) {
        char* field = (char*) malloc(MAX_FIELD_LEN);
        int field_len = 0;

        while (reader->last_char != EOF && reader->last_char != reader->delimiter && reader->last_char != '\n') {
            field[field_len++] = reader->last_char;
            reader->last_char = fgetc(reader->fp);
        }

        field[field_len] = '\0';
        row->fields[row->num_fields++] = field;

        if (reader->last_char == '\n' || reader->last_char == EOF) {
            break;
        }

        reader->last_char = fgetc(reader->fp);
    }

    if (reader->last_char == EOF) {
        reader->eof = 1;
    }

    return row;
}

void free_csv_row(CSVRow* row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }

    free(row);
}

void close_csv_reader(CSVReader* reader) {
    fclose(reader->fp);
    free(reader);
}

int main() {
    CSVReader* reader = create_csv_reader("data.csv", ',');
    CSVRow* row;

    while (!reader->eof) {
        row = read_csv_row(reader);

        for (int i = 0; i < row->num_fields; i++) {
            printf("%s ", row->fields[i]);
        }

        printf("\n");

        free_csv_row(row);
    }

    close_csv_reader(reader);

    return 0;
}