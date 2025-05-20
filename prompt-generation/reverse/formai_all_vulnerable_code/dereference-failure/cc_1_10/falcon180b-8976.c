//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define DELIMITER ","

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVReader;

CSVReader *create_csv_reader(FILE *file) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->num_rows = 0;
    reader->num_columns = 0;
    reader->data = malloc(sizeof(char *) * MAX_COLUMNS);
    for (int i = 0; i < MAX_COLUMNS; i++) {
        reader->data[i] = malloc(MAX_LINE_SIZE);
        memset(reader->data[i], 0, MAX_LINE_SIZE);
    }
    return reader;
}

void destroy_csv_reader(CSVReader *reader) {
    for (int i = 0; i < reader->num_columns; i++) {
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int read_csv_line(CSVReader *reader, char *line) {
    char *token = strtok(line, DELIMITER);
    int num_tokens = 0;
    while (token!= NULL) {
        if (num_tokens >= MAX_COLUMNS) {
            printf("Error: too many columns\n");
            return -1;
        }
        strcpy(reader->data[num_tokens], token);
        num_tokens++;
        token = strtok(NULL, DELIMITER);
    }
    reader->num_rows++;
    return 0;
}

int get_csv_num_rows(CSVReader *reader) {
    return reader->num_rows;
}

int get_csv_num_columns(CSVReader *reader) {
    return reader->num_columns;
}

char **get_csv_data(CSVReader *reader) {
    return reader->data;
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        return -1;
    }
    CSVReader *reader = create_csv_reader(file);
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (read_csv_line(reader, line) == -1) {
            destroy_csv_reader(reader);
            fclose(file);
            return -1;
        }
    }
    fclose(file);
    int num_rows = get_csv_num_rows(reader);
    int num_columns = get_csv_num_columns(reader);
    char **data = get_csv_data(reader);
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_columns; j++) {
            printf("%s\t", data[j]);
        }
        printf("\n");
    }
    destroy_csv_reader(reader);
    return 0;
}