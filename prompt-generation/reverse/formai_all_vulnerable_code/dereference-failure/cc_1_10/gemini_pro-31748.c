//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 16

typedef struct {
    char *buffer;
    int length;
    int capacity;
} String;

String *string_new() {
    String *s = malloc(sizeof(String));
    s->buffer = malloc(MAX_LINE_LENGTH);
    s->length = 0;
    s->capacity = MAX_LINE_LENGTH;
    return s;
}

void string_free(String *s) {
    free(s->buffer);
    free(s);
}

void string_append(String *s, const char *str) {
    int len = strlen(str);
    if (s->length + len > s->capacity) {
        s->capacity *= 2;
        s->buffer = realloc(s->buffer, s->capacity);
    }
    memcpy(s->buffer + s->length, str, len);
    s->length += len;
}

String *html_beautify(String *html) {
    String *out = string_new();
    int indent_level = 0;
    bool in_tag = false;
    char *p = html->buffer;
    while (*p) {
        if (*p == '<') {
            if (in_tag) {
                string_append(out, ">");
            }
            in_tag = true;
            string_append(out, p);
        } else if (*p == '>') {
            in_tag = false;
            string_append(out, p);
            if (*(p + 1) != '<') {
                string_append(out, "\n");
                for (int i = 0; i < indent_level; i++) {
                    string_append(out, "    ");
                }
            }
        } else if (*p == '\n') {
            string_append(out, p);
            if (!in_tag) {
                for (int i = 0; i < indent_level; i++) {
                    string_append(out, "    ");
                }
            }
        } else if (*p == ' ') {
            if (!in_tag) {
                string_append(out, " ");
            }
        } else {
            string_append(out, p);
        }
        if (*p++ == '<') {
            indent_level++;
        } else if (*--p == '>') {
            indent_level--;
        }
    }
    if (in_tag) {
        string_append(out, ">");
    }
    return out;
}

int main() {
    String *html = string_new();
    string_append(html, "<html>\n");
    string_append(html, "    <head>\n");
    string_append(html, "        <title>Hello World</title>\n");
    string_append(html, "    </head>\n");
    string_append(html, "    <body>\n");
    string_append(html, "        <h1>Hello World</h1>\n");
    string_append(html, "        <p>This is a paragraph.</p>\n");
    string_append(html, "    </body>\n");
    string_append(html, "</html>\n");

    String *out = html_beautify(html);
    printf("%s", out->buffer);

    string_free(html);
    string_free(out);
    return 0;
}