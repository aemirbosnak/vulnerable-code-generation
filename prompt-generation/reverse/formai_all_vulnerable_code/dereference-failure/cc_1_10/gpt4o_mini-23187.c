//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HTML_SIZE 1000
#define MAX_INDENT 10

void beautify_html(const char *input_html, char *output_html) {
    int indent_level = 0;
    int output_index = 0;
    int in_tag = 0; // To keep track if we're within a tag
    int i;

    for (i = 0; input_html[i] != '\0'; i++) {
        if (input_html[i] == '<') {
            // If we encounter a '<', we are entering a tag
            if (in_tag) {
                // If we are already in a tag, adjust for self-closing or closing tags
                if (input_html[i + 1] == '/') {
                    // Closing tag --> reduce indent level
                    indent_level--;
                }
                // Insert the tag
                output_html[output_index++] = '\n';
                for (int j = 0; j < indent_level; j++) {
                    output_html[output_index++] = '\t'; // Add indentation
                }
            } else {
                // Opening tag --> increase indent level
                output_html[output_index++] = '\n';
                for (int j = 0; j < indent_level; j++) {
                    output_html[output_index++] = '\t'; // Add indentation
                }
                indent_level++;
            }

            // Mark that we are in a tag
            in_tag = 1;
        } else if (input_html[i] == '>') {
            // Closing a tag
            output_html[output_index++] = input_html[i];
            in_tag = 0;
            if (input_html[i - 1] != '/') {
                // Do not increase indent level for self-closing tags
                indent_level--;
            }
            output_html[output_index++] = '\n';
            for (int j = 0; j < indent_level; j++) {
                output_html[output_index++] = '\t'; // Add indentation
            }
            continue;
        }

        // Copy the character if it's not part of a < or >
        if (!in_tag || input_html[i] != '<') {
            output_html[output_index++] = input_html[i];
        }
    }

    output_html[output_index] = '\0'; // Null terminate the output string
}

int main() {
    char input_html[MAX_HTML_SIZE];
    char output_html[MAX_HTML_SIZE];

    printf("Enter your HTML code (type 'END' on a new line to finish):\n");

    // Read multiline input until "END" is typed
    char buffer[256];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strcmp(buffer, "END\n") == 0) {
            break;
        }
        strcat(input_html, buffer);
    }

    printf("\nBeautifying your HTML...\n");

    // Beautify the input HTML
    beautify_html(input_html, output_html);

    printf("\nBeautified HTML:\n");
    printf("%s\n", output_html);

    return 0;
}