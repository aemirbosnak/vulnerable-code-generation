//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *content;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} HTMLDocument;

HTMLDocument *html_document_new() {
    HTMLDocument *document = malloc(sizeof(HTMLDocument));
    document->lines = malloc(sizeof(Line));
    document->num_lines = 0;
    return document;
}

void html_document_free(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].content);
    }
    free(document->lines);
    free(document);
}

void html_document_add_line(HTMLDocument *document, char *line) {
    document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(Line));
    document->lines[document->num_lines].content = strdup(line);
    document->lines[document->num_lines].length = strlen(line);
    document->num_lines++;
}

char *html_document_to_string(HTMLDocument *document) {
    char *output = malloc(MAX_LINE_LENGTH * document->num_lines);
    int offset = 0;
    for (int i = 0; i < document->num_lines; i++) {
        strcpy(output + offset, document->lines[i].content);
        offset += document->lines[i].length;
    }
    return output;
}

int main() {
    HTMLDocument *document = html_document_new();

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, stdin) != -1) {
        html_document_add_line(document, line);
    }

    char *output = html_document_to_string(document);
    printf("%s", output);

    html_document_free(document);
    free(output);

    return 0;
}