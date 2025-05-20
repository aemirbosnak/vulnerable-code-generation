//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct CSVRow {
    char **data;
    int size;
    struct CSVRow *next;
} CSVRow;

typedef struct CSVReader {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    CSVRow *rows;
} CSVReader;

int count_fields(char *line) {
    int count = 0;
    char *token = strtok(line, ",");
    while (token != NULL) {
        count++;
        token = strtok(NULL, ",");
    }
    return count;
}

CSVRow *create_csv_row(char *line) {
    CSVRow *row = (CSVRow *)malloc(sizeof(CSVRow));
    row->size = count_fields(line);
    row->data = (char **)malloc(sizeof(char *) * row->size);
    char *token = strtok(line, ",");
    int i = 0;
    while (token != NULL) {
        row->data[i] = (char *)malloc(sizeof(char) * (strlen(token)+1));
        strcpy(row->data[i], token);
        token = strtok(NULL, ",");
        i++;
    }
    row->next = NULL;
    return row;
}

void add_csv_row(CSVReader *reader, char *line) {
    CSVRow *row = create_csv_row(line);
    if (reader->rows == NULL) { // first row
        reader->rows = row;
    } else { // add to the end of the list
        CSVRow *current = reader->rows;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = row;
    }
}


void parse_csv(CSVReader *reader) {
    while (fgets(reader->buffer, BUFFER_SIZE, reader->fp) != NULL) {
        add_csv_row(reader, reader->buffer);
    }
}

CSVReader *new_csv_reader(char *filename) {
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    reader->fp = fopen(filename, "r");
    reader->rows = NULL;
    parse_csv(reader);
    return reader;
}

void free_csv_reader(CSVReader *reader) {
    CSVRow *current = reader->rows;
    while (current != NULL) {
        for (int i = 0; i < current->size; i++) {
            free(current->data[i]);
        }
        free(current->data);
        CSVRow *next = current->next;
        free(current);
        current = next;
    }
    fclose(reader->fp);
    free(reader);
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->size; i++) {
        printf("%s ", row->data[i]);
    }
    printf("\n");
}

void print_csv(CSVReader *reader) {
    CSVRow *current = reader->rows;
    while (current != NULL) {
        print_csv_row(current);
        current = current->next;
    }
}

int main() {
    CSVReader *reader = new_csv_reader("example.csv");
    print_csv(reader);
    free_csv_reader(reader);
    return 0;
}