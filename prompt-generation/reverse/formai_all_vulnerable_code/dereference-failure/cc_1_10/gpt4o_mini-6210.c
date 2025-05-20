//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 10

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int i = 0;

    while (fgets(line, sizeof(line), input)) {
        char *ptr = line;
        
        // Remove leading whitespace
        while (*ptr == ' ' || *ptr == '\t') {
            ptr++;
        }

        // Check for closing tags
        if (strncmp(ptr, "</", 2) == 0) {
            indent_level--;
        }
        
        // Indent the line
        for (i = 0; i < indent_level; i++) {
            fprintf(output, "    "); // Use 4 spaces for indentation
        }

        // Write the line to the output file
        fprintf(output, "%s", ptr);

        // Check for opening tags
        if (ptr[0] == '<' && ptr[1] != '/') {
            // Increase indent level for opening tags
            if (strncmp(ptr, "<!DOCTYPE", 9) != 0) {
                indent_level++;
            }
        }

        // Increase indent level for <script> and <style>
        if (strstr(ptr, "<script") || strstr(ptr, "<style")) {
            indent_level++;
        }

        // Decrease indent level for </script> and </style>
        if (strstr(ptr, "</script>") || strstr(ptr, "</style>")) {
            indent_level--;
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML beautification complete! Output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}