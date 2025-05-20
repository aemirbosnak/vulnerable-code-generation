//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
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

HTMLDocument *
html_document_new()
{
	HTMLDocument *doc = malloc(sizeof(HTMLDocument));
	doc->lines = malloc(sizeof(Line) * 10);
	doc->num_lines = 0;
	return doc;
}

void
html_document_free(HTMLDocument *doc)
{
	for (int i = 0; i < doc->num_lines; i++) {
		free(doc->lines[i].line);
	}
	free(doc->lines);
	free(doc);
}

void
html_document_add_line(HTMLDocument *doc, const char *line)
{
	if (doc->num_lines == 10) {
		doc->lines = realloc(doc->lines, sizeof(Line) * (doc->num_lines + 10));
	}
	doc->lines[doc->num_lines].line = strdup(line);
	doc->lines[doc->num_lines].length = strlen(line);
	doc->num_lines++;
}

void
html_document_print(HTMLDocument *doc)
{
	for (int i = 0; i < doc->num_lines; i++) {
		printf("%s", doc->lines[i].line);
	}
}

int
main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
		exit(1);
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror(argv[1]);
		exit(1);
	}

	HTMLDocument *doc = html_document_new();

	char line[MAX_LINE_LENGTH];
	while (fgets(line, MAX_LINE_LENGTH, fp)) {
		html_document_add_line(doc, line);
	}

	fclose(fp);

	html_document_print(doc);

	html_document_free(doc);

	return 0;
}