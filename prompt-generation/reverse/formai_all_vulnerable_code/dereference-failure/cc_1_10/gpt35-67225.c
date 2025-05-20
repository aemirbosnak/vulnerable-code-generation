//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SPACES 2 // Number of spaces for indention

void html_beautifier(char *html) {
    char *indent = malloc(INDENT_SPACES + 1); // Allocate memory for the indention string
    memset(indent, ' ', INDENT_SPACES); // Initialize indention string with spaces
    indent[INDENT_SPACES] = '\0'; // Add null terminator to the indention string

    int nesting_level = 0; // Initialize nesting level to zero (no indention needed)
    int i = 0, j = 0; // Loop counters
    while (html[i]) { // While there are characters in the HTML string
        if (html[i] == '<') { // If the current character is the start of an HTML tag
            if (html[i + 1] == '/') { // If the tag is a closing tag
                nesting_level--; // Decrease nesting level
            }
            for (j = 0; j < nesting_level * INDENT_SPACES; j++) { // Add the corresponding indention for the current nesting level
                putchar(' '); // Output a space
            }
            printf("%c", html[i]); // Output the '<' character
            i++; // Move to the next character
            while (html[i] && html[i] != '>') { // Output the tag name
                printf("%c", html[i]);
                i++;
            }
            if (html[i] && html[i] == '>') { // If the tag has attributes
                printf("%c", html[i]); // Output the closing '>'
                i++;
            }
            if (!html[i] || html[i - 1] != '/') { // If the tag is not a self-closing tag
                nesting_level++; // Increase nesting level
            }
            putchar('\n'); // Add a newline character
        } else { // If the current character is not the start of an HTML tag
            putchar(html[i]); // Output the current character
            if (html[i] == '>') { // If the current character ends an HTML tag
                putchar('\n'); // Add a newline character
            }
            i++; // Move to the next character
        }
    }

    free(indent); // Free dynamically allocated memory
}

int main() {
    char *html = "<html><head><title>Sample Page</title></head><body><h1>Welcome to my page!</h1><p>This is a sample page.</p></body></html>";

    printf("Before beautifying:\n%s\n\n", html); // Output the unformatted HTML string

    html_beautifier(html); // Beautify the HTML string

    printf("\nAfter beautifying:\n%s\n", html); // Output the beautified HTML string

    return 0;
}