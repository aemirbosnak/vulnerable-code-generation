//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void add_indent(char *line, int level) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        line[i] = ' ';
    }
    line[level * INDENT_SIZE] = '\0'; // Null-terminate the string
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        fprintf(stderr, "Could not open input file: %s\n", input_file);
        exit(EXIT_FAILURE);
    }
    
    FILE *out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        fprintf(stderr, "Could not open output file: %s\n", output_file);
        fclose(in_file);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    bool in_tag = false;

    while (fgets(line, sizeof(line), in_file)) {
        char trimmed_line[MAX_LINE_LENGTH];
        int trimmed_length = 0;
        
        // Remove leading whitespace
        for (int i = 0; line[i] != '\0'; ++i) {
            if (line[i] != ' ' && line[i] != '\t') {
                break;
            }
            trimmed_length++;
        }
        
        // Move to the right of the leading whitespace
        int j = 0;
        while (line[trimmed_length + j] != '\0' && line[trimmed_length + j] != '\n') {
            trimmed_line[j] = line[trimmed_length + j];
            j++;
        }
        trimmed_line[j] = '\0';

        // Check if we are currently inside a tag
        for (int k = 0; trimmed_line[k] != '\0'; k++) {
            if (trimmed_line[k] == '<') {
                in_tag = true;
                if (trimmed_line[k + 1] == '/') {
                    indent_level--;
                }
                break;
            } else if (trimmed_line[k] == '>') {
                in_tag = false;
                break;
            }
        }
        
        // Add indentation to the output
        add_indent(line, indent_level);
        
        // Write the trimmed line to the output file
        fprintf(out_file, "%s%s", line, (line[strcspn(line, "\n")] == '\0') ? "" : "\n");

        // Handle the closing tag to adjust indent level
        if (in_tag || (indent_level > 0 && trimmed_line[0] == '<' && trimmed_line[1] == '/')) {
            indent_level++;
        }
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML Beautification completed! Output saved to: %s\n", argv[2]);
    
    return EXIT_SUCCESS;
}