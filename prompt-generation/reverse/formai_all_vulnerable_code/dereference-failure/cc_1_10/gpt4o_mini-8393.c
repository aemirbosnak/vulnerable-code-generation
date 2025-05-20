//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 100

// Function to trim whitespace from the start and end of a string
char* trim_whitespace(char* str) {
    char* end;
    while (*str == ' ') str++;
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n' || *end == '\t')) end--;
    *(end + 1) = '\0';
    return str;
}

// Function to beautify an HTML line
void beautify_html(FILE* input, FILE* output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int in_tag = 0;

    while (fgets(line, sizeof(line), input)) {
        char* trimmed_line = trim_whitespace(line);
        
        if (strlen(trimmed_line) == 0) {
            continue; // Skip empty lines!
        }
        
        // Check if we are in an HTML tag
        char* tag_start = strchr(trimmed_line, '<');
        char* tag_end = strchr(trimmed_line, '>');

        if (tag_start && tag_end) {
            if (tag_start != trimmed_line) {
                // Before the tag, let's print the text
                fprintf(output, "%*s%s\n", indent_level * 2, "", trimmed_line);
            }

            if (*(tag_start + 1) == '/') {
                // Closing tag, decrease indent level
                indent_level--;
            }
            
            // Print the tag with proper indentation
            fprintf(output, "%*s%s\n", indent_level * 2, "", trimmed_line);

            if (*(tag_start + 1) != '/') {
                // Opening tag, increase indent level
                indent_level++;
            }
        } else {
            // If there's text outside of tags
            fprintf(output, "%*s%s\n", indent_level * 2, "", trimmed_line);
        }
    }
}

// Main function to handle the flow of the program
int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.html> <output.html>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Failed to open input file");
        return 2;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Failed to open output file");
        fclose(input_file);
        return 3;
    }

    printf("🎉 Starting the beautification process! 🎉\n");
    beautify_html(input_file, output_file);
    printf("✨ Beautification complete! Check out your new masterpiece! ✨\n");

    fclose(input_file);
    fclose(output_file);
    return 0;
}