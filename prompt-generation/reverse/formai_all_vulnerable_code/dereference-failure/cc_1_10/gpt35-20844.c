//FormAI DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the tab size and buffer size for the program
#define TAB_SIZE 4
#define BUFFER_SIZE 1024

// Function that takes an input HTML file and beautifies the output
void html_beautifier(char *input_file_name, char *output_file_name) {

    FILE *input_file, *output_file;
    char buffer[BUFFER_SIZE], ch;
    int i, indent = 0;

    // Open the input and output files using the provided file names
    input_file = fopen(input_file_name, "r");
    output_file = fopen(output_file_name, "w");

    // Check if the input file exists
    if (!input_file) {
        printf("Error: Could not open input file '%s'\n", input_file_name);
        exit(1);
    }

    // Read the input file character-by-character and beautify the output
    while ((ch = fgetc(input_file)) != EOF) {

        // If the current character is a '<', print a newline character and indent the output
        if (ch == '<') {
            fprintf(output_file, "\n");
            for (i = 0; i < indent; i++) {
                fprintf(output_file, " ");
            }
        }

        // Print the current character to the output file
        fprintf(output_file, "%c", ch);

        // If the current character is a '>', indent the output for the next line
        if (ch == '>') {
            indent += TAB_SIZE;
        }

        // If the current character is a newline character, decrease the indentation level
        if (ch == '\n') {
            indent = 0;
        }
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("HTML beautified successfully!\n");
}

int main() {

    char input_file_name[] = "index.html";
    char output_file_name[] = "beautified.html";

    // Call the html_beautifier function to beautify the input HTML file
    html_beautifier(input_file_name, output_file_name);

    return 0;
}