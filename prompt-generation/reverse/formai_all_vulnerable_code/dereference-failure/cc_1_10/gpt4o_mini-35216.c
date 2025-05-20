//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_STEP 4

void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    if (!input_file || !output_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    int i;

    while (fgets(buffer, BUFFER_SIZE, input_file)) {
        for (i = 0; buffer[i]; i++) {
            if (buffer[i] == '<') {
                if (buffer[i+1] == '/') {
                    // Closing tag
                    indent_level--;
                    if (indent_level < 0) indent_level = 0;
                    fprintf(output_file, "\n%*s", indent_level * INDENT_STEP, "");
                    fprintf(output_file, "%s", &buffer[i]);
                    break;
                } else {
                    // Opening tag
                    fprintf(output_file, "\n%*s", indent_level * INDENT_STEP, "");
                    fprintf(output_file, "%s", &buffer[i]);
                    indent_level++;
                    break;
                }
            }
        }
        
        // If the line does not contain a tag (text content)
        if (buffer[0] != '<') {
            fprintf(output_file, "%s", buffer);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification complete. Check the output file: %s\n", argv[2]);

    return EXIT_SUCCESS;
}