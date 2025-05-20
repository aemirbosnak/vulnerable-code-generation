//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Post-Apocalyptic HTML Beautifier
 * In a world where the internet is a mere echo,
 * This program scours the remnants of HTML files,
 * Stripping away the unnecessary clutter, 
 * And restoring the beauty in the codes of yore.
 */

void beautify_html(const char *input_file, const char *output_file);
void add_indentation(char *output, int level);
void trim_whitespace(char *str);
void append_line(char *output, const char *line, int level);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./html_beautifier <input_file.html> <output_file.html>\n");
        exit(1);
    }

    printf("Initiating the beautification process...\n");
    beautify_html(argv[1], argv[2]);
    printf("Beautification completed. Check the output file: %s\n", argv[2]);
    
    return 0;
}

// Function to beautify HTML content
void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (!input || !output) {
        fprintf(stderr, "Error: Cannot open input or output file.\n");
        exit(1);
    }

    char line[BUFFER_SIZE];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        trim_whitespace(line);
        
        // Handle indentations based on the HTML tag
        if (strstr(line, "</") == line) { // Closing tag detected
            indent_level--;
        }
        
        append_line(line, line, indent_level);
        
        if (strstr(line, "<") == line && strstr(line, "/") == NULL && 
            strstr(line, "?") == NULL && strstr(line, "!") == NULL) {
            indent_level++;
        }
    }

    fclose(input);
    fclose(output);
}

// Function to trim leading and trailing whitespace from a string
void trim_whitespace(char *str) {
    char *end;

    // Trim leading whitespace
    while (isspace((unsigned char) *str)) str++;

    // Trim trailing whitespace
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) end--;

    end[1] = '\0';
}

// Appends a line to the output buffer with indentation
void append_line(char *output, const char *line, int level) {
    char indented_line[BUFFER_SIZE] = "";
    
    for (int i = 0; i < level; i++) {
        strcat(indented_line, "    "); // 4 spaces for each indent level
    }
    
    strcat(indented_line, line);
    strcat(indented_line, "\n");

    // Write to output file
    FILE *out = fopen("output.html", "a");
    fputs(indented_line, out);
    fclose(out);
}