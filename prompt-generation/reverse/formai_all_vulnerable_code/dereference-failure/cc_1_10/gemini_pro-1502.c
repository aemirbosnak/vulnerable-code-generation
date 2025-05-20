//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: modular
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

HTMLDocument *parse_html(char *html) {
    HTMLDocument *document = malloc(sizeof(HTMLDocument));
    document->lines = NULL;
    document->num_lines = 0;

    char *line_start = html;
    char *line_end = strchr(line_start, '\n');
    while (line_end != NULL) {
        Line line;
        line.length = line_end - line_start;
        line.line = malloc(line.length + 1);
        memcpy(line.line, line_start, line.length);
        line.line[line.length] = '\0';

        document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(Line));
        document->lines[document->num_lines] = line;
        document->num_lines++;

        line_start = line_end + 1;
        line_end = strchr(line_start, '\n');
    }

    return document;
}

void free_html(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].line);
    }
    free(document->lines);
    free(document);
}

void beautify_html(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        Line *line = &document->lines[i];
        char *p = line->line;

        while (*p != '\0') {
            if (*p == '<') {
                *p++ = '\n';
                while (*p != '>' && *p != '\0') {
                    *p++ = '\t';
                }
                if (*p != '\0') {
                    *p++ = '\n';
                }
            } else if (*p == '&') {
                *p++ = '\n';
                while (*p != ';' && *p != '\0') {
                    *p++ = '\t';
                }
                if (*p != '\0') {
                    *p++ = '\n';
                }
            } else {
                p++;
            }
        }
    }
}

void print_html(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        printf("%s", document->lines[i].line);
    }
}

int main() {
    char *html = "<html>\n<head>\n<title>Hello, World!</title>\n</head>\n<body>\n<h1>Hello, World!</h1>\n</body>\n</html>";

    HTMLDocument *document = parse_html(html);
    beautify_html(document);
    print_html(document);
    free_html(document);

    return 0;
}