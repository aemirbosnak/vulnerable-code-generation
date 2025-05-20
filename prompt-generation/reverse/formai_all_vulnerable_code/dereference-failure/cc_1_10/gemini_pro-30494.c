//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: calm
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
} Document;

Document *
create_document(void)
{
    Document *document = malloc(sizeof(Document));
    if (document == NULL) {
        return NULL;
    }
    document->lines = NULL;
    document->num_lines = 0;
    return document;
}

void
free_document(Document *document)
{
    for (int i = 0; i < document->num_lines; i++) {
        free(document->lines[i].line);
    }
    free(document->lines);
    free(document);
}

int
read_document(Document *document, FILE *fp)
{
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        Line *new_line = malloc(sizeof(Line));
        if (new_line == NULL) {
            return -1;
        }
        new_line->line = strdup(line);
        if (new_line->line == NULL) {
            free(new_line);
            return -1;
        }
        new_line->length = strlen(new_line->line);
        document->lines = realloc(document->lines, sizeof(Line) * (document->num_lines + 1));
        if (document->lines == NULL) {
            free(new_line->line);
            free(new_line);
            return -1;
        }
        document->lines[document->num_lines] = *new_line;
        document->num_lines++;
    }
    return 0;
}

void
beautify_document(Document *document)
{
    for (int i = 0; i < document->num_lines; i++) {
        Line *line = &document->lines[i];
        for (int j = 0; j < line->length; j++) {
            if (line->line[j] == ' ') {
                line->line[j] = '\t';
            }
        }
    }
}

void
print_document(Document *document, FILE *fp)
{
    for (int i = 0; i < document->num_lines; i++) {
        Line *line = &document->lines[i];
        fprintf(fp, "%s", line->line);
    }
}

int
main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    Document *document = create_document();
    if (document == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (read_document(document, fp) != 0) {
        perror("read_document");
        free_document(document);
        return EXIT_FAILURE;
    }

    beautify_document(document);

    print_document(document, stdout);

    free_document(document);

    fclose(fp);

    return EXIT_SUCCESS;
}