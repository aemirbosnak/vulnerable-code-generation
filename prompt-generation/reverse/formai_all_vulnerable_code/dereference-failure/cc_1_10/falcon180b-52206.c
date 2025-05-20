//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: standalone
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
} Text;

void add_line(Text *text, const char *line) {
    Line *new_line = (Line *)malloc(sizeof(Line));
    new_line->text = strdup(line);
    new_line->length = strlen(line);
    text->lines = (Line *)realloc(text->lines, sizeof(Line) * (text->num_lines + 1));
    text->lines[text->num_lines] = *new_line;
    text->num_lines++;
}

void print_text(Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        printf("%s", text->lines[i].text);
    }
}

void free_text(Text *text) {
    for (int i = 0; i < text->num_lines; i++) {
        free(text->lines[i].text);
    }
    free(text->lines);
}

int main(int argc, char **argv) {
    FILE *file = fopen(argv[1], "r");
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

    printf("Original text:\n");
    print_text(&text);

    printf("\nHTML-formatted text:\n");
    for (int i = 0; i < text.num_lines; i++) {
        char *html_line = (char *)malloc(text.lines[i].length * 2 + 1);
        for (int j = 0; j < text.lines[i].length; j++) {
            char c = tolower(text.lines[i].text[j]);
            if (c == '<') {
                strcat(html_line, "&lt;");
            } else if (c == '>') {
                strcat(html_line, "&gt;");
            } else if (c == '&') {
                strcat(html_line, "&amp;");
            } else {
                strcat(html_line, &c);
            }
        }
        printf("%s\n", html_line);
        free(html_line);
    }

    free_text(&text);

    return 0;
}