//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: excited
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

void add_line(Document *doc, char *line) {
    doc->num_lines++;
    doc->lines = realloc(doc->lines, sizeof(Line) * doc->num_lines);
    doc->lines[doc->num_lines - 1].line = line;
    doc->lines[doc->num_lines - 1].length = strlen(line);
}

void print_document(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        printf("%s", doc->lines[i].line);
    }
}

void free_document(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i].line);
    }
    free(doc->lines);
}

int main() {
    FILE *file = fopen("example.html", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Document doc = {0};
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(&doc, line);
    }

    fclose(file);

    printf("Original:\n");
    print_document(&doc);

    printf("\nBeautified:\n");
    for (int i = 0; i < doc.num_lines; i++) {
        printf("%s\n", doc.lines[i].line);
    }

    free_document(&doc);

    return 0;
}