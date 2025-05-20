//FormAI DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Global variable to store the indentation level
int indent_level = 0;

// Function to print indentation spaces
void print_indentation() {
    int i;
    for (i = 0; i < indent_level; i++) {
        printf("  ");
    }
}

// Main program
int main() {
    // Initialize variables
    char html[10000] = "<html>\n<body>\n<div>\n<p> This is a paragraph. </p>\n</div>\n</body>\n</html>\n";
    char* token;
    char* rest = html;
    char* opener;
    char* closer;

    // Set up loop to parse the HTML string
    while ((token = strtok_r(rest, "\n", &rest))) {

        // Check for opening tag
        opener = strstr(token, "<");
        closer = strstr(token, ">");

        if (opener) {
            // Indentation
            print_indentation();

            // Print opening tag
            printf("%.*s", closer - opener + 1, opener);
            indent_level++;
        } else if (closer) {
            // Indentation
            indent_level--;

            // Print closing tag
            print_indentation();
            printf("%.*s\n", closer - opener + 1, opener);
        } else {
            // Indentation and print text
            print_indentation();
            printf("%s\n", token);
        }
    }

    // Exit program
    exit(0);
}