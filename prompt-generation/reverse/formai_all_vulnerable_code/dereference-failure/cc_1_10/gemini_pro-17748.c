//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove leading and trailing whitespace from a string
char *trim(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;

    // Trim leading whitespace
    while (start != end && isspace(*start)) {
        start++;
    }

    // Trim trailing whitespace
    while (end != start && isspace(*end)) {
        end--;
    }

    // Null-terminate the trimmed string
    *++end = '\0';

    return start;
}

// Function to beautify HTML code
char *beautify_html(char *html) {
    // Allocate memory for the beautified HTML code
    char *beautified_html = malloc(strlen(html) * 2);
    if (beautified_html == NULL) {
        return NULL;
    }

    // Initialize the beautified HTML code
    strcpy(beautified_html, "");

    // Split the HTML code into lines
    char *lines[1000];
    int num_lines = 0;
    char *line = strtok(html, "\n");
    while (line != NULL) {
        lines[num_lines++] = line;
        line = strtok(NULL, "\n");
    }

    // Beautify each line of HTML code
    for (int i = 0; i < num_lines; i++) {
        // Trim leading and trailing whitespace from the line
        char *trimmed_line = trim(lines[i]);

        // Indent the line according to its level of nesting
        int level = 0;
        for (int j = 0; j < strlen(trimmed_line); j++) {
            if (trimmed_line[j] == '<') {
                level++;
            } else if (trimmed_line[j] == '>') {
                level--;
            }
        }
        for (int j = 0; j < level; j++) {
            strcat(beautified_html, "  ");
        }

        // Add the trimmed line to the beautified HTML code
        strcat(beautified_html, trimmed_line);
        strcat(beautified_html, "\n");
    }

    // Return the beautified HTML code
    return beautified_html;
}

// Main function
int main() {
    // Get the HTML code from the user
    char html[10000];
    printf("Enter HTML code:\n");
    scanf("%s", html);

    // Beautify the HTML code
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML code
    printf("\nBeautified HTML code:\n%s", beautified_html);

    // Free the memory allocated for the beautified HTML code
    free(beautified_html);

    return 0;
}