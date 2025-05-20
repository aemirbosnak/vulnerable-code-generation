//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
    // Allocate memory for the beautified HTML code
    char *beautified_html = malloc(strlen(html) * 2);

    // Index of the current character in the beautified HTML code
    int beautified_index = 0;

    // Index of the current character in the original HTML code
    int html_index = 0;

    // Indentation level
    int indentation_level = 0;

    // Loop through each character in the original HTML code
    while (html[html_index] != '\0') {
        // Get the current character
        char c = html[html_index];

        // Handle special characters
        switch (c) {
            case '<':
                // Start a new line and indent the code
                beautified_html[beautified_index++] = '\n';
                for (int i = 0; i < indentation_level; i++) {
                    beautified_html[beautified_index++] = ' ';
                }
                // Copy the opening angle bracket
                beautified_html[beautified_index++] = c;
                // Increment the indentation level
                indentation_level++;
                break;
            case '>':
                // Copy the closing angle bracket
                beautified_html[beautified_index++] = c;
                // Decrement the indentation level
                indentation_level--;
                break;
            case '\n':
                // Ignore newlines
                break;
            default:
                // Copy the character
                beautified_html[beautified_index++] = c;
        }

        // Increment the index of the current character in the original HTML code
        html_index++;
    }

    // Null-terminate the beautified HTML code
    beautified_html[beautified_index] = '\0';

    // Return the beautified HTML code
    return beautified_html;
}

// Main function
int main() {
    // Get the HTML code from the user
    char *html = malloc(1024);
    printf("Enter HTML code: ");
    scanf("%s", html);

    // Beautify the HTML code
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML code
    printf("\nBeautified HTML code:\n");
    printf("%s\n", beautified_html);

    // Free the allocated memory
    free(html);
    free(beautified_html);

    return 0;
}