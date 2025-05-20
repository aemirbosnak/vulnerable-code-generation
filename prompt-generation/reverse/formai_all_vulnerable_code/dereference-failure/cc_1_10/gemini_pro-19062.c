//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: satisfied
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

HTMLDocument *create_html_document() {
    HTMLDocument *document = malloc(sizeof(HTMLDocument));
    document->lines = NULL;
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
    document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(Line));
    document->lines[document->num_lines].line = strdup(line);
    document->lines[document->num_lines].length = strlen(line);
    document->num_lines++;
}

void beautify_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        Line *line = &document->lines[i];

        // Remove leading and trailing whitespace.
        while (line->length > 0 && isspace(line->line[line->length - 1])) {
            line->length--;
        }
        while (line->length > 0 && isspace(line->line[0])) {
            line->line++;
            line->length--;
        }

        // Indent the line.
        for (int j = 0; j < i; j++) {
            printf("  ");
        }

        // Print the line.
        printf("%s\n", line->line);
    }
}

int main() {
    // Create an HTML document.
    HTMLDocument *document = create_html_document();

    // Add some lines to the document.
    add_line_to_html_document(document, "<html>");
    add_line_to_html_document(document, "  <head>");
    add_line_to_html_document(document, "    <title>My Website</title>");
    add_line_to_html_document(document, "  </head>");
    add_line_to_html_document(document, "  <body>");
    add_line_to_html_document(document, "    <h1>Welcome to my website!</h1>");
    add_line_to_html_document(document, "    <p>This is my website. It is still under construction, but I will be adding new content soon.</p>");
    add_line_to_html_document(document, "  </body>");
    add_line_to_html_document(document, "</html>");

    // Beautify the HTML document.
    beautify_html_document(document);

    // Free the HTML document.
    free_html_document(document);

    return 0;
}