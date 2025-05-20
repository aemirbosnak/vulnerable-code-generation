//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: Claude Shannon
// A Claude Shannon-inspired C program to beautify HTML documents.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove whitespace from a string.
char *trim(char *str) {
    char *end;

    // Trim leading whitespace.
    while(*str && isspace(*str)) {
        str++;
    }

    // Trim trailing whitespace.
    end = str + strlen(str) - 1;
    while(end >= str && isspace(*end)) {
        end--;
    }

    // Null-terminate the trimmed string.
    *(end + 1) = '\0';

    return str;
}

// Function to beautify an HTML document.
char *beautify(char *html) {
    char *result = NULL;
    char *token = NULL;
    char *tag = NULL;
    char *attrs = NULL;
    char *value = NULL;
    int indent = 0;

    // Split the HTML document into tokens.
    token = strtok(html, "<>");

    // Iterate over the tokens.
    while(token) {
        // Check if the token is a tag.
        if(*token == '<') {
            // Get the tag name.
            tag = strtok(NULL, " ");

            // Get the attributes.
            attrs = strtok(NULL, ">");

            // Print the opening tag.
            result = strcat(result, "<");
            result = strcat(result, tag);

            // Print the attributes.
            while(attrs) {
                value = strtok(NULL, "=");
                result = strcat(result, " ");
                result = strcat(result, attrs);
                result = strcat(result, "=");
                result = strcat(result, value);
                attrs = strtok(NULL, " ");
            }

            // Print the closing tag.
            result = strcat(result, ">");

            // Indent the subsequent lines.
            indent++;
        } else {
            // Get the text content.
            value = token;

            // Print the text content.
            for(int i = 0; i < indent; i++) {
                result = strcat(result, "  ");
            }
            result = strcat(result, value);
            result = strcat(result, "\n");
        }

        // Get the next token.
        token = strtok(NULL, "<>");
    }

    // Trim the result.
    return trim(result);
}

// Main function.
int main() {
    // Get the HTML document from the user.
    char *html = "<h1>This is a heading</h1><p>This is a paragraph.</p>";

    // Beautify the HTML document.
    char *result = beautify(html);

    // Print the beautified HTML document to the console.
    printf("%s", result);

    return 0;
}