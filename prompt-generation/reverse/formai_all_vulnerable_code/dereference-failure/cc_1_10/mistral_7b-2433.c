//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    size_t length;
    size_t capacity;
    char *data;
} string;

string read_line(FILE *file) {
    size_t capacity = 256;
    string line = {0};
    char *buffer = malloc(capacity);
    size_t position = 0;

    while (position < capacity - 1 && getc(file) != '\n' && !feof(file)) {
        buffer[position++] = (char) toupper((int) getc(file));
    }

    if (position > 0) {
        line.length = position;
        line.capacity = capacity;
        line.data = realloc(buffer, line.length + 1);
        line.data[position] = '\0';
    }

    free(buffer);

    return line;
}

void split_line(string line, size_t *num_fields, string **fields) {
    size_t capacity = 8;
    size_t num_allocated_fields = 0;

    *fields = malloc(capacity * sizeof(string));
    *num_fields = 0;

    string token = {0};
    char *token_start = line.data;
    char delimiter = ',';

    while (token_start < line.data + line.length) {
        size_t field_length = 0;

        while (*token_start && (*token_start != delimiter)) {
            token.data[field_length++] = *token_start++;
        }

        if (field_length > 0) {
            token.length = field_length;
            token.capacity = field_length + 1;
            token.data = realloc(token.data, token.capacity * sizeof(char));
            (*fields)[*num_fields] = token;
            (*num_fields)++;

            if (*num_fields >= capacity) {
                capacity *= 2;
                *fields = realloc(*fields, capacity * sizeof(string));
            }
        }

        if (*token_start == delimiter) {
            token_start++;
            if (*token_start == '\0') {
                break;
            }
        }
    }
}

void free_memory(size_t num_fields, string *fields) {
    for (size_t i = 0; i < num_fields; i++) {
        free(fields[i].data);
        free(fields[i].data);
    }

    free(fields);
}

int main() {
    FILE *file = fopen("example.csv", "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open the CSV file.\n");
        return 1;
    }

    string line;
    size_t num_fields;
    string *fields;

    while (fgetc(file) != EOF) {
        line = read_line(file);
        split_line(line, &num_fields, &fields);

        printf("|");
        for (size_t i = 0; i < num_fields; i++) {
            printf("%s|", fields[i].data);
        }
        printf("\n");

        free_memory(num_fields, fields);
    }

    fclose(file);

    return 0;
}