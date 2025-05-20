//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} HTMLDocument;

HTMLDocument *new_html_document() {
    HTMLDocument *doc = malloc(sizeof(HTMLDocument));
    doc->lines = NULL;
    doc->num_lines = 0;
    return doc;
}

void free_html_document(HTMLDocument *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i].line);
    }
    free(doc->lines);
    free(doc);
}

void add_line_to_html_document(HTMLDocument *doc, char *line) {
    doc->lines = realloc(doc->lines, sizeof(Line) * (doc->num_lines + 1));
    doc->lines[doc->num_lines].line = strdup(line);
    doc->lines[doc->num_lines].length = strlen(line);
    doc->num_lines++;
}

char *beautify_html_document(HTMLDocument *doc) {
    char *output = malloc(MAX_LINE_LENGTH * doc->num_lines);
    int output_index = 0;
    for (int i = 0; i < doc->num_lines; i++) {
        char *line = doc->lines[i].line;
        int line_length = doc->lines[i].length;
        for (int j = 0; j < line_length; j++) {
            char c = line[j];
            if (c == '<') {
                output[output_index++] = c;
                if (j + 1 < line_length && line[j + 1] == '/') {
                    output[output_index++] = line[j + 1];
                    j++;
                }
                while (j + 1 < line_length && line[j + 1] != '>') {
                    output[output_index++] = line[j + 1];
                    j++;
                }
                output[output_index++] = line[j + 1];
                j++;
            } else if (c == ' ') {
                if (j == 0 || line[j - 1] == '>' || line[j - 1] == '\n') {
                    continue;
                }
                output[output_index++] = c;
            } else if (c == '\n') {
                output[output_index++] = c;
            } else {
                output[output_index++] = c;
            }
        }
        output[output_index++] = '\n';
    }
    output[output_index] = '\0';
    return output;
}

int main() {
    HTMLDocument *doc = new_html_document();
    add_line_to_html_document(doc, "<html>");
    add_line_to_html_document(doc, "  <head>");
    add_line_to_html_document(doc, "    <title>Hello World</title>");
    add_line_to_html_document(doc, "  </head>");
    add_line_to_html_document(doc, "  <body>");
    add_line_to_html_document(doc, "    <h1>Hello World</h1>");
    add_line_to_html_document(doc, "  </body>");
    add_line_to_html_document(doc, "</html>");

    char *beautified_html = beautify_html_document(doc);
    printf("%s", beautified_html);

    free_html_document(doc);
    free(beautified_html);

    return 0;
}