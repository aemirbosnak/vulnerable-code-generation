//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} HTMLDocument;

HTMLDocument *
parse_html_document(char *text) {
    HTMLDocument *document = malloc(sizeof(HTMLDocument));
    document->lines = NULL;
    document->num_lines = 0;

    char *line_start = text;
    while (*line_start != '\0') {
        char *line_end = strchr(line_start, '\n');
        if (line_end == NULL) {
            line_end = text + strlen(text);
        }

        Line line;
        line.length = line_end - line_start;
        line.text = malloc(line.length + 1);
        memcpy(line.text, line_start, line.length);
        line.text[line.length] = '\0';

        document->lines = realloc(document->lines, (document->num_lines + 1) * sizeof(Line));
        document->lines[document->num_lines] = line;
        document->num_lines++;

        line_start = line_end + 1;
    }

    return document;
}

void
beautify_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        Line *line = &document->lines[i];

        // Indent the line if it contains a start tag.
        if (strstr(line->text, "<") != NULL) {
            for (int j = 0; j < i; j++) {
                printf("    ");
            }
        }

        // Print the line.
        printf("%s", line->text);
    }
}

void
free_html_document(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].text);
    }
    free(document->lines);
    free(document);
}

int
main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <html file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *text = malloc(file_size + 1);
    fread(text, 1, file_size, fp);
    text[file_size] = '\0';

    HTMLDocument *document = parse_html_document(text);
    beautify_html_document(document);
    free_html_document(document);

    fclose(fp);
    free(text);

    return 0;
}