//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
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

HTMLDocument *parse_html_document(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    HTMLDocument *document = malloc(sizeof(HTMLDocument));
    if (document == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    document->lines = NULL;
    document->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        Line *new_line = malloc(sizeof(Line));
        if (new_line == NULL) {
            perror("malloc");
            fclose(fp);
            free(document);
            return NULL;
        }

        new_line->length = strlen(line);
        new_line->line = malloc(new_line->length + 1);
        if (new_line->line == NULL) {
            perror("malloc");
            fclose(fp);
            free(document);
            free(new_line);
            return NULL;
        }

        strcpy(new_line->line, line);

        document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(Line));
        if (document->lines == NULL) {
            perror("realloc");
            fclose(fp);
            free(document);
            free(new_line);
            return NULL;
        }

        document->lines[document->num_lines++] = *new_line;
        free(new_line);
    }

    fclose(fp);

    return document;
}

void beautify_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        Line *line = &document->lines[i];

        // Trim leading whitespace
        while (*line->line == ' ' || *line->line == '\t') {
            line->line++;
            line->length--;
        }

        // Trim trailing whitespace
        while (line->length > 0 && (line->line[line->length - 1] == ' ' || line->line[line->length - 1] == '\t')) {
            line->line[line->length - 1] = '\0';
            line->length--;
        }

        // Indent lines that start with certain tags
        if (strncmp(line->line, "<html>", 6) == 0 || strncmp(line->line, "<head>", 6) == 0 || strncmp(line->line, "<body>", 6) == 0) {
            line->line = realloc(line->line, line->length + 3);
            if (line->line == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }

            memmove(line->line + 3, line->line, line->length + 1);
            line->line[0] = ' ';
            line->line[1] = ' ';
            line->line[2] = ' ';
            line->length += 3;
        }
    }
}

void print_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        Line *line = &document->lines[i];
        printf("%s", line->line);
    }
}

void free_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].line);
    }

    free(document->lines);
    free(document);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    HTMLDocument *document = parse_html_document(argv[1]);
    if (document == NULL) {
        fprintf(stderr, "Error parsing HTML document\n");
        return EXIT_FAILURE;
    }

    beautify_html_document(document);

    print_html_document(document);

    free_html_document(document);

    return EXIT_SUCCESS;
}