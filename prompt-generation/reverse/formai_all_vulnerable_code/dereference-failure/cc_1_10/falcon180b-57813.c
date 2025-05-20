//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 5000
#define MAX_COL 1000
#define MAX_LINE_SIZE 10240

typedef struct {
    char **data;
    int row_count;
    int col_count;
} CSVReader;

void csv_reader_init(CSVReader *reader) {
    reader->row_count = 0;
    reader->col_count = 0;
    reader->data = NULL;
}

void csv_reader_destroy(CSVReader *reader) {
    for (int i = 0; i < reader->row_count; i++) {
        for (int j = 0; j < reader->col_count; j++) {
            free(reader->data[i][j]);
        }
        free(reader->data[i]);
    }
    free(reader->data);
}

void csv_reader_read_file(CSVReader *reader, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    int row = 0;
    int col = 0;
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *ptr = strtok(line, ",");
        while (ptr!= NULL) {
            if (row >= MAX_ROW) {
                printf("Error: Maximum number of rows reached\n");
                exit(1);
            }
            if (col >= MAX_COL) {
                printf("Error: Maximum number of columns reached\n");
                exit(1);
            }
            reader->data[row][col] = strdup(ptr);
            ptr = strtok(NULL, ",");
            col++;
        }
        row++;
        col = 0;
    }

    fclose(fp);
}

void csv_reader_print_data(CSVReader *reader) {
    for (int i = 0; i < reader->row_count; i++) {
        for (int j = 0; j < reader->col_count; j++) {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSVReader reader;
    csv_reader_init(&reader);

    csv_reader_read_file(&reader, "example.csv");

    csv_reader_print_data(&reader);

    csv_reader_destroy(&reader);

    return 0;
}