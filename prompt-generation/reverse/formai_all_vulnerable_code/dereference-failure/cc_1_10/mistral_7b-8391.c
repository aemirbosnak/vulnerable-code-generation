//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t capacity;
    size_t length;
    char* data;
} string_t;

void string_init(string_t* str, size_t capacity) {
    str->capacity = capacity;
    str->length = 0;
    str->data = calloc(capacity + 1, sizeof(char));
}

void string_append(string_t* str, const char* src, size_t len) {
    if (str->length + len >= str->capacity) {
        str->capacity *= 2;
        str->data = realloc(str->data, str->capacity + 1);
    }

    memcpy(str->data + str->length, src, len);
    str->length += len;
}

void string_append_char(string_t* str, char c) {
    if (str->length + 1 >= str->capacity) {
        str->capacity *= 2;
        str->data = realloc(str->data, str->capacity + 1);
    }

    str->data[str->length++] = c;
}

void string_deinit(string_t* str) {
    free(str->data);
}

void print_csv_row(const string_t* values) {
    for (size_t i = 0; i < values->length; ++i) {
        printf("%s%s", values->data, i == values->length - 1 ? "" : ", ");
    }
    printf("\n");
}

void read_csv_line(FILE* file, string_t* lines, string_t* values) {
    char c;
    size_t capacity = 128;
    string_init(values, capacity);

    string_append_char(lines, c = fgetc(file));
    while (c != EOF && c != '\n') {
        if (c == ',') {
            string_append(values, lines->data, lines->length);
            lines->length = 0;
            capacity *= 2;
            string_init(values, capacity);
        } else {
            string_append_char(lines, c);
        }

        string_append_char(lines, c = fgetc(file));
    }

    if (lines->length > 0) {
        string_append(values, lines->data, lines->length);
    }

    string_deinit(lines);
}

int main() {
    FILE* file = fopen("data.csv", "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }

    string_t lines, values;
    while (fgetc(file) != EOF) {
        read_csv_line(file, &lines, &values);
        print_csv_row(&values);
    }

    fclose(file);
    string_deinit(&lines);
    string_deinit(&values);

    return 0;
}