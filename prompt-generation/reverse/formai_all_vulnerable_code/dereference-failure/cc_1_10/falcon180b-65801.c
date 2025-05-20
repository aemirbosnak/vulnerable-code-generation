//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line **lines;
    int count;
} Document;

Line *create_line(char *text) {
    Line *line = (Line *)malloc(sizeof(Line));
    line->text = text;
    line->length = strlen(text);
    return line;
}

void add_line(Document *doc, Line *line) {
    doc->lines = (Line **)realloc(doc->lines, sizeof(Line *) * (doc->count + 1));
    doc->lines[doc->count] = line;
    doc->count++;
}

void print_line(Line *line, int indent) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("%s", line->text);
}

void print_document(Document *doc, int indent) {
    for (int i = 0; i < doc->count; i++) {
        print_line(doc->lines[i], indent);
        printf("\n");
    }
}

int main() {
    FILE *input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char line_buffer[MAX_LINE_LENGTH];
    Document doc = {NULL, 0};

    while (fgets(line_buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        Line *line = create_line(line_buffer);
        add_line(&doc, line);
    }

    fclose(input_file);

    int indent_level = 0;
    for (int i = 0; i < doc.count; i++) {
        if (strncmp(doc.lines[i]->text, "<", 1) == 0) {
            indent_level++;
        } else if (strncmp(doc.lines[i]->text, "</", 2) == 0) {
            indent_level--;
        }

        if (indent_level > 0) {
            print_line(doc.lines[i], indent_level * 4);
        }
    }

    return 0;
}