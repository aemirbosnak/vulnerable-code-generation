//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 2

typedef struct {
    char *line;
    int indent_level;
} BeautifiedLine;

void freeBeautifiedLines(BeautifiedLine *lines, int count) {
    for (int i = 0; i < count; i++) {
        free(lines[i].line);
    }
    free(lines);
}

void addIndentation(char **line, int level) {
    char indent[INDENT_SIZE + 1];
    memset(indent, ' ', INDENT_SIZE);
    indent[INDENT_SIZE] = '\0';

    char *indented_line = (char *)malloc(strlen(*line) + (level * INDENT_SIZE) + 1);
    for (int i = 0; i < level; i++) {
        strcat(indented_line, indent);
    }
    strcat(indented_line, *line);

    free(*line);
    *line = indented_line;
}

int isOpenTag(const char *line) {
    return strstr(line, "<") && !strstr(line, "</");
}

int isCloseTag(const char *line) {
    return strstr(line, "</");
}

int main() {
    printf("Welcome to the Great HTML Beautifier, where your messy code becomes as pretty as a cat meme!\n\n");
    
    char line[MAX_LINE_LENGTH];
    BeautifiedLine *lines = (BeautifiedLine *)malloc(sizeof(BeautifiedLine) * MAX_LINE_LENGTH);
    int count = 0, indent_level = 0;

    printf("Please paste your messy HTML code below (EOF to finish):\n");

    while (fgets(line, sizeof(line), stdin)) {
        // Strip any newlines
        line[strcspn(line, "\n")] = 0;

        if (count >= MAX_LINE_LENGTH) {
            printf("Uh-oh! Too much code! Let's keep it a bit more tidy, shall we?\n");
            break;
        }

        lines[count].line = strdup(line); // Duplicate line
        lines[count].indent_level = indent_level;

        if (isOpenTag(line)) {
            indent_level++;
        } else if (isCloseTag(line)) {
            indent_level = indent_level > 0 ? indent_level - 1 : 0;
        }

        count++;
    }

    printf("\nHold on to your hats, we’re beautifying your code...\n");

    for (int i = 0; i < count; i++) {
        addIndentation(&lines[i].line, lines[i].indent_level);
    }

    printf("\nHere’s your new and improved HTML code! 🌈✨\n");
    
    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i].line);
    }

    freeBeautifiedLines(lines, count);
    printf("And that’s how we turn code chaos into order. Go forth and beautify your web pages! 🕸️💅\n");
    
    return 0;
}