//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *buffer;
    size_t capacity;
    size_t size;
} String;

void string_init(String *string) {
    string->buffer = malloc(128);
    string->capacity = 128;
    string->size = 0;
}

void string_free(String *string) {
    free(string->buffer);
    string->buffer = NULL;
    string->capacity = 0;
    string->size = 0;
}

void string_append(String *string, char *buffer, size_t size) {
    if (string->size + size > string->capacity) {
        string->capacity *= 2;
        string->buffer = realloc(string->buffer, string->capacity);
    }
    memcpy(string->buffer + string->size, buffer, size);
    string->size += size;
}

void string_append_char(String *string, char c) {
    if (string->size + 1 > string->capacity) {
        string->capacity *= 2;
        string->buffer = realloc(string->buffer, string->capacity);
    }
    string->buffer[string->size] = c;
    string->size += 1;
}

void beautify_html(String *string) {
    bool in_tag = false;
    bool in_comment = false;
    bool in_string = false;
    char quote = '\0';
    size_t indent = 0;
    for (size_t i = 0; i < string->size; i++) {
        char c = string->buffer[i];
        switch (c) {
            case '<':
                if (!in_comment && !in_string) {
                    in_tag = true;
                    string_append(string, "\n", 1);
                    for (size_t j = 0; j < indent; j++) {
                        string_append_char(string, '\t');
                    }
                }
                string_append_char(string, c);
                break;
            case '>':
                if (in_tag) {
                    in_tag = false;
                    string_append(string, "\n", 1);
                }
                string_append_char(string, c);
                break;
            case '/':
                if (in_tag && string->buffer[i + 1] == '>') {
                    in_tag = false;
                    indent--;
                    string_append(string, "\n", 1);
                    for (size_t j = 0; j < indent; j++) {
                        string_append_char(string, '\t');
                    }
                    string_append(string, "</", 2);
                    i++;
                } else {
                    string_append_char(string, c);
                }
                break;
            case '"':
            case '\'':
                if (!in_comment && !in_tag) {
                    if (!in_string) {
                        in_string = true;
                        quote = c;
                    } else if (in_string && quote == c) {
                        in_string = false;
                    }
                }
                string_append_char(string, c);
                break;
            case '-':
                if (in_tag && string->buffer[i + 1] == '-' && string->buffer[i + 2] == '>') {
                    in_comment = false;
                    i += 2;
                } else {
                    string_append_char(string, c);
                }
                break;
            case '\n':
                if (!in_comment && !in_tag) {
                    string_append(string, "\n", 1);
                }
                break;
            default:
                if (!in_comment && !in_string && c != ' ' && c != '\t') {
                    indent++;
                }
                string_append_char(string, c);
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    String string;
    string_init(&string);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        string_append(&string, buffer, strlen(buffer));
    }
    fclose(file);

    beautify_html(&string);

    printf("%s", string.buffer);

    string_free(&string);

    return EXIT_SUCCESS;
}