//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
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

HTMLDocument *read_html_document(FILE *fp) {
    HTMLDocument *doc = malloc(sizeof(HTMLDocument));
    doc->lines = NULL;
    doc->num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        int length = strlen(line);
        while (length > 0 && (line[length - 1] == '\n' || line[length - 1] == '\r')) {
            length--;
        }

        doc->lines = realloc(doc->lines, (doc->num_lines + 1) * sizeof(Line));
        doc->lines[doc->num_lines].line = malloc(length + 1);
        memcpy(doc->lines[doc->num_lines].line, line, length);
        doc->lines[doc->num_lines].line[length] = '\0';
        doc->num_lines++;
    }

    return doc;
}

void free_html_document(HTMLDocument *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i].line);
    }
    free(doc->lines);
    free(doc);
}

void print_html_document(HTMLDocument *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        printf("%s\n", doc->lines[i].line);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    HTMLDocument *doc = read_html_document(fp);
    fclose(fp);

    print_html_document(doc);
    free_html_document(doc);

    return 0;
}