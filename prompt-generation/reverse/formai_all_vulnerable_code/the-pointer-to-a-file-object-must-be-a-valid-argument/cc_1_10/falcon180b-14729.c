//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char delimiter;
    FILE* file;
    int num_rows;
    int num_cols;
    char** data;
} CSVReader;

CSVReader* create_csv_reader(const char* filename) {
    CSVReader* reader = malloc(sizeof(CSVReader));
    reader->delimiter = ',';
    reader->file = fopen(filename, "r");
    reader->num_rows = 0;
    reader->num_cols = 0;
    reader->data = NULL;
    return reader;
}

void destroy_csv_reader(CSVReader* reader) {
    if (reader->data!= NULL) {
        for (int i = 0; i < reader->num_rows; i++) {
            for (int j = 0; j < reader->num_cols; j++) {
                free(reader->data[i][j]);
            }
            free(reader->data[i]);
        }
        free(reader->data);
    }
    fclose(reader->file);
    free(reader);
}

int read_csv_file(CSVReader* reader) {
    char line[MAX_CELL_SIZE];
    char* token = strtok(line, reader->delimiter);
    int num_cols = 0;
    while (token!= NULL) {
        num_cols++;
        token = strtok(NULL, reader->delimiter);
    }
    if (num_cols > reader->num_cols) {
        reader->num_cols = num_cols;
        for (int i = 0; i < reader->num_rows; i++) {
            for (int j = reader->num_cols; j < num_cols; j++) {
                reader->data[i][j] = NULL;
            }
        }
    }
    rewind(reader->file);
    reader->num_rows = 0;
    while ((fgets(line, MAX_CELL_SIZE, reader->file))!= NULL) {
        reader->num_rows++;
        char** row = malloc(sizeof(char*) * num_cols);
        token = strtok(line, reader->delimiter);
        int col = 0;
        while (token!= NULL) {
            row[col] = strdup(token);
            col++;
            token = strtok(NULL, reader->delimiter);
        }
        reader->data[reader->num_rows - 1] = row;
    }
    return 0;
}

void print_csv_data(CSVReader* reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        for (int j = 0; j < reader->num_cols; j++) {
            printf("%s\t", reader->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSVReader* reader = create_csv_reader("data.csv");
    read_csv_file(reader);
    print_csv_data(reader);
    destroy_csv_reader(reader);
    return 0;
}