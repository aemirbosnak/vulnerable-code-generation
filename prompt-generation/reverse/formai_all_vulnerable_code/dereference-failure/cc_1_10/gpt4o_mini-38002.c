//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define INDENT "    " // 4 spaces for indentation

void beautify_html(const char *input, FILE *output) {
    int indent_level = 0;
    int in_tag = 0;
    const char *ptr = input;
    char buffer[BUFFER_SIZE];
    
    while (*ptr) {
        if (*ptr == '<') {
            if (*(ptr + 1) == '/') {
                // Closing tag: decrease indent
                indent_level--;
                if (indent_level < 0) indent_level = 0;
            }
            
            // Print indentation
            for (int i = 0; i < indent_level; i++) {
                fputs(INDENT, output);
            }
            
            in_tag = 1;
            fputc(*ptr++, output); // Print the '<'
        } else if (*ptr == '>') {
            fputc(*ptr++, output); // Print the '>'
            in_tag = 0;
            
            // Check for opening tag
            if (*(ptr - 2) != '/') {
                // Opening tag: increase indent
                indent_level++;
            }

            // New line after tag
            fputc('\n', output);
        } else {
            // Print current character
            if (!in_tag && *ptr == '\n') {
                // Skip redundant newlines
                ptr++;
                continue;
            }
            fputc(*ptr++, output);
        }
    }
}

char* read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    fclose(file);
    return buffer;
}

void write_file(const char *filename, char *content) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fputs(content, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input-html-file> <output-html-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *input_html = read_file(argv[1]);
    
    // Open output file
    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        fprintf(stderr, "Could not open file: %s\n", argv[2]);
        free(input_html);
        return EXIT_FAILURE;
    }

    fprintf(output_file, "<!DOCTYPE html>\n");
    fprintf(output_file, "<html>\n");
    
    beautify_html(input_html, output_file);

    fprintf(output_file, "</html>\n");

    fclose(output_file);
    free(input_html);
    
    printf("HTML beautification complete! Check the file: %s\n", argv[2]);

    return EXIT_SUCCESS;
}