//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CSVRow {
    char **fields;
    int num_fields;
};

struct CSVReader {
    FILE *file;
    int has_header;
    char delimiter;
};

struct CSVReader *new_csv_reader(const char *filename, int has_header, char delimiter) {
    struct CSVReader *reader = malloc(sizeof(struct CSVReader));
    reader->file = fopen(filename, "r");
    reader->has_header = has_header;
    reader->delimiter = delimiter;
    return reader;
}

struct CSVRow *csv_reader_get_row(struct CSVReader *reader) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, reader->file)) != -1) {
        struct CSVRow *row = malloc(sizeof(struct CSVRow));
        
        char *field;
        int num_fields = 0;
        int max_fields = 10;
        char **fields = malloc(max_fields * sizeof(char*));
        
        // tokenize line into fields
        field = strtok(line, &reader->delimiter);
        while (field != NULL) {
            fields[num_fields] = field;
            num_fields++;
            if (num_fields >= max_fields) {
                max_fields *= 2;
                fields = realloc(fields, max_fields * sizeof(char*));
            }
            field = strtok(NULL, &reader->delimiter);
        }
        
        row->num_fields = num_fields;
        row->fields = fields;
        
        if (reader->has_header) {
            free(line);
            return NULL; // don't return header row
        } else {
            return row;
        }
    } else {
        return NULL; // end of file
    }
}

void free_csv_reader(struct CSVReader *reader) {
    fclose(reader->file);
    free(reader);
}

void free_csv_row(struct CSVRow *row) {
    free(row->fields);
    free(row);
}

int main() {
    struct CSVReader *reader = new_csv_reader("data.csv", 1, ',');
    
    struct CSVRow *row;
    while ((row = csv_reader_get_row(reader)) != NULL) {
        if (row->num_fields >= 2) {
            printf("%s - %s\n", row->fields[0], row->fields[1]);
        }
        free_csv_row(row);
    }
    
    free_csv_reader(reader);
    
    return 0;
}