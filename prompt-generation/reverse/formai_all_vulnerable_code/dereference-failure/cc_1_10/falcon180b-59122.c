//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVReader;

CSVReader *csv_reader_create(void) {
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    reader->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    reader->num_rows = 0;
    reader->num_columns = 0;
    return reader;
}

int csv_reader_parse_line(CSVReader *reader, char *line) {
    int i, j, num_columns = 0;
    char *token;
    if (reader->num_rows >= MAX_ROWS) {
        return -1;
    }
    if (reader->num_columns == 0) {
        token = strtok(line, ",");
        while (token!= NULL) {
            reader->data[reader->num_rows] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(reader->data[reader->num_rows], token);
            reader->num_columns++;
            reader->num_rows++;
            token = strtok(NULL, ",");
        }
    } else {
        for (i = 0; i < reader->num_columns; i++) {
            token = strtok(line, ",");
            if (token == NULL) {
                return -1;
            }
            reader->data[reader->num_rows][i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
            strcpy(reader->data[reader->num_rows][i], token);
        }
        reader->num_rows++;
    }
    return 0;
}

void csv_reader_destroy(CSVReader *reader) {
    int i, j;
    for (i = 0; i < reader->num_rows; i++) {
        for (j = 0; j < reader->num_columns; j++) {
            free(reader->data[i][j]);
        }
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    CSVReader *reader = csv_reader_create();
    file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        csv_reader_parse_line(reader, line);
    }
    fclose(file);
    int i, j;
    for (i = 0; i < reader->num_rows; i++) {
        for (j = 0; j < reader->num_columns; j++) {
            printf("%s ", reader->data[i][j]);
        }
        printf("\n");
    }
    csv_reader_destroy(reader);
    return 0;
}