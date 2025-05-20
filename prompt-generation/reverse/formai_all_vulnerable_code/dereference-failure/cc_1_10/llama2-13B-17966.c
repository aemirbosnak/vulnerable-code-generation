//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a syntax element
struct syntax_element {
    char *name;   // Name of the syntax element
    char *value;  // Value of the syntax element
    struct syntax_element *next; // Next element in the list
};

// Define a function to parse a syntax string
struct syntax_element *parse_syntax(char *str) {
    struct syntax_element *root = NULL;
    char *token = strtok(str, " ");

    while (token != NULL) {
        // Check if the token is a keyword
        if (strchr("if else switch case", *token) != NULL) {
            struct syntax_element *new_ele = (struct syntax_element *)malloc(sizeof(struct syntax_element));
            new_ele->name = token;
            new_ele->value = NULL;
            new_ele->next = root;
            root = new_ele;
        } else {
            // Check if the token is a identifier
            if (isalpha(*token)) {
                struct syntax_element *new_ele = (struct syntax_element *)malloc(sizeof(struct syntax_element));
                new_ele->name = token;
                new_ele->value = NULL;
                new_ele->next = root;
                root = new_ele;
            }
        }
        token = strtok(NULL, " ");
    }
    return root;
}

// Define a function to print the parsed syntax
void print_syntax(struct syntax_element *root) {
    if (root == NULL) {
        printf("Empty syntax\n");
        return;
    }
    printf("Syntax:\n");
    struct syntax_element *current = root;
    while (current != NULL) {
        printf("%s %s\n", current->name, current->value != NULL ? current->value : "");
        current = current->next;
    }
}

int main() {
    char str[] = "if (x > 5) { y = 10; } else if (x < 2) { y = 5; } else { y = 0; } switch (x) { case 10: z = 20; break; case 5: z = 15; break; default: z = 0; }";
    struct syntax_element *root = parse_syntax(str);
    print_syntax(root);
    return 0;
}