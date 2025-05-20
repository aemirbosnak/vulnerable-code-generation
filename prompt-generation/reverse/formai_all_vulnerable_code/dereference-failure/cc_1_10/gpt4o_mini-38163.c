//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the trimmed string
    *(end + 1) = '\0';
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *fptr_in = fopen(input_file, "r");
    FILE *fptr_out = fopen(output_file, "w");
    
    if (fptr_in == NULL) {
        fprintf(stderr, "Could not open the input file: %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    if (fptr_out == NULL) {
        fprintf(stderr, "Could not open the output file: %s\n", output_file);
        fclose(fptr_in);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    const char *indents = "    "; // Four spaces for indentation

    while (fgets(line, sizeof(line), fptr_in)) {
        trim_whitespace(line);
        
        if (strstr(line, "</") == line) { // Closing tag
            indent_level--;
        }

        if (indent_level < 0) {
            indent_level = 0; // Prevent negative indentation
        }

        // Write indentation before the line
        for (int i = 0; i < indent_level; i++) {
            fputs(indents, fptr_out);
        }

        fputs(line, fptr_out);
        fputs("\n", fptr_out); // New line after the line

        if (strstr(line, "<") == line && strstr(line, "/") == NULL && strstr(line, "<?") == NULL && strstr(line, "<!") == NULL) {
            indent_level++; // Increment indention for opening tag, unless self-closing or declaration
        }
    }

    fclose(fptr_in);
    fclose(fptr_out);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Elementary, my dear Watson! Let's beautify the HTML file...\n");
    
    beautify_html(argv[1], argv[2]);

    printf("The HTML file has been beautified and saved as %s.\n", argv[2]);
    
    return EXIT_SUCCESS;
}