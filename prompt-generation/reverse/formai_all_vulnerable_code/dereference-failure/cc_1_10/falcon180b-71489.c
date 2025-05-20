//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_INDENT_LEVEL 10
#define INDENT_SPACES "    "

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
    int indent_level;
} Document;

void add_line(Document *doc, const char *text) {
    int length = strlen(text);
    Line *line = malloc(sizeof(Line));
    line->text = text;
    line->length = length;
    doc->lines = realloc(doc->lines, sizeof(Line) * (doc->num_lines + 1));
    doc->lines[doc->num_lines] = *line;
    doc->num_lines++;
}

void indent(Document *doc) {
    doc->indent_level++;
}

void unindent(Document *doc) {
    if (doc->indent_level > 0) {
        doc->indent_level--;
    }
}

void print_line(Document *doc, int index) {
    int indent_spaces = doc->indent_level * strlen(INDENT_SPACES);
    printf("%*s%s\n", indent_spaces, "", doc->lines[index].text);
}

void print_document(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        print_line(doc, i);
    }
}

int main() {
    Document doc;
    doc.lines = NULL;
    doc.num_lines = 0;
    doc.indent_level = 0;

    add_line(&doc, "<html>");
    indent(&doc);
    add_line(&doc, "<head>");
    indent(&doc);
    add_line(&doc, "<title>Hello World</title>");
    unindent(&doc);
    unindent(&doc);

    add_line(&doc, "<body>");
    indent(&doc);
    add_line(&doc, "<h1>Hello World</h1>");
    unindent(&doc);

    add_line(&doc, "</body>");
    unindent(&doc);
    add_line(&doc, "</html>");

    print_document(&doc);

    free(doc.lines);
    return 0;
}