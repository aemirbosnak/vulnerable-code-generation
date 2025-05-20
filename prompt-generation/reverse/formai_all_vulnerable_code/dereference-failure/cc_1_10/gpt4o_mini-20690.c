//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void trim_whitespace(char *line) {
    char *end;

    // Trim leading whitespace
    while(isspace((unsigned char)*line)) line++;

    // Trim trailing whitespace
    end = line + strlen(line) - 1;
    while(end > line && isspace((unsigned char)*end)) end--;

    // Null terminate the trimmed string
    *(end + 1) = '\0';
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (!input || !output) {
        fprintf(stderr, "Error: Could not open files.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int inside_tag = 0;

    while (fgets(line, sizeof(line), input)) {
        trim_whitespace(line);

        // Check for opening tags
        if (strchr(line, '<')) {
            inside_tag = 1;
            if (line[1] != '/') { // Not a closing tag
                fprintf(output, "%*s%s\n", indent_level * 4, "", line);
                indent_level++;
            } else { // Closing tag
                indent_level--;
                fprintf(output, "%*s%s\n", indent_level * 4, "", line);
            }
        } else if (inside_tag && strchr(line, '>')) {
            inside_tag = 0;
            fprintf(output, "%*s%s\n", indent_level * 4, "", line);
        } else {
            fprintf(output, "%*s%s\n", indent_level * 4, "", line);
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
    printf("HTML Beautification completed and output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}