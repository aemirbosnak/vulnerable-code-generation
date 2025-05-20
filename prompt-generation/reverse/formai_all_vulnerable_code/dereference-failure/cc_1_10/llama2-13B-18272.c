//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAB_SIZE 4

void html_beautify(char *input) {
    char *output = NULL;
    char *token = NULL;
    char *current_tag = NULL;
    char *previous_tag = NULL;
    int current_line = 1;
    int current_column = 1;
    int tabs_used = 0;

    // Step 1: Tokenize the input
    token = strtok(input, "<");
    while (token != NULL) {
        if (strcmp(token, "<") == 0) {
            // Start of a tag
            current_tag = token;
            previous_tag = NULL;
        } else if (strcmp(token, "/>") == 0) {
            // End of a tag
            if (current_tag != previous_tag) {
                // Close the previous tag
                if (previous_tag != NULL) {
                    printf("</%s>", previous_tag);
                }
                previous_tag = current_tag;
            }
        } else {
            // Normal character
            output = realloc(output, strlen(output) + 1 + strlen(token) + 1);
            strcat(output, token);
        }
        token = strtok(NULL, "<");
    }

    // Step 2: Indent the output
    for (int i = 0; i < current_line; i++) {
        output = realloc(output, strlen(output) + 1 + TAB_SIZE * (i + 1));
        strcat(output, TAB_SIZE * (i + 1));
    }

    // Step 3: Wrap the output in HTML tags
    printf("<html><body>\n%s</body></html>", output);

    // Free memory
    free(output);
}

int main() {
    char input[] = "<html><body><p>This is a paragraph of text.</p><ul><li>This is the first list item.</li><li>This is the second list item.</li></ul></body></html>";
    html_beautify(input);
    return 0;
}