//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

typedef enum { false, true } bool;

// Function to trim whitespace from a string
char *trim_whitespace(char *str) {
    char *end;

    while (isspace(*str)) str++;
    if (*str == 0) return str;

    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    *(end + 1) = 0;

    return str;
}

// Function to beautify HTML string
char *beautify_html(const char *html) {
    bool in_tag = false, in_quotes = false;
    int indent_level = 0;
    char *result = malloc(BUFFER_SIZE);
    char *output = result;
    int len = strlen(html);
    
    for (int i = 0; i < len; i++) {
        char current = html[i];
        char next = (i + 1 < len) ? html[i + 1] : 0;

        // Detect if we're entering or exiting a tag
        if (current == '<') {
            if (i > 0 && output != result && *(output - 1) != '\n') {
                *output++ = '\n';
            }
            in_tag = true;
            indent_level += 1;
            for (int j = 0; j < indent_level; j++) {
                *output++ = '\t'; // Add indentation
            }
        }

        // Detect if we're exiting a tag
        if (current == '>') {
            in_tag = false;
            indent_level -= (next == '<') ? 1 : 0;
            *output++ = current;

            if (next != '<' && next != '=') {
                *output++ = '\n';
                for (int j = 0; j < indent_level; j++) {
                    *output++ = '\t'; // Add indentation after ending the tag
                }
            }
            continue;
        }

        // Toggle in_quotes state on quotes
        if (current == '"' || current == '\'') {
            in_quotes = !in_quotes;
        }
        
        // Apply behavior for tags and non-tags
        if (in_tag || in_quotes) {
            *output++ = current;
        } else {
            // Insert a space before a non-HTML character after an HTML character
            if (isspace(current)) {
                if (output > result && *(output - 1) != ' ') {
                    *output++ = ' ';
                }
            } else {
                *output++ = current;
            }
        }
    }
    
    *output = '\0'; // Null terminate the output string
    return result;
}

// Main function to read and beautify an HTML file
int main() {
    FILE *file;
    char *filename = "example.html";
    char html_content[BUFFER_SIZE];

    // Open the HTML file
    file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read file content
    fread(html_content, 1, BUFFER_SIZE, file);
    fclose(file);

    // Beautify the HTML content
    char *beautified_html = beautify_html(html_content);

    // Print the beautified HTML to standard output
    printf("%s\n", beautified_html);

    // Free the allocated memory
    free(beautified_html);
    return 0;
}