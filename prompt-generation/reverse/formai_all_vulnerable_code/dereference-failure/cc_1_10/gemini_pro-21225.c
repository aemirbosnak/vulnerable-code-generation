//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *data;
    int length;
    int capacity;
} String;

String *string_new() {
    String *string = malloc(sizeof(String));
    string->data = malloc(MAX_LINE_LENGTH);
    string->length = 0;
    string->capacity = MAX_LINE_LENGTH;
    return string;
}

void string_free(String *string) {
    free(string->data);
    free(string);
}

void string_append(String *string, char *data) {
    int len = strlen(data);
    if (string->length + len >= string->capacity) {
        string->capacity *= 2;
        string->data = realloc(string->data, string->capacity);
    }
    memcpy(string->data + string->length, data, len);
    string->length += len;
}

int is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int is_tag_start(char c) {
    return c == '<';
}

int is_tag_end(char c) {
    return c == '>';
}

int is_attribute_start(char c) {
    return c == '"';
}

int is_attribute_end(char c) {
    return c == '"';
}

void beautify_html(String *string) {
    int level = 0;
    for (int i = 0; i < string->length; i++) {
        char c = string->data[i];
        if (is_whitespace(c)) {
            continue;
        } else if (is_tag_start(c)) {
            string_append(string, "\n");
            for (int j = 0; j < level; j++) {
                string_append(string, "  ");
            }
            string_append(string, "<");
        } else if (is_tag_end(c)) {
            string_append(string, ">");
        } else if (is_attribute_start(c)) {
            string_append(string, "\"");
        } else if (is_attribute_end(c)) {
            string_append(string, "\"");
        } else {
            string_append(string, &c);
        }
    }
    string_append(string, "\n");
}

int main() {
    String *string = string_new();
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        string_append(string, line);
    }
    beautify_html(string);
    printf("%s", string->data);
    string_free(string);
    return 0;
}