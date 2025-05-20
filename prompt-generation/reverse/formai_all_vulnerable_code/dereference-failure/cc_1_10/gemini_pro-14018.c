//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *buffer;
    size_t size;
    size_t len;
} CSVReader;

CSVReader *CSVReader_new(FILE *fp) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->buffer = malloc(1024);  
    reader->size = 1024; 
    reader->len = 0; 

    while (!feof(fp)) {
        size_t bytes_read = fread(reader->buffer + reader->len, 1, reader->size - reader->len, fp);
        reader->len += bytes_read;

        if (reader->len == reader->size) {
            reader->size *= 2;
            reader->buffer = realloc(reader->buffer, reader->size);
        }
    }

    return reader;
}

void CSVReader_free(CSVReader *reader) {
    free(reader->buffer);
    free(reader);
}

char *CSVReader_next_field(CSVReader *reader) {
    char *field = NULL;
    size_t field_len = 0;

    while (reader->len > 0) {
        char c = reader->buffer[reader->len - 1];

        if (c == ',') {
            reader->len--;
            break;
        } else if (c == '\n' || c == '\r') {
            reader->len--;
            continue;
        } else {
            field_len++;
            reader->len--;
        }
    }

    if (field_len > 0) {
        field = malloc(field_len + 1);
        memcpy(field, reader->buffer + reader->len, field_len);
        field[field_len] = '\0';
    }

    return field;
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    CSVReader *reader = CSVReader_new(fp);
    char *field;
    while ((field = CSVReader_next_field(reader)) != NULL) {
        printf("%s\n", field);
        free(field);
    }

    CSVReader_free(reader);
    fclose(fp);

    return EXIT_SUCCESS;
}