//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void beautify(html_content) {
    int indent_level = 0;
    char line[MAX_LINE_LENGTH];
    bool in_tag = false;
    bool is_closing_tag = false;
    
    while (fgets(line, sizeof(line), html_content) != NULL) {
        char *ptr = line;
        char *tag_start;
        char *tag_end;

        while (*ptr) {
            if (*ptr == '<') {
                // Handle tag opening
                if (strncmp(ptr, "</", 2) == 0) {
                    is_closing_tag = true;
                    ptr += 2;  // Move past "</"
                } else if (strncmp(ptr, "<!--", 4) == 0) {
                    // Skip comment, but do not adjust indent level
                    while (*ptr && strncmp(ptr, "-->", 3) != 0) ptr++;
                    ptr += 3; // Move past "-->"
                    continue;
                } else {
                    is_closing_tag = false;
                    ptr++;  // Move past "<"
                }
                
                // Print new line and indent
                printf("\n%*s", indent_level, "");
                in_tag = true;

                // Count the tag's indentation level
                tag_start = ptr;
                while (*ptr && *ptr != '>') ptr++;
                tag_end = ptr;

                if (*ptr == '>') {
                    *ptr = '\0'; // Temporarily terminate the string
                    printf("%s", tag_start); // Print the tag
                    *ptr = '> '; // Restore '>'
                    ptr++; // Move past '>'

                    // Increase indent level for non-closing tags
                    if (!is_closing_tag) {
                        indent_level += INDENT_SIZE;
                    }
                }

                // Print the whitespace after the tag
                printf(" ");
            } else {
                // Print normal text
                if (in_tag) {
                    in_tag = false;
                    if (is_closing_tag) {
                        indent_level -= INDENT_SIZE;
                    }
                }
                putchar(*ptr++);
            }
        }
    }
}

int main() {
    printf("Enter HTML content (Ctrl+D to end):\n");
    beautify(stdin);
    return 0;
}