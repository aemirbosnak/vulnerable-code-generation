//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
    // Allocate memory for the beautified HTML
    char *beautified_html = malloc(strlen(html) * 2);
    if (beautified_html == NULL) {
        perror("malloc");
        exit(1);
    }

    // Initialize the index of the beautified HTML
    int index = 0;

    // Loop through each character in the HTML
    for (int i = 0; i < strlen(html); i++) {
        // If the current character is a newline, add two newlines to the beautified HTML
        if (html[i] == '\n') {
            beautified_html[index++] = '\n';
            beautified_html[index++] = '\n';
        }
        // If the current character is a whitespace character, add a single space to the beautified HTML
        else if (isspace(html[i])) {
            beautified_html[index++] = ' ';
        }
        // Otherwise, add the current character to the beautified HTML
        else {
            beautified_html[index++] = html[i];
        }
    }

    // Terminate the beautified HTML
    beautified_html[index] = '\0';

    // Return the beautified HTML
    return beautified_html;
}

// Main function
int main() {
    // Get the HTML code from the user
    char *html = malloc(1024);
    if (html == NULL) {
        perror("malloc");
        exit(1);
    }
    printf("Enter the HTML code:\n");
    fgets(html, 1024, stdin);

    // Beautify the HTML code
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML
    printf("Beautified HTML:\n%s", beautified_html);

    // Free the allocated memory
    free(html);
    free(beautified_html);

    return 0;
}