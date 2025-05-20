//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INDENT_SIZE 4
#define BUFFER_SIZE 1024

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int indent_level = 0;
    bool in_tag = false;

    while (fgets(buffer, BUFFER_SIZE, input)) {
        for (char *ptr = buffer; *ptr != '\0'; ptr++) {
            if (*ptr == '<') {
                if (*(ptr + 1) == '/') {
                    // Closing tag
                    indent_level--;
                    fprintf(output, "\n%*s", indent_level * INDENT_SIZE, "");
                } else {
                    // Opening tag
                    fprintf(output, "\n%*s", indent_level * INDENT_SIZE, "");
                    indent_level++;
                }
                in_tag = true;
            }

            fputc(*ptr, output);

            if (*ptr == '>') {
                if (!in_tag) {
                    fprintf(output, "\n%*s", indent_level * INDENT_SIZE, "");
                }
                in_tag = false;
            }
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification completed successfully!\n");
    
    return EXIT_SUCCESS;
}