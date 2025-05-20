//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// This program beautifies HTML code by adding indents and newlines.
// It uses a stack to keep track of the current indentation level.

// The main function.
int main(int argc, char *argv[]) {
    // Check if the user has provided a filename.
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the file into a string.
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char *html = malloc(size + 1);
    fread(html, 1, size, file);
    fclose(file);
    html[size] = '\0';

    // Create a stack to keep track of the current indentation level.
    int stack[100];
    int top = -1;

    // Beautify the HTML code.
    int i;
    for (i = 0; i < strlen(html); i++) {
        char c = html[i];

        // If the character is a newline, add a newline to the output.
        if (c == '\n') {
            printf("\n");
        }
        // If the character is a '<', add an indent to the output.
        else if (c == '<') {
            top++;
            stack[top] = 2;
            printf("%*c%c", stack[top], ' ', c);
        }
        // If the character is a '>', remove an indent from the output.
        else if (c == '>') {
            top--;
            printf("%c", c);
        }
        // If the character is a space or a tab, add a space to the output.
        else if (isspace(c)) {
            printf(" ");
        }
        // Otherwise, add the character to the output.
        else {
            printf("%c", c);
        }
    }

    // Free the allocated memory.
    free(html);

    return EXIT_SUCCESS;
}