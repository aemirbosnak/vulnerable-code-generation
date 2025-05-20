//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototypes
void beautify_html(const char *input_file, const char *output_file);
void add_indent(char *result, int indent_level);
bool is_closing_tag(const char *tag);
bool is_opening_tag(const char *tag);
bool is_self_closing_tag(const char *tag);
void trim(char *str);

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 10

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification done. Check your output file: %s\n", argv[2]);
    return EXIT_SUCCESS;
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_file, "w");
    if (!output) {
        fclose(input);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        // Trim the line for leading/trailing spaces
        trim(line);
        
        // Check for closing tags
        if (line[0] == '<' && is_closing_tag(line + 1)) {
            indent_level--;
            add_indent(line, indent_level);
        } else if (line[0] == '<' && is_opening_tag(line + 1)) {
            add_indent(line, indent_level);
            if (!is_self_closing_tag(line + 1)) {
                indent_level++;
            }
        } else {
            add_indent(line, indent_level);
        }
        
        fputs(line, output);
        
        // Add newline if not self-closing tag
        if (line[0] == '<' && is_opening_tag(line + 1) && !is_self_closing_tag(line + 1)) {
            fputc('\n', output);
        }
    }

    fclose(input);
    fclose(output);
}

void add_indent(char *result, int indent_level) {
    int i;
    for (i = 0; i < indent_level; i++) {
        fputs("\t", stdout);  // Print tabs for indentation
    }
    fputs(result, stdout);  // Output the modified line
}

bool is_closing_tag(const char *tag) {
    return tag[0] == '/';
}

bool is_opening_tag(const char *tag) {
    return tag[0] != '/' && tag[0] != '\0' && tag[1] != '\0' && tag[1] != '/';
}

bool is_self_closing_tag(const char *tag) {
    return tag[0] != '/' && tag[strlen(tag) - 2] == '/';
}

void trim(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';
}