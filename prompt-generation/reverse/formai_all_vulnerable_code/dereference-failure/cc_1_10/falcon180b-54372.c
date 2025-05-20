//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    char *html;
} Line;

char *escape_html(char *text) {
    char *html = malloc(strlen(text) * 2 + 1);
    if (html == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    char *ptr = html;
    while (*text!= '\0') {
        if (*text == '&') {
            strcpy(ptr, "&amp;");
            ptr += 5;
        } else if (*text == '<') {
            strcpy(ptr, "&lt;");
            ptr += 4;
        } else if (*text == '>') {
            strcpy(ptr, "&gt;");
            ptr += 4;
        } else if (*text == '"') {
            strcpy(ptr, "&quot;");
            ptr += 6;
        } else {
            *ptr++ = *text;
        }
        text++;
    }
    *ptr = '\0';
    return html;
}

void print_line(Line *line) {
    printf("<p>%s</p>\n", line->html);
}

int main(int argc, char *argv[]) {
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        return 1;
    }
    Line *lines = malloc(MAX_LINE_LENGTH * sizeof(Line));
    if (lines == NULL) {
        printf("Error: Out of memory\n");
        fclose(input_file);
        return 1;
    }
    int line_count = 0;
    while (fgets(lines[line_count].text, MAX_LINE_LENGTH, input_file)!= NULL) {
        lines[line_count].html = escape_html(lines[line_count].text);
        line_count++;
    }
    fclose(input_file);
    for (int i = 0; i < line_count; i++) {
        print_line(&lines[i]);
    }
    free(lines);
    return 0;
}