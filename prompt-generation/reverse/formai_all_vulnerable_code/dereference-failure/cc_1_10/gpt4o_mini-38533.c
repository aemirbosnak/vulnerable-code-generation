//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4
#define MAX_INDENT_LEVEL 20

void add_indent(char *buffer, int level) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        buffer[i] = ' ';
    }
    buffer[level * INDENT_SIZE] = '\0';  // Null-terminate the string
}

bool is_opening_bracket(char ch) {
    return ch == '{';
}

bool is_closing_bracket(char ch) {
    return ch == '}';
}

bool is_opening_tag(const char *line) {
    return strstr(line, "<") != NULL && strstr(line, "/") == NULL;
}

bool is_closing_tag(const char *line) {
    return strstr(line, "</") != NULL;
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    
    if (!in || !out) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    int indent_level = 0;
    
    while (fgets(line, sizeof(line), in) != NULL) {
        // Strip leading and trailing whitespaces
        char *start = line;
        while (isspace((unsigned char)*start)) start++;
        
        char *end = start + strlen(start) - 1;
        while (end > start && isspace((unsigned char)*end)) end--;
        *(end + 1) = '\0'; // Null terminate after the last character
        
        if (is_closing_bracket(line[0])) {
            indent_level--;
        }
        
        add_indent(buffer, indent_level);
        
        // Write the processed line to output
        fprintf(out, "%s%s\n", buffer, start);
        
        if (is_opening_bracket(line[0])) {
            indent_level++;
        }
        
        // Handle HTML tags
        if (is_opening_tag(start) && !is_closing_tag(start)) {
            // Further check for self closing tags (like <img />, <br />, etc.)
            if (strstr(start, "/>") == NULL) {
                indent_level++;
            } 
        } else if (is_closing_tag(start)) {
            indent_level--;
        }
    }
    
    fclose(in);
    fclose(out);
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <input-file.html> <output-file.html>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML beautification complete! Output written to %s\n", argv[2]);
    return EXIT_SUCCESS;
}