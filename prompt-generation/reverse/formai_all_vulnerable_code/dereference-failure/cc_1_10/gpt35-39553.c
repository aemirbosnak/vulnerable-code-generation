//FormAI DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to strip out leading spaces
char* removeLeadingSpaces(char* line) {
    int i;
    int len = strlen(line);
    for(i = 0; i < len && line[i] == ' '; i++) {}
    return line + i;
}

// Function to beautify the HTML
void beautify(char* input_file, char* output_file) {
    // Open the input file for reading
    FILE* fp_in = fopen(input_file, "r");
    if(!fp_in) {
        printf("Error opening input file!\n");
        exit(EXIT_FAILURE);
    }

    // Open the output file for writing
    FILE* fp_out = fopen(output_file, "w");
    if(!fp_out) {
        printf("Error opening output file!\n");
        exit(EXIT_FAILURE);
    }

    char line[1000];
    char prev_line[1000] = "";
    int indent = 0;

    while(fgets(line, 1000, fp_in)) {
        // Ignore leading and trailing spaces
        char* stripped_line = removeLeadingSpaces(line);
        int len = strlen(stripped_line) - 1;

        // Check if current line is closing tag and decrement indentation
        if (len > 1 && stripped_line[0] == '/' && stripped_line[1] == '>') {
            indent -= 2;
        }

        // Add indentation to the line
        for(int i = 0; i < indent; ++i) {
            fputc('\t', fp_out);
        }

        // Write the line with indentation to output file
        fputs(stripped_line, fp_out);

        // Check if the current line is not self closing tag and increment identation
        if (len > 2 && stripped_line[len - 1] != '/' && stripped_line[len - 2] != '-') {
            indent += 2;
        }

        // Copy the current line to previous_line
        strcpy(prev_line, line);
    }

    // Close the input and output files
    fclose(fp_in);
    fclose(fp_out);
}

// Main function
int main() {
    const char* input_file = "input.html";
    const char* output_file = "output.html";
    beautify(input_file, output_file);
    printf("HTML file beautified successfully!\n");
    return 0;
}