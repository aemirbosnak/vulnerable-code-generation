//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
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

HTMLDocument *parse_html(char *html) {
    HTMLDocument *document = malloc(sizeof(HTMLDocument));
    document->lines = malloc(sizeof(Line) * MAX_LINE_LENGTH);
    document->num_lines = 0;

    char *line_start = html;
    char *line_end;
    while ((line_end = strchr(line_start, '\n')) != NULL) {
        document->lines[document->num_lines].content = line_start;
        document->lines[document->num_lines].length = line_end - line_start;
        document->num_lines++;
        line_start = line_end + 1;
    }

    return document;
}

void beautify_html(HTMLDocument *document) {
    for (int i = 0; i < document->num_lines; i++) {
        Line *line = &document->lines[i];

        // Indent the line if it starts with a tag.
        if (line->content[0] == '<') {
            for (int j = 0; j < i; j++) {
                printf("  ");
            }
        }

        // Print the line.
        printf("%s\n", line->content);
    }
}

int main() {
    // Read the HTML from a file.
    FILE *fp = fopen("input.html", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *html = malloc(file_size + 1);
    fread(html, 1, file_size, fp);
    fclose(fp);

    // Parse the HTML.
    HTMLDocument *document = parse_html(html);

    // Beautify the HTML.
    beautify_html(document);

    // Free the memory.
    free(html);
    free(document->lines);
    free(document);

    return EXIT_SUCCESS;
}