//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define INDENT_SIZE 4

void beautify_html(const char* input, char* output) {
    int indent_level = 0;
    int output_index = 0;
    int in_tag = 0;
    
    for (int i = 0; i < strlen(input); i++) {
        char ch = input[i];
        switch (ch) {
            case '<':
                // Open tag found
                if (i + 1 < strlen(input) && input[i + 1] == '/') {
                    // Close tag
                    indent_level--;
                } else {
                    // Open tag
                    if (indent_level > 0) {
                        output[output_index++] = '\n'; // New Line before tag
                    }
                    for (int j = 0; j < indent_level * INDENT_SIZE; j++) {
                        output[output_index++] = ' '; // Add indentation
                    }
                    in_tag = 1;
                }
                break;
            case '>':
                // Close tag found
                output[output_index++] = ch;
                output[output_index] = '\0';
                if (!in_tag) {
                    output_index--;
                }
                if (input[i - 1] != '/') {
                    // Only indent if it's not a self-closing tag
                    indent_level++;
                }
                in_tag = 0;
                continue; // Avoid adding newline here
            case '\n':
                continue; // Skip newlines directly in input
            default:
                // Add characters to output
                if (in_tag) {
                    output[output_index++] = ch; 
                } else {
                    // Append and then indent if inside text
                    if (output_index == 0 || output[output_index - 1] == '<') {
                        output[output_index++] = '\n';
                        for (int j = 0; j < indent_level * INDENT_SIZE; j++) {
                            output[output_index++] = ' ';// Add indentation before text
                        }
                    }
                    output[output_index++] = ch; 
                }
                break;
        }
        output[output_index] = '\0';
    }
    output[output_index] = '\0';
}

int main() {
    char html_input[MAX_LEN];
    char html_output[MAX_LEN * 2]; // Assume beautified HTML could be larger
    
    printf("Enter your HTML content (end with EOF):\n");
    // Read HTML input until EOF
    int i = 0;
    while (i < MAX_LEN - 1 && (html_input[i] = getchar()) != EOF) {
        if (html_input[i] == '\n') {
            // To ensure lines don't get too long
            if (i + 1 < MAX_LEN - 1) {
                html_input[i + 1] = '\0'; // Null terminate
                beautify_html(html_input, html_output);
                printf("%s", html_output);
                i = -1; // restart the index for new line
            }
        }
        i++;
    }
    
    // Handle the final line if it's not ending with a newline
    if (i > 0) {
        html_input[i] = '\0';
        beautify_html(html_input, html_output);
        printf("%s", html_output);
    }

    printf("\nBeautification completed.\n");
    return 0;
}