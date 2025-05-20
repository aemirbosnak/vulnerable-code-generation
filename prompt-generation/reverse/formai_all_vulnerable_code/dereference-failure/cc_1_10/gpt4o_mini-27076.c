//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to trim whitespaces from the beginning and end of a string
char* trim_whitespace(char* str) {
    char* end;
    
    // Trim leading space
    while(*str == ' ') str++;
    
    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && *end == ' ') end--;
    *(end + 1) = '\0';

    return str;
}

// Function to beautify HTML code
void beautify_html(const char* input, FILE* output) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int indent = 0;

    // Read each line of HTML
    FILE* input_file = fopen(input, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Could not open input file %s\n", input);
        return;
    }

    while ((read = getline(&line, &len, input_file)) != -1) {
        // Trim each line
        char* trimmed_line = trim_whitespace(line);
        
        // Check for opening and closing tags
        if (strstr(trimmed_line, "<") && strstr(trimmed_line, ">")) {
            // Determine the indentation level for the current line
            if (strstr(trimmed_line, "</")) {
                indent--;
            }
            
            // Print the current line with indentation
            for (int i = 0; i < indent; i++) {
                fprintf(output, "    "); // Each indent is 4 spaces
            }
            fprintf(output, "%s\n", trimmed_line);
            
            // Increase indent for opening tags
            if (!strstr(trimmed_line, "</") && !strstr(trimmed_line, "/>")) {
                indent++;
            }
        } else {
            // Just print non-tag lines
            for (int i = 0; i < indent; i++) {
                fprintf(output, "    "); // Each indent is 4 spaces
            }
            fprintf(output, "%s\n", trimmed_line);
        }
    }

    fclose(input_file);
    if (line) {
        free(line);
    }
}

// Function to print a romantic message
void print_heart() {
    printf("\n\n");
    printf("                     .--.\n");
    printf("                  .-./  _\\\n");
    printf("                  \\  `-'/\n");
    printf("                   `---'\n");
    printf("      My love for you is like a perfectly structured HTML...\n");
    printf("                 It is beautiful and indented just right.\n");
    printf("                 Let us beautify this world together.\n");
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_heart();
    
    beautify_html(argv[1], fopen(argv[2], "w"));
    
    printf("\nYour HTML has been lovingly beautified and saved to %s. \n", argv[2]);
    printf("May our coding journeys be forever entwined!\n");
    
    return EXIT_SUCCESS;
}