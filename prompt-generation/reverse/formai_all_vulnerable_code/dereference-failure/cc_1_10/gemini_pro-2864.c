//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: dynamic
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
} Document;

Document *create_document(char *html) {
    Document *doc = malloc(sizeof(Document));
    doc->num_lines = 0;
    doc->lines = NULL;

    char *line = strtok(html, "\n");
    while (line != NULL) {
        Line *new_line = malloc(sizeof(Line));
        new_line->line = line;
        new_line->length = strlen(line);

        doc->lines = realloc(doc->lines, (doc->num_lines + 1) * sizeof(Line));
        doc->lines[doc->num_lines++] = *new_line;

        line = strtok(NULL, "\n");
    }

    return doc;
}

void free_document(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i].line);
    }
    free(doc->lines);
    free(doc);
}

char *beautify_html(char *html) {
    Document *doc = create_document(html);

    // Indent each line according to its nesting level.
    for (int i = 0; i < doc->num_lines; i++) {
        Line *line = &doc->lines[i];
        int indent_level = 0;
        for (int j = 0; j < line->length; j++) {
            if (line->line[j] == '<') {
                indent_level++;
            } else if (line->line[j] == '>') {
                indent_level--;
            }
        }
        for (int j = 0; j < indent_level; j++) {
            line->line = realloc(line->line, line->length + 2);
            memmove(line->line + 2, line->line, line->length);
            line->line[0] = '\t';
            line->line[1] = '\t';
            line->length += 2;
        }
    }

    // Add newlines after each tag.
    for (int i = 0; i < doc->num_lines; i++) {
        Line *line = &doc->lines[i];
        for (int j = 0; j < line->length; j++) {
            if (line->line[j] == '<') {
                line->line = realloc(line->line, line->length + 2);
                memmove(line->line + 2, line->line + j, line->length - j);
                line->line[j] = '\n';
                line->line[j + 1] = '\t';
                line->length += 2;
                j++;
            }
        }
    }

    // Remove any unnecessary whitespace.
    for (int i = 0; i < doc->num_lines; i++) {
        Line *line = &doc->lines[i];
        int j = 0;
        while (j < line->length) {
            if (line->line[j] == ' ' || line->line[j] == '\t') {
                if (j == 0 || line->line[j - 1] == '\n') {
                    line->line = realloc(line->line, line->length - 1);
                    memmove(line->line + j, line->line + j + 1, line->length - j - 1);
                    line->length--;
                } else {
                    j++;
                }
            } else {
                j++;
            }
        }
    }

    // Convert the document back to a string.
    char *output = malloc(doc->num_lines * MAX_LINE_LENGTH);
    int output_length = 0;
    for (int i = 0; i < doc->num_lines; i++) {
        Line *line = &doc->lines[i];
        memcpy(output + output_length, line->line, line->length);
        output_length += line->length;
    }
    output[output_length] = '\0';

    free_document(doc);

    return output;
}

int main() {
    char *html = "<html>\n<head>\n<title>Hello, world!</title>\n</head>\n<body>\n<h1>Hello, world!</h1>\n</body>\n</html>\n";
    char *beautified_html = beautify_html(html);
    printf("%s\n", beautified_html);

    free(beautified_html);

    return 0;
}