//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a C syntax element
struct syntax_element {
    char *name;      // Name of the syntax element
    char *content;  // Content of the syntax element
    struct syntax_element *next;  // Next syntax element in the list
};

// Function to parse a C syntax string and print its elements
void parse_c_syntax(char *str) {
    // Create a list of syntax elements
    struct syntax_element *list = NULL;

    // Tokenize the input string
    char *token = strtok(str, " ");
    while (token != NULL) {
        // Create a new syntax element
        struct syntax_element *new_element = malloc(sizeof(struct syntax_element));
        new_element->name = token;
        new_element->content = NULL;
        new_element->next = list;
        list = new_element;

        // Check if the token is a keyword
        if (strchr("ifelsewhilefor", token[0]) != NULL) {
            // If it is a keyword, print its content
            if (list->content != NULL) {
                printf("Keyword %s has content %s\n", list->name, list->content);
            } else {
                printf("Keyword %s has no content\n", list->name);
            }
        } else {
            // If it is not a keyword, print its content and move to the next token
            if (list->content != NULL) {
                printf("Non-keyword %s has content %s\n", list->name, list->content);
            }
            token = strtok(NULL, " ");
            if (token != NULL) {
                list->content = token;
            }
        }
    }
}

int main() {
    char str[] = "if (x > 0) { while (y > 0) { z = x + y; } } else { printf(\"x is less than or equal to 0\"); }";
    parse_c_syntax(str);
    return 0;
}