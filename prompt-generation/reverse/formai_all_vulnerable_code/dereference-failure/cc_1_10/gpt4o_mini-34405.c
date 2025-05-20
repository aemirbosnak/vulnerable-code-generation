//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_OUTPUT_LENGTH 2048

void beautify_html(const char *input_file, const char *output_file) {
    FILE *infile = fopen(input_file, "r");
    FILE *outfile = fopen(output_file, "w");
    
    if (!infile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (!outfile) {
        perror("Error opening output file");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    char indent_string[4] = "    ";  // 4 spaces for indentation

    while (fgets(line, sizeof(line), infile)) {
        char *pos = line;

        // Loop through the line to find opening/closing tags
        while ((pos = strstr(pos, "<"))) {
            // Print the part of the line before the tag
            int length = pos - line;
            if (length > 0) {
                fwrite(line, sizeof(char), length, outfile);
            }

            // Find the end of the tag
            char *end_tag = strstr(pos, ">");
            if (!end_tag) {
                break;  // Malformed HTML, stop processing
            }

            // Calculate the tag length
            int tag_length = end_tag - pos + 1;

            // Determine if it is an opening or closing tag
            if (*(pos + 1) == '/') {
                // Closing tag
                indent_level--;
            }

            // Print indentation
            for (int i = 0; i < indent_level; i++) {
                fwrite(indent_string, sizeof(char), strlen(indent_string), outfile);
            }

            // Write the tag itself to the output
            fwrite(pos, sizeof(char), tag_length, outfile);

            // Move position forward
            pos += tag_length;

            // Check if it's an opening tag to increase indentation
            if (*(pos - 2) != '/') {
                indent_level++;
            }

            // Adjust the line for the next round
            strncpy(line, pos, MAX_LINE_LENGTH);
        }
        
        // Ensure to write remaining part of the line after last tag
        if (line[0] != '\0') {
            fwrite(line, sizeof(char), strlen(line), outfile);
        }
    }

    fclose(infile);
    fclose(outfile);
    printf("HTML beautification complete. Output saved to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    return EXIT_SUCCESS;
}