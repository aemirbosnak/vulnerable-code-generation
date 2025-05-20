//FormAI DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void indent(int level); // Function to add appropriate indentation
char *remove_whitespace(char *string); // Function to remove all unnecessary spaces and newlines


int main() {

    // Take input HTML code from the user
    char html[1000];
    printf("Enter your HTML code: ");
    fgets(html, 1000, stdin);

    // Remove unnecessary white spaces and newlines
    char *clean_html = remove_whitespace(html);

    // Initialize the level of indentation
    int level = 0;

    // Loop through the clean HTML code
    for (int i = 0; i < strlen(clean_html); i++) {

        // If opening tag is found, increase the level of indentation and print the tag
        if (clean_html[i] == '<' && clean_html[i+1] != '/') {
            indent(level);
            level++;
            printf("<");
            while (clean_html[i+1] != '>') {
                printf("%c", clean_html[i+1]);
                i++;
            }
            printf(">\n");
        }

        // If closing tag is found, decrease the level of indentation and print the tag
        else if (clean_html[i] == '<' && clean_html[i+1] == '/') {
            level--;
            indent(level);
            printf("<");
            while (clean_html[i+1] != '>') {
                printf("%c", clean_html[i+1]);
                i++;
            }
            printf(">\n");
        }

        // If content is found, print it with proper indentation
        else {
            indent(level);
            while (clean_html[i] != '<') {
                printf("%c", clean_html[i]);
                i++;
            }
            i--;
            printf("\n");
        }

    }

    return 0;
}

// Function to add appropriate indentation
void indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
}

// Function to remove all unnecessary spaces and newlines
char *remove_whitespace(char *string) {
    char *new_string = malloc(strlen(string) + 1);
    if (new_string == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    int j = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != ' ' && string[i] != '\n') {
            new_string[j] = string[i];
            j++;
        }
    }
    new_string[j] = '\0';
    return new_string;
}