//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct row {
    char *name;
    char *address;
} Row;

typedef struct csv_reader {
    FILE *file;
    Row *rows;
    int num_rows;
} CSV_Reader;

CSV_Reader *csv_reader_create(const char *filename) {
    CSV_Reader *reader = malloc(sizeof(CSV_Reader));
    reader->file = fopen(filename, "r");
    if (reader->file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    reader->rows = malloc(sizeof(Row) * 100);
    reader->num_rows = 0;
    return reader;
}

void csv_reader_destroy(CSV_Reader *reader) {
    fclose(reader->file);
    free(reader->rows);
    free(reader);
}

int csv_reader_next(CSV_Reader *reader, Row *row) {
    char line[256];
    int num_cols = 0;
    int i;
    
    if (reader->num_rows == 0) {
        fgets(line, sizeof(line), reader->file);
        sscanf(line, "%d,%[^\n]", &num_cols, row->name);
        reader->num_rows++;
        for (i = 0; i < num_cols; i++) {
            fgets(line, sizeof(line), reader->file);
            sscanf(line, "%s", row->address + i * 50);
        }
    } else {
        fgets(line, sizeof(line), reader->file);
        sscanf(line, "%s", row->name);
        for (i = 0; i < num_cols; i++) {
            fgets(line, sizeof(line), reader->file);
            sscanf(line, "%s", row->address + i * 50);
        }
    }
    return num_cols;
}

int main(int argc, char *argv[]) {
    CSV_Reader *reader = csv_reader_create(argv[1]);
    Row row;
    
    while (csv_reader_next(reader, &row)) {
        printf("Name: %s\n", row.name);
        printf("Address: %s\n", row.address);
    }
    
    csv_reader_destroy(reader);
    return 0;
}