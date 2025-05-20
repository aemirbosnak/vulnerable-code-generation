//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
} html_document_t;

html_document_t *html_document_new() {
    html_document_t *document = (html_document_t *)malloc(sizeof(html_document_t));
    document->lines = NULL;
    document->num_lines = 0;
    return document;
}

void html_document_free(html_document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].line);
    }
    free(document->lines);
    free(document);
}

int html_document_load_from_file(html_document_t *document, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line_t line_struct;
        line_struct.line = strdup(line);
        line_struct.length = strlen(line);

        document->lines = (line_t *)realloc(document->lines, (document->num_lines + 1) * sizeof(line_t));
        document->lines[document->num_lines] = line_struct;
        document->num_lines++;
    }

    fclose(file);
    return 0;
}

void html_document_beautify(html_document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        char *line = document->lines[i].line;
        int length = document->lines[i].length;

        // Remove leading whitespace
        int j = 0;
        while (j < length && isspace(line[j])) {
            j++;
        }
        memmove(line, line + j, length - j + 1);
        length -= j;

        // Remove trailing whitespace
        j = length - 1;
        while (j >= 0 && isspace(line[j])) {
            j--;
        }
        line[j + 1] = '\0';
        length = j + 1;

        // Indent lines that start with certain tags
        if (length >= 2 && line[0] == '<' && (line[1] == 'h' || line[1] == 'p' || line[1] == 'u' || line[1] == 'o' || line[1] == 'l')) {
            for (int k = 0; k < i; k++) {
                if (document->lines[k].line[0] == '<' && document->lines[k].line[1] == '/') {
                    break;
                }
                line_t *prev_line = &document->lines[k];
                prev_line->line = (char *)realloc(prev_line->line, prev_line->length + 4);
                memmove(prev_line->line + 4, prev_line->line, prev_line->length + 1);
                prev_line->line[0] = ' ';
                prev_line->line[1] = ' ';
                prev_line->line[2] = ' ';
                prev_line->line[3] = ' ';
                prev_line->length += 4;
            }
        }
    }
}

void html_document_print(html_document_t *document) {
    for (int i = 0; i < document->num_lines; i++) {
        printf("%s", document->lines[i].line);
    }
}

int main() {
    html_document_t *document = html_document_new();
    if (html_document_load_from_file(document, "input.html") == 0) {
        html_document_beautify(document);
        html_document_print(document);
    }
    html_document_free(document);
    return 0;
}