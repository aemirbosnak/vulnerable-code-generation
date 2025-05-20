//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct csv_reader_t {
    FILE *file;
    char delimiter;
    char *line_buffer;
    int line_number;
    int column_count;
    char **column_pointers;
} csv_reader;

int init_csv_reader(csv_reader *reader, const char *filename, char delimiter) {
    reader->file = fopen(filename, "r");
    if (reader->file == NULL) {
        return -1;
    }

    reader->delimiter = delimiter;
    reader->line_buffer = (char*)malloc(sizeof(char) * MAX_LINE_SIZE);
    reader->line_number = 0;
    reader->column_count = 0;
    reader->column_pointers = NULL;

    return 0;
}

int read_line(csv_reader *reader) {
    char *result = fgets(reader->line_buffer, MAX_LINE_SIZE, reader->file);
    if (result == NULL) {
        return -1;
    }

    int length = strlen(reader->line_buffer);
    if (reader->line_buffer[length - 1] == '\n') {
        reader->line_buffer[length - 1] = '\0';
    }

    reader->line_number++;

    char *buffer = strdup(reader->line_buffer);
    char *token = strtok(buffer, &reader->delimiter);
    reader->column_count = 0;
    while (token != NULL) {
        reader->column_pointers = (char**)realloc(reader->column_pointers, sizeof(char*) * (reader->column_count + 1));
        reader->column_pointers[reader->column_count] = strdup(token);
        reader->column_count++;
        token = strtok(NULL, &reader->delimiter);
    }
    free(buffer);

    return 0;
}

void free_csv_reader(csv_reader *reader) {
    for (int i = 0; i < reader->column_count; i++) {
        free(reader->column_pointers[i]);
    }
    free(reader->column_pointers);
    free(reader->line_buffer);
    fclose(reader->file);
}

int main() {
    csv_reader reader;
    if (init_csv_reader(&reader, "example.csv", ',') != 0) {
        printf("Error: Could not open file\n");
        return -1;
    }

    while (read_line(&reader) == 0) {
        printf("Line %d:\n", reader.line_number);
        for (int i = 0; i < reader.column_count; i++) {
            printf("%s\n", reader.column_pointers[i]);
        }
    }

    free_csv_reader(&reader);

    return 0;
}