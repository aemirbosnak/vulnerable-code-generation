//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVReader;

CSVReader *csv_reader_create(FILE *file) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->num_rows = 0;
    reader->num_columns = 0;
    reader->data = malloc(MAX_COLUMNS * sizeof(char *));

    char line[MAX_LINE_SIZE];
    char *token;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int i = 0;
        token = strtok(line, ",");
        while (token!= NULL) {
            reader->data[i] = malloc(strlen(token) + 1);
            strcpy(reader->data[i], token);
            i++;
            token = strtok(NULL, ",");
        }
        reader->num_columns = i;
        reader->num_rows++;
    }

    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        for (int j = 0; j < reader->num_columns; j++) {
            free(reader->data[j * reader->num_rows + i]);
        }
    }
    free(reader->data);
    free(reader);
}

char **csv_reader_get_data(CSVReader *reader) {
    return reader->data;
}

int csv_reader_get_num_rows(CSVReader *reader) {
    return reader->num_rows;
}

int csv_reader_get_num_columns(CSVReader *reader) {
    return reader->num_columns;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    CSVReader *reader = csv_reader_create(file);

    char **data = csv_reader_get_data(reader);
    int num_rows = csv_reader_get_num_rows(reader);
    int num_columns = csv_reader_get_num_columns(reader);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            printf("%s ", data[j * num_rows + i]);
        }
        printf("\n");
    }

    csv_reader_destroy(reader);
    fclose(file);

    return 0;
}