//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *data;
    size_t capacity;
    size_t length;
} String;

void string_init(String *s) {
    s->data = malloc(16);
    s->capacity = 16;
    s->length = 0;
    s->data[0] = '\0';
}

void string_append(String *s, const char *str) {
    size_t len = strlen(str);
    if (s->length + len >= s->capacity) {
        s->capacity *= 2;
        s->data = realloc(s->data, s->capacity);
    }
    strcat(s->data, str);
    s->length += len;
    s->data[s->length] = '\0';
}

void string_free(String *s) {
    free(s->data);
}

typedef struct {
    FILE *file;
    char delimiter;
    String *row;
} CSVReader;

void csv_reader_init(CSVReader *reader, FILE *file, char delimiter) {
    reader->file = file;
    reader->delimiter = delimiter;
    string_init(reader->row);
}

int csv_reader_read_row(CSVReader *reader) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int fields = 0;

    if (fgets(line, MAX_LINE_LENGTH, reader->file) == NULL) {
        return 0;
    }

    string_init(reader->row);
    token = strtok(line, reader->delimiter);
    while (token!= NULL) {
        string_append(reader->row, token);
        fields++;
        token = strtok(NULL, reader->delimiter);
    }

    return fields;
}

void csv_reader_free(CSVReader *reader) {
    string_free(reader->row);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    CSVReader reader;

    file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    csv_reader_init(&reader, file, ',');

    while (csv_reader_read_row(&reader) > 0) {
        printf("Row: %s\n", reader.row->data);
    }

    csv_reader_free(&reader);
    fclose(file);

    return 0;
}