//FormAI DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if a character is a valid HTML tag
int is_valid_tag(char c) {
    return isalpha(c) || c == '/';
}

// Function to check if a string is a valid HTML tag
int is_tag(char* s) {
    int len = strlen(s);
    if (len < 3) return 0;
    if (s[0] != '<' || s[len - 1] != '>') return 0;
    for (int i = 1; i < len - 1; i++) {
        if (!is_valid_tag(s[i])) return 0;
    }
    return 1;
}

// Function to read a line of text from stdin
char* read_line() {
    char* line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, stdin);
    if (read == -1) {
        return NULL;
    }
    // Remove newline character if it exists
    if (line[read - 1] == '\n') {
        line[read - 1] = '\0';
    }
    return line;
}

// Function to print a string with the given indentation level
void print_indented(char* s, int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%s\n", s);
}

// Function to beautify the HTML input and print it to stdout
void beautify_html() {
    char* line = NULL;
    int level = 0;
    while ((line = read_line()) != NULL) {
        if (is_tag(line)) {
            // Check if the tag is a closing tag
            int is_closing_tag = line[1] == '/';
            // Adjust the indentation level
            if (is_closing_tag) level--;
            print_indented(line, level);
            if (!is_closing_tag) level++;
        } else {
            print_indented(line, level);
        }
        free(line);
    }
}

int main() {
    beautify_html();
    return 0;
}