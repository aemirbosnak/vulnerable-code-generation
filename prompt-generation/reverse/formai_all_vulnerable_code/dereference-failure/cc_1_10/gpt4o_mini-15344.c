//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_STACK_SIZE 100

char *stack[MAX_STACK_SIZE];
int top = -1;

void push(char *tag) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = tag;
    } else {
        printf("Error: Stack overflow while pushing tag\n");
    }
}

char *pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        return NULL;
    }
}

int is_empty() {
    return top == -1;
}

int is_closing_tag(const char *line) {
    return line[1] == '/';
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    FILE *out_file = fopen(output_file, "w");
    
    if (in_file == NULL || out_file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_BUFFER_SIZE];
    int indent_level = 0;
    
    while (fgets(line, sizeof(line), in_file)) {
        char *pos = line;
        // Trim leading spaces/tabs
        while (*pos == ' ' || *pos == '\t') {
            pos++;
        }

        // Determine if it's an opening or closing tag
        if (strstr(pos, "<!DOCTYPE html") == pos) {
            fprintf(out_file, "%s\n", pos);
            continue;
        }

        if (is_closing_tag(pos)) {
            indent_level--;
        }

        // Print indented line
        for (int i = 0; i < indent_level; i++) {
            fprintf(out_file, "    ");
        }
        fprintf(out_file, "%s", pos); // Print the line

        // Check for opening tags
        char *end_tag = strchr(pos, '>');
        if (end_tag != NULL) {
            *end_tag = '\0'; // Null-terminate the string for tag analysis
            if (pos[1] != '/') { // Not a closing tag
                push(pos); // Push opening tag to stack
                // Check if self-closing tag
                if (strstr(pos, "/") != NULL && strstr(pos, "/>") != NULL) {
                    // It's a self-closing tag, don't increment indent
                    indent_level--;
                } else {
                    // It's an opening tag, increment indent
                    indent_level++;
                }
            }
        }
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification complete. Output saved to %s.\n", argv[2]);
    return EXIT_SUCCESS;
}