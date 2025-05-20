//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} HtmlDocument;

HtmlDocument *html_document_new() {
    HtmlDocument *document = malloc(sizeof(HtmlDocument));
    document->lines = NULL;
    document->num_lines = 0;
    return document;
}

void html_document_free(HtmlDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].line);
    }
    free(document->lines);
    free(document);
}

int html_document_add_line(HtmlDocument *document, char *line) {
    document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(Line));
    document->lines[document->num_lines].line = strdup(line);
    document->lines[document->num_lines].length = strlen(line);
    document->num_lines++;
    return 0;
}

int html_document_beautify(HtmlDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        char *line = document->lines[i].line;
        int length = document->lines[i].length;

        // Remove leading whitespace
        while (length > 0 && isspace(line[length - 1])) {
            length--;
        }
        document->lines[i].length = length;
        line[length] = '\0';

        // Indent tags
        if (line[0] == '<') {
            for (int j = 0; j < i; j++) {
                printf("  ");
            }
        }

        // Print the line
        printf("%s\n", line);
    }

    return 0;
}

int main() {
    HtmlDocument *document = html_document_new();
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        html_document_add_line(document, line);
    }

    html_document_beautify(document);

    html_document_free(document);

    return 0;
}