//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to allocate and check memory
void *malloc_and_check(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to read a file into a string
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Allocate memory for the string
    char *str = malloc_and_check(size + 1);

    // Read the file into the string
    fread(str, size, 1, file);
    str[size] = '\0';

    // Close the file
    fclose(file);

    return str;
}

// Function to beautify HTML code
char *beautify_html(char *html) {
    // Allocate memory for the beautified HTML code
    char *beautified = malloc_and_check(strlen(html) * 2 + 1);

    // Initialize the beautified HTML code
    beautified[0] = '\0';

    // Track the current indentation level
    int indent_level = 0;

    // Iterate over the HTML code
    for (char *p = html; *p != '\0'; p++) {
        // Check for the start of a tag
        if (*p == '<') {
            // Add the tag to the beautified HTML code
            strcat(beautified, p);

            // If the tag is not a self-closing tag, increase the indentation level
            if (*++p != '/') {
                indent_level++;

                // Add a newline and indentation to the beautified HTML code
                strcat(beautified, "\n");
                for (int i = 0; i < indent_level; i++) {
                    strcat(beautified, "  ");
                }
            }
        }
        // Check for the end of a tag
        else if (*p == '>') {
            // If the tag is not the end of a self-closing tag, decrease the indentation level
            if (*--p != '/') {
                indent_level--;

                // Add a newline and indentation to the beautified HTML code
                strcat(beautified, "\n");
                for (int i = 0; i < indent_level; i++) {
                    strcat(beautified, "  ");
                }
            }

            // Add the tag to the beautified HTML code
            strcat(beautified, p);
        }
        // Check for text
        else {
            // Add the text to the beautified HTML code
            strcat(beautified, p);
        }
    }

    // Return the beautified HTML code
    return beautified;
}

// Main function
int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read the HTML file into a string
    char *html = read_file(argv[1]);

    // Beautify the HTML code
    char *beautified = beautify_html(html);

    // Print the beautified HTML code
    printf("%s", beautified);

    // Free the memory allocated for the HTML code
    free(html);
    free(beautified);

    return EXIT_SUCCESS;
}