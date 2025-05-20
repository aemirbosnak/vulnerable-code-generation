//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

// Function to allocate memory for the output string
char* allocate_output(size_t size) {
    char* output = (char*)malloc(size);
    if (!output) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return output;
}

// Function to add indentation based on the current indentation level
void add_indentation(char* output, int indent_level, size_t* pos) {
    for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
        output[(*pos)++] = ' ';
    }
}

// Function to beautify the input HTML string
void beautify_html(const char* input, char* output) {
    int indent_level = 0;
    size_t pos = 0;
    int in_tag = 0;

    for (size_t i = 0; i < strlen(input); i++) {
        char current = input[i];

        if (current == '<') {
            if (input[i + 1] == '/') {
                if (indent_level > 0) {
                    indent_level--;
                }
            }
            if (pos > 0 && output[pos - 1] != '\n') {
                output[pos++] = '\n'; // Newline before tag
                add_indentation(output, indent_level, &pos);
            }
            in_tag = 1;
            output[pos++] = current; // Add the opening bracket
        } else if (current == '>') {
            output[pos++] = current; // Add the closing bracket
            in_tag = 0;
            // Check if it's a self-closing tag
            if (input[i - 1] != '/' && !(input[i - 1] == '>' && input[i - 2] == '/')) {
                if (strchr(input + i - 1, '<')) {
                    indent_level++; // Increase indent for the next tags
                }
            }
            output[pos++] = '\n'; 
            add_indentation(output, indent_level, &pos);
        } else {
            output[pos++] = current; // Add normal characters
        }
    }
    output[pos] = '\0'; // Null-terminate
}

// Function to read the HTML file into a string
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char* content = allocate_output(BUFFER_SIZE);
    size_t total_size = BUFFER_SIZE;
    size_t bytes_read = 0;

    while (fgets(content + bytes_read, total_size - bytes_read, file)) {
        bytes_read = strlen(content);
        if (bytes_read == total_size - 1) {
            total_size *= 2;
            content = realloc(content, total_size);
            if (!content) {
                fprintf(stderr, "Memory reallocation failed\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
    return content;
}

// Function to write the beautified HTML to a file
void write_to_file(const char* filename, const char* data) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error writing to file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", data);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the input HTML file
    char* input_html = read_file(argv[1]);
    
    // Allocate enough space for beautified output
    char* beautified_html = allocate_output(strlen(input_html) + 2048); // Extra space for indenting

    // Beautify the HTML
    beautify_html(input_html, beautified_html);

    // Write the beautified HTML to output file
    write_to_file(argv[2], beautified_html);
    
    // Cleanup
    free(input_html);
    free(beautified_html);

    printf("HTML beautification completed successfully!\n");
    return EXIT_SUCCESS;
}