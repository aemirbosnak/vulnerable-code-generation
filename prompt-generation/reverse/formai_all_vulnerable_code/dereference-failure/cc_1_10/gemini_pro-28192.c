//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *data;
    int length;
} String;

typedef struct {
    String *lines;
    int num_lines;
} HtmlDocument;

HtmlDocument *create_html_document(char *html) {
    HtmlDocument *document = malloc(sizeof(HtmlDocument));
    if (document == NULL) {
        return NULL;
    }

    document->lines = NULL;
    document->num_lines = 0;

    char *line = strtok(html, "\n");
    while (line != NULL) {
        String *string = malloc(sizeof(String));
        if (string == NULL) {
            free(document);
            return NULL;
        }

        string->data = line;
        string->length = strlen(line);

        document->lines = realloc(document->lines, sizeof(String) * (document->num_lines + 1));
        if (document->lines == NULL) {
            free(string);
            free(document);
            return NULL;
        }

        document->lines[document->num_lines] = *string;
        document->num_lines++;

        line = strtok(NULL, "\n");
    }

    return document;
}

void free_html_document(HtmlDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].data);
    }
    free(document->lines);
    free(document);
}

char *beautify_html(HtmlDocument *document) {
    char *beautified_html = malloc(MAX_LINE_LENGTH * document->num_lines);
    if (beautified_html == NULL) {
        return NULL;
    }

    int offset = 0;
    for (int i = 0; i < document->num_lines; i++) {
        String line = document->lines[i];

        // Remove leading whitespace
        while (line.data[0] == ' ') {
            line.data++;
            line.length--;
        }

        // Remove trailing whitespace
        while (line.data[line.length - 1] == ' ') {
            line.length--;
        }

        // Indent the line
        for (int j = 0; j < i; j++) {
            beautified_html[offset++] = '\t';
        }

        // Add the line to the beautified HTML
        memcpy(beautified_html + offset, line.data, line.length);
        offset += line.length;

        // Add a newline character
        beautified_html[offset++] = '\n';
    }

    beautified_html[offset] = '\0';

    return beautified_html;
}

int main() {
    char *html = "<html>\n<head>\n<title>Example</title>\n</head>\n<body>\n<h1>Hello, world!</h1>\n</body>\n</html>";

    HtmlDocument *document = create_html_document(html);
    if (document == NULL) {
        fprintf(stderr, "Error creating HTML document\n");
        return EXIT_FAILURE;
    }

    char *beautified_html = beautify_html(document);
    if (beautified_html == NULL) {
        fprintf(stderr, "Error beautifying HTML\n");
        free_html_document(document);
        return EXIT_FAILURE;
    }

    printf("%s", beautified_html);

    free(beautified_html);
    free_html_document(document);

    return EXIT_SUCCESS;
}