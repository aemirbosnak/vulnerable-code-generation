//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: creative
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

HTMLDocument *parse_html_document(const char *html) {
    HTMLDocument *document = malloc(sizeof(HTMLDocument));
    document->lines = NULL;
    document->num_lines = 0;

    char *line_start = (char *)html;
    char *line_end = strchr(line_start, '\n');
    while (line_end != NULL) {
        Line line;
        line.length = line_end - line_start;
        line.line = malloc(line.length + 1);
        memcpy(line.line, line_start, line.length);
        line.line[line.length] = '\0';

        document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(Line));
        document->lines[document->num_lines++] = line;

        line_start = line_end + 1;
        line_end = strchr(line_start, '\n');
    }

    if (line_start != NULL) {
        Line line;
        line.length = strlen(line_start);
        line.line = malloc(line.length + 1);
        memcpy(line.line, line_start, line.length);
        line.line[line.length] = '\0';

        document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(Line));
        document->lines[document->num_lines++] = line;
    }

    return document;
}

void free_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].line);
    }
    free(document->lines);
    free(document);
}

void beautify_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        Line line = document->lines[i];

        // Remove leading whitespace
        while (line.length > 0 && isspace(line.line[0])) {
            line.line++;
            line.length--;
        }

        // Remove trailing whitespace
        while (line.length > 0 && isspace(line.line[line.length - 1])) {
            line.length--;
        }

        // Add indentation
        if (i > 0) {
            document->lines[i].line = realloc(document->lines[i].line, line.length + 2);
            memmove(document->lines[i].line + 2, document->lines[i].line, line.length);
            document->lines[i].line[0] = '\n';
            document->lines[i].line[1] = '\t';
            document->lines[i].length += 2;
        }
    }
}

void print_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        printf("%s", document->lines[i].line);
    }
}

int main() {
    const char *html = "<html>\n<head>\n<title>My Page</title>\n</head>\n<body>\n<h1>Hello, world!</h1>\n</body>\n</html>";

    HTMLDocument *document = parse_html_document(html);
    beautify_html_document(document);
    print_html_document(document);
    free_html_document(document);

    return 0;
}