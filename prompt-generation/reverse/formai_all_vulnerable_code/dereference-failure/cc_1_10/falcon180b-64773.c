//Falcon-180B DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
    int line_number;
} Line;

typedef struct {
    Line *lines;
    int count;
} Text;

void add_line(Text *text, const char *line) {
    int length = strlen(line);
    Line *new_line = (Line *) malloc(sizeof(Line));
    new_line->text = (char *) malloc(length + 1);
    strcpy(new_line->text, line);
    new_line->length = length;
    new_line->line_number = text->count;
    text->lines = (Line *) realloc(text->lines, sizeof(Line) * (text->count + 1));
    text->lines[text->count] = *new_line;
    text->count++;
}

void print_text(Text *text) {
    for (int i = 0; i < text->count; i++) {
        printf("%d: %s\n", text->lines[i].line_number, text->lines[i].text);
    }
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    Text text = {0};

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(&text, line);
    }

    fclose(file);

    print_text(&text);

    for (int i = 0; i < text.count; i++) {
        free(text.lines[i].text);
        free(text.lines[i].text);
    }
    free(text.lines);

    return 0;
}