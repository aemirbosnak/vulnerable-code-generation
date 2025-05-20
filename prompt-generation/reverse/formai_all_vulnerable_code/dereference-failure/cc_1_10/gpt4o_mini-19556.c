//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the maximum line length
#define MAX_LINE_LENGTH 1024

// Function to trim whitespace from a string
char *trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-whitespace character
    *(end + 1) = '\0';

    return str;
}

// Function to beautify the HTML content
void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        char *trimmed_line = trim_whitespace(line);
        
        // Check if line is empty
        if (strlen(trimmed_line) == 0) {
            // Output empty lines as they are
            fprintf(output, "\n");
            continue;
        }

        // Increase indentation for starting tags
        if (strstr(trimmed_line, "<") && !strstr(trimmed_line, "/>") && !strstr(trimmed_line, "</")) {
            fprintf(output, "%*s%s\n", indent_level * 4, "", trimmed_line);
            indent_level++;  // Entering a new indent level
        }
        // Decrease indentation for closing tags
        else if (strstr(trimmed_line, "</")) {
            indent_level--;  // Exiting an indent level
            fprintf(output, "%*s%s\n", indent_level * 4, "", trimmed_line);
        } else {
            fprintf(output, "%*s%s\n", indent_level * 4, "", trimmed_line);
        }
    }
}

// Main function to execute the beautifier
int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input file
    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open the output file
    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return EXIT_FAILURE;
    }

    // Beautify the HTML content
    beautify_html(input, output);

    // Close the files
    fclose(input);
    fclose(output);

    printf("HTML beautification completed successfully!\n");

    return EXIT_SUCCESS;
}