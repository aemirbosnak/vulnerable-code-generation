//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: detailed
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
    int count;
} Document;

Document *create_document() {
    Document *doc = (Document *)malloc(sizeof(Document));
    doc->lines = (Line *)malloc(sizeof(Line));
    doc->count = 1;
    doc->lines[0].text = (char *)malloc(sizeof(char) * MAX_LINE_LENGTH);
    doc->lines[0].length = 0;
    return doc;
}

void append_line(Document *doc, char *text) {
    if (doc->count == MAX_LINE_LENGTH) {
        Line *tmp = (Line *)malloc(sizeof(Line));
        tmp->text = (char *)malloc(sizeof(char) * MAX_LINE_LENGTH);
        strcpy(tmp->text, doc->lines[doc->count-1].text);
        doc->lines[doc->count-1].text = tmp->text;
        doc->lines[doc->count-1].length = 0;
        doc->lines = (Line *)realloc(doc->lines, sizeof(Line) * (doc->count+1));
        doc->lines[doc->count-1].text = (char *)realloc(doc->lines[doc->count-1].text, sizeof(char) * MAX_LINE_LENGTH);
        doc->count++;
    }
    strcat(doc->lines[doc->count-1].text, text);
    doc->lines[doc->count-1].length += strlen(text);
}

void print_document(Document *doc) {
    for (int i = 0; i < doc->count; i++) {
        printf("%s", doc->lines[i].text);
    }
}

int main() {
    Document *doc = create_document();
    char *html_text = "<html>\n<head>\n<title>Hello, world!</title>\n</head>\n<body>\n<h1>Hello, world!</h1>\n<p>This is a test.</p>\n</body>\n</html>";
    char *line = strtok(html_text, "\n");
    while (line!= NULL) {
        append_line(doc, line);
        line = strtok(NULL, "\n");
    }
    print_document(doc);
    return 0;
}