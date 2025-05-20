//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations of beautification functions
void beautify_tags(char *html);
void beautify_attributes(char *html);
void beautify_indentation(char *html);
void beautify_newlines(char *html);

// Main function
int main() {
    // Read the HTML code from the standard input
    char *html = NULL;
    size_t len = 0;
    getline(&html, &len, stdin);

    // Beautify the HTML code
    beautify_tags(html);
    beautify_attributes(html);
    beautify_indentation(html);
    beautify_newlines(html);

    // Print the beautified HTML code to the standard output
    printf("%s", html);

    // Free the allocated memory
    free(html);

    return 0;
}

// Beautify tags by adding spaces around them
void beautify_tags(char *html) {
    int i = 0;
    while (html[i] != '\0') {
        if (html[i] == '<') {
            // Move the current character to the right
            memmove(html + i + 1, html + i, strlen(html + i) + 1);
            html[i] = ' ';
            i++;
        } else if (html[i] == '>') {
            // Move the current character to the left
            memmove(html + i - 1, html + i, strlen(html + i) + 1);
            html[i] = ' ';
            i++;
        }
        i++;
    }
}

// Beautify attributes by adding quotes around them
void beautify_attributes(char *html) {
    int i = 0;
    while (html[i] != '\0') {
        if (html[i] == '=') {
            // Move the current character to the right
            memmove(html + i + 1, html + i, strlen(html + i) + 1);
            html[i] = '"';
            i++;
        } else if (html[i] == ' ' && html[i + 1] != '"') {
            // Move the current character to the left
            memmove(html + i - 1, html + i, strlen(html + i) + 1);
            html[i] = '"';
            i++;
        }
        i++;
    }
}

// Beautify indentation by adding two spaces before each new line
void beautify_indentation(char *html) {
    int i = 0;
    while (html[i] != '\0') {
        if (html[i] == '\n') {
            // Move the current character to the right
            memmove(html + i + 2, html + i, strlen(html + i) + 1);
            html[i] = ' ';
            html[i + 1] = ' ';
            i++;
        }
        i++;
    }
}

// Beautify newlines by adding a newline after each closing tag
void beautify_newlines(char *html) {
    int i = 0;
    while (html[i] != '\0') {
        if (html[i] == '>' && html[i + 1] != '\n') {
            // Move the current character to the right
            memmove(html + i + 1, html + i, strlen(html + i) + 1);
            html[i] = '\n';
            i++;
        }
        i++;
    }
}