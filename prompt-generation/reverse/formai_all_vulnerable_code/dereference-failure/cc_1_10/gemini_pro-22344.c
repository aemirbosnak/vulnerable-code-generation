//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: brave
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
    HTMLDocument *document = malloc(sizeof(HTMLDocument));
    document->lines = malloc(sizeof(Line) * 10);
    document->num_lines = 0;
    return document;
}

void free_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].line);
    }
    free(document->lines);
    free(document);
}

void add_line_to_html_document(HTMLDocument *document, char *line) {
    document->lines = realloc(document->lines, sizeof(Line) * (document->num_lines + 1));
    document->lines[document->num_lines].line = strdup(line);
    document->lines[document->num_lines].length = strlen(line);
    document->num_lines++;
}

char *beautify_html_document(HTMLDocument *document) {
    char *output = malloc(MAX_LINE_LENGTH * document->num_lines);
    int output_length = 0;

    for (int i = 0; i < document->num_lines; i++) {
        char *line = document->lines[i].line;
        int line_length = document->lines[i].length;

        // Indent the line.
        for (int j = 0; j < i; j++) {
            output[output_length++] = ' ';
        }

        // Copy the line to the output.
        for (int j = 0; j < line_length; j++) {
            output[output_length++] = line[j];
        }

        // Add a newline character to the output.
        output[output_length++] = '\n';
    }

    output[output_length] = '\0';
    return output;
}

int main() {
    // Read the HTML document from stdin.
    char line[MAX_LINE_LENGTH];
    HTMLDocument *document = new_html_document();
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        add_line_to_html_document(document, line);
    }

    // Beautify the HTML document.
    char *output = beautify_html_document(document);

    // Print the beautified HTML document to stdout.
    printf("%s", output);

    // Free the memory allocated for the HTML document and the output.
    free_html_document(document);
    free(output);

    return 0;
}