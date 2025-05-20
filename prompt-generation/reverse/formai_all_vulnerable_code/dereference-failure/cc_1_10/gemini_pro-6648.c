//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to beautify HTML code
char *beautify_html(char *html) {
    // Allocate memory for the beautified HTML code
    char *beautified_html = malloc(strlen(html) * 2);

    // Initialize the beautified HTML code
    beautified_html[0] = '\0';

    // Iterate over the HTML code
    for (int i = 0; i < strlen(html); i++) {
        // If the current character is a '<', then it is the start of a tag
        if (html[i] == '<') {
            // Copy the tag to the beautified HTML code
            strcat(beautified_html, "<");

            // Iterate over the tag
            for (int j = i + 1; j < strlen(html); j++) {
                // If the current character is a '>', then it is the end of the tag
                if (html[j] == '>') {
                    // Copy the end of the tag to the beautified HTML code
                    strcat(beautified_html, ">");

                    // Increment the index to the next character after the tag
                    i = j + 1;

                    // Break the loop
                    break;
                }

                // If the current character is a space, then it is a whitespace character
                else if (html[j] == ' ') {
                    // Copy the whitespace character to the beautified HTML code
                    strcat(beautified_html, " ");
                }

                // Otherwise, the current character is a non-whitespace character
                else {
                    // Copy the non-whitespace character to the beautified HTML code
                    strcat(beautified_html, &html[j]);
                }
            }
        }

        // If the current character is not a '<', then it is a non-tag character
        else {
            // Copy the non-tag character to the beautified HTML code
            strcat(beautified_html, &html[i]);
        }
    }

    // Return the beautified HTML code
    return beautified_html;
}

// Main function
int main() {
    // Get the HTML code from the user
    char *html = malloc(1000);
    printf("Enter HTML code: ");
    scanf("%s", html);

    // Beautify the HTML code
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML code
    printf("\nBeautified HTML code:\n%s", beautified_html);

    // Free the allocated memory
    free(html);
    free(beautified_html);

    return 0;
}