//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_LENGTH 1000

typedef struct {
    char delimiter;
    FILE *file;
    int num_rows;
    int num_cols;
    char **data;
} CSVReader;

CSVReader *create_csv_reader(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->file = file;
    reader->delimiter = ',';
    reader->num_rows = 0;
    reader->num_cols = 0;
    reader->data = malloc(MAX_ROWS * sizeof(char*));

    char line[MAX_CELL_LENGTH];
    while (fgets(line, MAX_CELL_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        if (cols > reader->num_cols) {
            reader->num_cols = cols;
        }
        reader->num_rows++;
    }

    reader->data = realloc(reader->data, reader->num_rows * sizeof(char*));
    rewind(file);
    return reader;
}

void destroy_csv_reader(CSVReader *reader) {
    fclose(reader->file);
    free(reader->data);
    free(reader);
}

int get_num_rows(CSVReader *reader) {
    return reader->num_rows;
}

int get_num_cols(CSVReader *reader) {
    return reader->num_cols;
}

char get_delimiter(CSVReader *reader) {
    return reader->delimiter;
}

char **get_data(CSVReader *reader) {
    return reader->data;
}

int main() {
    CSVReader *reader = create_csv_reader("example.csv");

    int num_rows = get_num_rows(reader);
    int num_cols = get_num_cols(reader);

    printf("Number of rows: %d\n", num_rows);
    printf("Number of columns: %d\n", num_cols);

    char **data = get_data(reader);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s ", data[i * num_cols + j]);
        }
        printf("\n");
    }

    destroy_csv_reader(reader);

    return 0;
}