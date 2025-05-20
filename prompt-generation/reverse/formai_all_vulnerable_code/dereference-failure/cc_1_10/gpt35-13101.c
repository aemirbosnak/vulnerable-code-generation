//FormAI DATASET v1.0 Category: HTML beautifier ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAB_SIZE 4

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("USAGE: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: cannot open input file '%s'\n", argv[1]);
        return 1;
    }

    // Read the input file character by character
    char c;
    int indent_level = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '<') {
            // Output newline and indent before opening tag
            printf("\n");
            for (int i = 0; i < indent_level; i++) {
                printf(" ");
            }
            // Output opening tag and increase indent
            printf("%c", c);
            indent_level += TAB_SIZE;
        } else if (c == '>') {
            // Output closing tag and decrease indent
            printf("%c", c);
            indent_level -= TAB_SIZE;
        } else if (c == '/') {
            // Output closing tag and decrease indent
            printf("%c", c);
            c = fgetc(fp);
            if (c == '>') {
                printf("%c", c);
                indent_level -= TAB_SIZE;
            } else {
                printf("Error: malformed tag at line %d\n", indent_level / TAB_SIZE + 1);
                return 1;
            }
        } else {
            // Output other characters
            printf("%c", c);
        }
    }

    fclose(fp);
    return 0;
}