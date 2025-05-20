//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENTATION_SIZE 4

// Function prototypes
void beautify_html(const char *input_file, const char *output_file);
int is_inside_tag(const char *line);
void add_indent(char *output_line, int indent_level);

// Main function
int main(int argc, char *argv[]) {
    // Welcome to the HTML Beautifier Extravaganza!
    printf("🎉 Welcome to the Great HTML Beautifier! 🎉\n");
    
    if (argc != 3) {
        printf("Usage: %s <input.html> <output.html>\n", argv[0]);
        printf("Don't worry! The beauty will be unleashed soon.\n");
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    // Let's beautify that HTML!
    beautify_html(input_file, output_file);
    
    printf("✨ Your HTML has been beautified! Check out %s for the magic! ✨\n", output_file);
    return EXIT_SUCCESS;
}

// Function to beautify the HTML
void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    
    // Check if files opened successfully
    if (!input) {
        printf("😱 Oh no! Can't open input file: %s\n", input_file);
        exit(EXIT_FAILURE);
    }
    if (!output) {
        printf("😱 Oh no! Can't open output file: %s\n", output_file);
        fclose(input);
        exit(EXIT_FAILURE);
    }

    // Read and process each line of the HTML file
    while (fgets(line, sizeof(line), input)) {
        char output_line[MAX_LINE_LENGTH] = "";

        // Magic happens here! Adding indentation!
        if (is_inside_tag(line)) {
            if (strstr(line, "</") != NULL) {
                // Close tag detected, decrease indent
                indent_level--;
            }
        }

        // Add indentation
        add_indent(output_line, indent_level);
        strcat(output_line, line);
        fputs(output_line, output);

        // Determine if we should increase indent after a line
        if (is_inside_tag(line) && strstr(line, "/>") == NULL && strstr(line, "</") == NULL) {
            // Open tag detected, increase indent
            indent_level++;
        }
    }

    // Close the files, because we are done
    fclose(input);
    fclose(output);
}

// Determines whether the current line is inside an HTML tag
int is_inside_tag(const char *line) {
    return (strchr(line, '<') != NULL && strchr(line, '>') != NULL);
}

// Add indentation to the given output line based on current indent level
void add_indent(char *output_line, int indent_level) {
    for (int i = 0; i < indent_level * INDENTATION_SIZE; i++) {
        output_line[i] = ' ';
    }
    output_line[indent_level * INDENTATION_SIZE] = '\0';  // Ensure null termination
}