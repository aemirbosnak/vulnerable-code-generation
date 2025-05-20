//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1024
#define INDENT_SIZE 4

void indent(FILE *output, int level) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        fputc(' ', output);
    }
}

bool is_whitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

bool is_closing_tag(const char *line, const char *tag) {
    char closing_tag[20];
    snprintf(closing_tag, sizeof(closing_tag), "</%s>", tag);
    return strstr(line, closing_tag) != NULL;
}

bool is_opening_tag(const char *line, const char *tag) {
    char opening_tag[20];
    snprintf(opening_tag, sizeof(opening_tag), "<%s>", tag);
    return strstr(line, opening_tag) != NULL;
}

void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    
    if (!input_file || !output_file) {
        fprintf(stderr, "Error opening files.\n");
        return;
    }
    
    char line[MAX_LEN];
    int indent_level = 0;
    
    while (fgets(line, sizeof(line), input_file) != NULL) {
        char temp[MAX_LEN];
        strcpy(temp, line);
        
        // Strip leading whitespace
        int lead_space = 0;
        while (is_whitespace(temp[lead_space])) {
            lead_space++;
        }
        memmove(temp, temp + lead_space, sizeof(temp) - lead_space);  
        
        // Increase indent level for opening tags
        for (int i = 0; temp[i] != '\0'; i++) {
            if (temp[i] == '<') {
                if (is_opening_tag(temp + i, "html") || 
                    is_opening_tag(temp + i, "body") || 
                    is_opening_tag(temp + i, "div")) {
                    indent(output_file, indent_level);
                    fputs(temp, output_file);
                    if (!is_closing_tag(temp + i, "html") && !is_closing_tag(temp + i, "body") && !is_closing_tag(temp + i, "div")) {
                        indent_level++;
                    }
                    break;
                } else if (is_closing_tag(temp + i, "html") || 
                           is_closing_tag(temp + i, "body") || 
                           is_closing_tag(temp + i, "div")) {
                    indent_level--;
                    indent(output_file, indent_level);
                    fputs(temp, output_file);
                    break;
                }
            } 
        }
        
        // Add indentation before other lines (text content)
        if (indent_level > 0 && is_whitespace(line[0]) && line[0] != '\n') {
            indent(output_file, indent_level);
        }
        
        // Write line
        fputs(temp, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Elementary, my dear Watson! Let's beautify this HTML...\n");
    beautify_html(argv[1], argv[2]);
    printf("The job is done! The HTML file is now beautified.\n");

    return EXIT_SUCCESS;
}