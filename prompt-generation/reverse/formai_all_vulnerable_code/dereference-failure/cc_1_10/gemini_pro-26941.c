//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 10

typedef enum {
    HTML_TAG,
    HTML_CONTENT,
    HTML_COMMENT
} HTML_ELEMENT_TYPE;

typedef struct {
    HTML_ELEMENT_TYPE type;
    char *content;
    int indent_level;
} HTML_ELEMENT;

typedef struct {
    HTML_ELEMENT *elements;
    int num_elements;
    int capacity;
} HTML_DOCUMENT;

// Creates a new HTML document.
HTML_DOCUMENT *html_document_new() {
    HTML_DOCUMENT *document = malloc(sizeof(HTML_DOCUMENT));
    document->elements = NULL;
    document->num_elements = 0;
    document->capacity = 0;
    return document;
}

// Frees the memory associated with an HTML document.
void html_document_free(HTML_DOCUMENT *document) {
    for (int i = 0; i < document->num_elements; i++) {
        free(document->elements[i].content);
    }
    free(document->elements);
    free(document);
}

// Adds an HTML element to a document.
void html_document_add_element(HTML_DOCUMENT *document, HTML_ELEMENT_TYPE type, char *content, int indent_level) {
    if (document->num_elements == document->capacity) {
        document->capacity *= 2;
        document->elements = realloc(document->elements, document->capacity * sizeof(HTML_ELEMENT));
    }

    HTML_ELEMENT element = {
        .type = type,
        .content = content,
        .indent_level = indent_level
    };

    document->elements[document->num_elements++] = element;
}

// Beautifies an HTML document.
void html_document_beautify(HTML_DOCUMENT *document) {
    for (int i = 0; i < document->num_elements; i++) {
        HTML_ELEMENT element = document->elements[i];

        // Indent the element.
        for (int j = 0; j < element.indent_level; j++) {
            printf("    ");
        }

        // Print the element.
        switch (element.type) {
            case HTML_TAG:
                printf("<%s>\n", element.content);
                break;
            case HTML_CONTENT:
                printf("%s\n", element.content);
                break;
            case HTML_COMMENT:
                printf("<!-- %s -->\n", element.content);
                break;
        }
    }
}

// Parses an HTML document from a string.
HTML_DOCUMENT *html_document_parse(char *html) {
    HTML_DOCUMENT *document = html_document_new();

    int indent_level = 0;
    char *start = html;
    char *end = html;

    while (*end != '\0') {
        // Skip whitespace.
        while (*end == ' ' || *end == '\t' || *end == '\n') {
            end++;
        }

        // Check if we're at the start of a tag.
        if (*end == '<') {
            // If we're not at the start of the document, add the previous content as an element.
            if (start != html) {
                html_document_add_element(document, HTML_CONTENT, strndup(start, end - start), indent_level);
            }

            // Increment the indent level.
            indent_level++;

            // Find the end of the tag.
            end++;
            while (*end != '>' && *end != '\0') {
                end++;
            }

            // Add the tag as an element.
            html_document_add_element(document, HTML_TAG, strndup(start + 1, end - start - 1), indent_level);

            // Update the start pointer.
            start = end + 1;
        }
        // Check if we're at the start of a comment.
        else if (*end == '-') {
            // If we're not at the start of the document, add the previous content as an element.
            if (start != html) {
                html_document_add_element(document, HTML_CONTENT, strndup(start, end - start), indent_level);
            }

            // Find the end of the comment.
            end++;
            while (*end != '-' && *end != '-' && *end != '\0') {
                end++;
            }

            // Add the comment as an element.
            html_document_add_element(document, HTML_COMMENT, strndup(start + 2, end - start - 3), indent_level);

            // Update the start pointer.
            start = end + 1;
        }
        // Otherwise, it's just content.
        else {
            // Find the end of the content.
            end++;
            while (*end != '<' && *end != '-' && *end != '\0') {
                end++;
            }

            // Add the content as an element.
            html_document_add_element(document, HTML_CONTENT, strndup(start, end - start), indent_level);

            // Update the start pointer.
            start = end;
        }

        // Advance the end pointer.
        end++;
    }

    // If there's any remaining content, add it as an element.
    if (start != html) {
        html_document_add_element(document, HTML_CONTENT, strndup(start, end - start), indent_level);
    }

    return document;
}

// The main function.
int main(int argc, char **argv) {
    // Check if the user provided an input file.
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Read the HTML from the input file.
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);

    char *html = malloc(file_size + 1);
    fread(html, 1, file_size, input_file);
    fclose(input_file);

    // Parse the HTML document.
    HTML_DOCUMENT *document = html_document_parse(html);
    free(html);

    // Beautify the HTML document.
    html_document_beautify(document);

    // Free the memory associated with the HTML document.
    html_document_free(document);

    return 0;
}