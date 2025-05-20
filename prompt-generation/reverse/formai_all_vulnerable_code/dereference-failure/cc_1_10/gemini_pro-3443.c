//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *data;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Document;

Document *document_new() {
    Document *document = malloc(sizeof(Document));
    document->lines = malloc(sizeof(Line) * 10);
    document->num_lines = 0;
    return document;
}

void document_free(Document *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].data);
    }
    free(document->lines);
    free(document);
}

void document_add_line(Document *document, char *line) {
    if (document->num_lines == document->num_lines) {
        document->lines = realloc(document->lines, sizeof(Line) * (document->num_lines * 2));
    }
    document->lines[document->num_lines].data = strdup(line);
    document->lines[document->num_lines].length = strlen(line);
    document->num_lines++;
}

char *document_to_string(Document *document) {
    char *string = malloc(sizeof(char) * (document->num_lines * MAX_LINE_LENGTH));
    int length = 0;
    for (int i = 0; i < document->num_lines; i++) {
        memcpy(string + length, document->lines[i].data, document->lines[i].length);
        length += document->lines[i].length;
        string[length++] = '\n';
    }
    string[length] = '\0';
    return string;
}

int main() {
    Document *document = document_new();
    document_add_line(document, "<html>");
    document_add_line(document, "  <head>");
    document_add_line(document, "    <title>Hello World</title>");
    document_add_line(document, "  </head>");
    document_add_line(document, "  <body>");
    document_add_line(document, "    <h1>Hello World</h1>");
    document_add_line(document, "  </body>");
    document_add_line(document, "</html>");
    char *string = document_to_string(document);
    printf("%s", string);
    free(string);
    document_free(document);
    return 0;
}