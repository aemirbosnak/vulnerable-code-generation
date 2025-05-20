//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: secure
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *line;
    int length;
    int capacity;
} line_t;

typedef struct {
    line_t *lines;
    int count;
    int capacity;
} document_t;

void document_init(document_t *document) {
    document->lines = NULL;
    document->count = 0;
    document->capacity = 0;
}

void document_free(document_t *document) {
    for (int i = 0; i < document->count; i++) {
        free(document->lines[i].line);
    }
    free(document->lines);
}

int document_add_line(document_t *document, const char *line) {
    if (document->count >= document->capacity) {
        document->capacity = document->capacity == 0 ? 1 : document->capacity * 2;
        document->lines = realloc(document->lines, sizeof(line_t) * document->capacity);
    }

    document->lines[document->count].line = strdup(line);
    document->lines[document->count].length = strlen(line);
    document->lines[document->count].capacity = document->lines[document->count].length + 1;

    document->count++;

    return 0;
}

void document_beautify(document_t *document) {
    for (int i = 0; i < document->count; i++) {
        line_t *line = &document->lines[i];

        // Remove leading and trailing whitespace
        while (line->length > 0 && isspace(line->line[line->length - 1])) {
            line->line[line->length - 1] = '\0';
            line->length--;
        }

        while (line->length > 0 && isspace(line->line[0])) {
            line->line++;
            line->length--;
        }

        // Indent the line
        for (int j = 0; j < line->length; j++) {
            if (line->line[j] == '<') {
                line->line[j] = '\n';
                for (int k = 0; k < 4; k++) {
                    line->line[j + k + 1] = ' ';
                }
                line->length += 4;
            }
        }
    }
}

void document_print(document_t *document) {
    for (int i = 0; i < document->count; i++) {
        printf("%s\n", document->lines[i].line);
    }
}

int main() {
    document_t document;
    document_init(&document);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        document_add_line(&document, line);
    }

    document_beautify(&document);
    document_print(&document);

    document_free(&document);

    return 0;
}