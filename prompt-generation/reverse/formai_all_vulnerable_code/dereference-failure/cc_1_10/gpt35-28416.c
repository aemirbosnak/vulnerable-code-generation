//FormAI DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function to check whether a character is a space, tab, or newline
int is_whitespace(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n');
}

// Function to beautify the HTML code
void beautify_html(char *input_file, char *output_file) {
    // Open the input file
    FILE *fp_in = fopen(input_file, "r");

    // Open the output file
    FILE *fp_out = fopen(output_file, "w");

    // Check if file opening was successful
    if (fp_in == NULL || fp_out == NULL) {
        printf("Couldn't open file\n");
        exit(1);
    }

    // Initialize variables
    char curr_char, prev_char;
    int indent_level = 0;
    int newline_flag = 0;

    // Loop through the input file char by char
    while ((curr_char = fgetc(fp_in)) != EOF) {
        // Check if the current character is a whitespace
        if (is_whitespace(curr_char)) {
            // Check if the previous character was a newline
            if (prev_char == '\n') {
                newline_flag = 1;
            }
            continue;
        }

        // Check if the current character is a tag starting symbol
        if (curr_char == '<') {
            // Check if the previous character wasn't a whitespace and if there was a newline before
            if (!is_whitespace(prev_char) && newline_flag == 1) {
                fprintf(fp_out, "\n");
                for (int i = 0; i < indent_level; i++) {
                    fprintf(fp_out, "    ");
                }
            }

            // Write the tag starting symbol to the output file
            fprintf(fp_out, "%c", curr_char);

            // Increment the indent level
            indent_level += 1;

            // Set the newline flag to 1
            newline_flag = 1;
        }
        // Check if the current character is a tag ending symbol
        else if (curr_char == '>') {
            // Write the tag ending symbol to the output file
            fprintf(fp_out, "%c", curr_char);

            // Decrement the indent level
            indent_level -= 1;

            // Set the newline flag to 1
            newline_flag = 1;

            // Check if the next character is a newline
            if ((curr_char = fgetc(fp_in)) == '\n') {
                continue;
            }

            // Write the indentation to the output file
            fprintf(fp_out, "\n");
            for (int i = 0; i < indent_level; i++) {
                fprintf(fp_out, "    ");
            }
            fprintf(fp_out, "%c", curr_char);
        }
        else {
            // Check if the previous character was a newline
            if (prev_char == '\n') {
                newline_flag = 1;
                for (int i = 0; i < indent_level; i++) {
                    fprintf(fp_out, "    ");
                }
            }
            fprintf(fp_out, "%c", curr_char);
        }

        // Set the previous character to the current character
        prev_char = curr_char;
    }

    // Close the input and output files
    fclose(fp_in);
    fclose(fp_out);
}

int main() {
    // Call the function to beautify the HTML code
    beautify_html("input.html", "output.html");

    // Output a message
    printf("HTML code beautified successfully!\n");

    return 0;
}