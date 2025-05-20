//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **lines;
    int num_lines;
    int max_line_length;
    int indent_level;
} html_document;

html_document *new_html_document() {
    html_document *doc = malloc(sizeof(html_document));
    doc->lines = NULL;
    doc->num_lines = 0;
    doc->max_line_length = 0;
    doc->indent_level = 0;
    return doc;
}

void free_html_document(html_document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i]);
    }
    free(doc->lines);
    free(doc);
}

void append_line(html_document *doc, char *line) {
    doc->lines = realloc(doc->lines, (doc->num_lines + 1) * sizeof(char *));
    doc->lines[doc->num_lines] = strdup(line);
    doc->num_lines++;
    doc->max_line_length = fmax(doc->max_line_length, strlen(line));
}

void indent(html_document *doc, int level) {
    for (int i = 0; i < level; i++) {
        append_line(doc, "    ");
    }
}

void beautify_html(html_document *doc) {
    int in_tag = 0;
    int in_comment = 0;
    int in_cdata = 0;
    for (int i = 0; i < doc->num_lines; i++) {
        char *line = doc->lines[i];
        if (in_comment) {
            if (strstr(line, "-->")) {
                in_comment = 0;
            }
        } else if (in_cdata) {
            if (strstr(line, "]]>")) {
                in_cdata = 0;
            }
        } else if (strstr(line, "<!--")) {
            in_comment = 1;
        } else if (strstr(line, "<![CDATA[")) {
            in_cdata = 1;
        } else if (strstr(line, "<")) {
            in_tag = 1;
            indent(doc, doc->indent_level);
            append_line(doc, line);
            doc->indent_level++;
        } else if (strstr(line, ">")) {
            in_tag = 0;
            doc->indent_level--;
            append_line(doc, line);
        } else {
            if (!in_tag) {
               indent(doc, doc->indent_level);
            }
            append_line(doc, line);
        }
    }
}

void print_html_document(html_document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        printf("%s\n", doc->lines[i]);
    }
}

int main() {
    html_document *doc = new_html_document();
    append_line(doc, "<html>");
    append_line(doc, "<head>");
    append_line(doc, "<title>My Awesome Website</title>");
    append_line(doc, "</head>");
    append_line(doc, "<body>");
    append_line(doc, "<h1>Hello, world!</h1>");
    append_line(doc, "<p>This is my awesome website.</p>");
    append_line(doc, "</body>");
    append_line(doc, "</html>");
    beautify_html(doc);
    print_html_document(doc);
    free_html_document(doc);
    return 0;
}