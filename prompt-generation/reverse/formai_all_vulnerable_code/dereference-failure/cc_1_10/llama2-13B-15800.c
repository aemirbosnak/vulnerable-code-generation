//LLAMA2-13B DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define MAX_INDENT 4

typedef struct node {
    char *text;
    struct node *next;
} Node;

void html_beautify(char *input) {
    Node *head, *curr, *prev;
    char line[MAX_LINE_LENGTH];
    int indent = 0;

    // Initialize the head node
    head = NULL;

    // Tokenize the input HTML code
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '<') {
            // Start of a new tag
            curr = (Node *)malloc(sizeof(Node));
            curr->text = line;
            curr->next = NULL;

            // Skip the '<' character
            i++;

            // Read the tag name
            while (input[i] != '>') {
                line[strcspn(line, "><")] = 0;
                i++;
            }

            // Add the tag to the head node
            curr->next = head;
            head = curr;

            // Reset the line and indent
            line[0] = '\0';
            indent = 0;
        } else if (input[i] == '>') {
            // End of a tag
            curr->next = NULL;
            head = curr;
            curr = NULL;
        } else if (input[i] == '\n') {
            // Start of a new line
            if (indent > MAX_INDENT) {
                // Indent decrease
                while (indent > MAX_INDENT) {
                    indent -= MAX_INDENT;
                }
            }
            // Reset the line and indent
            line[0] = '\0';
            indent = 0;
        } else {
            // Add the character to the current line
            line[strcspn(line, "><")] = 0;
            i++;
        }
    }

    // Format the HTML code
    curr = head;
    while (curr != NULL) {
        // Check if the current node is a tag
        if (curr->next != NULL) {
            // Add a space before the tag
            if (strcmp(curr->text, "br") != 0) {
                line[strcspn(line, ">")] = ' ';
            }
        }

        // Add the current node to the output
        printf("%s", line);

        // Move to the next node
        curr = curr->next;
    }

    // Free the memory
    free(head);
}

int main() {
    char input[] = "<html><body><p>This is a messy HTML code.</p><br><img src='example.com' alt='Example image'>"
                    "<p>This is another messy HTML code.</p></body></html>";
    html_beautify(input);
    return 0;
}