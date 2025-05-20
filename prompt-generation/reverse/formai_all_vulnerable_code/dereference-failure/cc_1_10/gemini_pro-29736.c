//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Structure to store a line of HTML code.
typedef struct {
    char *line;
    int length;
} Line;

// Function to compare two lines of HTML code.
int compare_lines(const void *a, const void *b) {
    Line *line1 = (Line *)a;
    Line *line2 = (Line *)b;

    return line1->length - line2->length;
}

// Function to beautify a line of HTML code.
char *beautify_line(char *line) {
    char *new_line = malloc(strlen(line) * 2 + 1);
    int new_line_index = 0;

    for (int i = 0; i < strlen(line); i++) {
        char character = line[i];

        if (character == '<') {
            new_line[new_line_index++] = character;
            i++;
            while (i < strlen(line) && line[i] != '>') {
                new_line[new_line_index++] = line[i++];
            }
            new_line[new_line_index++] = '>';
        } else if (character == ' ') {
            if (new_line_index > 0 && new_line[new_line_index - 1] != ' ') {
                new_line[new_line_index++] = character;
            }
        } else {
            new_line[new_line_index++] = character;
        }
    }

    new_line[new_line_index] = '\0';

    return new_line;
}

// Function to beautify a string of HTML code.
char *beautify_html(char *html) {
    // Split the HTML code into lines.
    char *lines[MAX_LINE_LENGTH];
    int num_lines = 0;
    char *line = strtok(html, "\n");
    while (line != NULL) {
        lines[num_lines++] = line;
        line = strtok(NULL, "\n");
    }

    // Sort the lines by length.
    qsort(lines, num_lines, sizeof(char *), compare_lines);

    // Beautify each line.
    for (int i = 0; i < num_lines; i++) {
        lines[i] = beautify_line(lines[i]);
    }

    // Join the lines into a single string.
    char *new_html = malloc(strlen(html) * 2 + 1);
    int new_html_index = 0;
    for (int i = 0; i < num_lines; i++) {
        strcat(new_html, lines[i]);
        new_html_index += strlen(lines[i]);
    }
    new_html[new_html_index] = '\0';

    // Free the allocated memory.
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }

    return new_html;
}

// Main function.
int main() {
    // Read the HTML code from the standard input.
    char *html = malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(html, MAX_LINE_LENGTH, stdin);

    // Beautify the HTML code.
    char *new_html = beautify_html(html);

    // Print the beautified HTML code to the standard output.
    printf("%s", new_html);

    // Free the allocated memory.
    free(html);
    free(new_html);

    return 0;
}