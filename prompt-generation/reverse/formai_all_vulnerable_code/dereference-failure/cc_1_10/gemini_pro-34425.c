//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *str;
    int len;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Document;

Document *document_new() {
    Document *doc = malloc(sizeof(Document));
    doc->lines = NULL;
    doc->num_lines = 0;
    return doc;
}

void document_free(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i].str);
    }
    free(doc->lines);
    free(doc);
}

Line *line_new(char *str) {
    Line *line = malloc(sizeof(Line));
    line->str = strdup(str);
    line->len = strlen(str);
    return line;
}

void line_free(Line *line) {
    free(line->str);
    free(line);
}

void document_add_line(Document *doc, Line *line) {
    doc->lines = realloc(doc->lines, sizeof(Line) * (doc->num_lines + 1));
    doc->lines[doc->num_lines++] = *line;
}

char *document_to_string(Document *doc) {
    char *str = malloc(MAX_LINE_LENGTH * doc->num_lines);
    int len = 0;
    for (int i = 0; i < doc->num_lines; i++) {
        memcpy(str + len, doc->lines[i].str, doc->lines[i].len);
        len += doc->lines[i].len;
        str[len++] = '\n';
    }
    str[len] = '\0';
    return str;
}

void document_beautify(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        Line *line = &doc->lines[i];
        int indent = 0;
        for (int j = 0; j < line->len; j++) {
            if (line->str[j] == '{') {
                indent++;
            } else if (line->str[j] == '}') {
                indent--;
            } else if (line->str[j] == '\n') {
                for (int k = 0; k < indent; k++) {
                    line->str[j + k] = ' ';
                }
            }
        }
    }
}

int main() {
    Document *doc = document_new();
    char *str =
        "int main() {\n"
        "    int a = 1;\n"
        "    if (a == 1) {\n"
        "        int b = 2;\n"
        "    }\n"
        "    return 0;\n"
        "}";

    char *lines[6];
    lines[0] = "int main() {";
    lines[1] = "    int a = 1;";
    lines[2] = "    if (a == 1) {";
    lines[3] = "        int b = 2;";
    lines[4] = "    }";
    lines[5] = "    return 0;";

    for (int i = 0; i < 6; i++) {
        document_add_line(doc, line_new(lines[i]));
    }

    document_beautify(doc);

    char *beautified_str = document_to_string(doc);
    printf("%s", beautified_str);

    document_free(doc);
    free(beautified_str);

    return 0;
}