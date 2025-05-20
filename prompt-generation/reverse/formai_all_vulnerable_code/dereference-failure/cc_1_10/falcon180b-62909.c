//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Document;

Document *create_document() {
    Document *doc = malloc(sizeof(Document));
    doc->lines = NULL;
    doc->num_lines = 0;
    return doc;
}

void free_document(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i].text);
    }
    free(doc->lines);
    free(doc);
}

void add_line(Document *doc, char *text) {
    Line *line = malloc(sizeof(Line));
    line->text = strdup(text);
    line->length = strlen(text);
    doc->lines = realloc(doc->lines, sizeof(Line) * (doc->num_lines + 1));
    doc->lines[doc->num_lines] = *line;
    doc->num_lines++;
}

void print_document(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        printf("%s\n", doc->lines[i].text);
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    Document *doc = create_document();

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        if (strlen(buffer) == 0 || buffer[0] == '<') {
            add_line(doc, buffer);
        } else {
            int j = 0;
            for (int i = 0; i < strlen(buffer); i++) {
                if (isspace(buffer[i])) {
                    if (j >= MAX_LINE_LENGTH) {
                        add_line(doc, strndup(buffer, i));
                        j = 0;
                    } else {
                        j++;
                    }
                } else {
                    j++;
                }
            }
            add_line(doc, strndup(buffer, strlen(buffer)));
        }
    }

    fclose(input_file);

    print_document(doc);

    free_document(doc);

    return 0;
}