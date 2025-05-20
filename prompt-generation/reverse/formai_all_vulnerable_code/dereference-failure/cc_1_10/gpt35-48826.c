//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to remove spaces and comments from the code
char* clean_code(char* code) {
    char* clean = malloc(sizeof(char) * strlen(code));
    int i = 0, j = 0;

    // iterate through each character of the code
    while (code[i] != '\0') {
        if (code[i] == '/') {
            // if the character is a '/', check if it is a comment
            if (code[i + 1] == '/') {
                // remove the comment by skipping the rest of the line
                while (code[i] != '\n') {
                    i++;
                }
            }
            else if (code[i + 1] == '*') {
                // remove the comment by skipping until '*/'
                while (1) {
                    i++;
                    if (code[i] == '*' && code[i + 1] == '/') {
                        i += 2;
                        break;
                    }
                }
            }
            else {
                clean[j] = code[i];
                j++;
            }
        }
        else if (code[i] == ' ') {
            // remove spaces between characters
            if (j > 0 && clean[j - 1] != ' ' && clean[j - 1] != '>' && clean[j - 1] != '=') {
                clean[j] = code[i];
                j++;
            }
        }
        else {
            clean[j] = code[i];
            j++;
        }
        i++;
    }
    // add a null terminator at the end of the cleaned code
    clean[j] = '\0';
    return clean;
}

int main() {
    // sample code with spaces and comments
    char code[] = "/* This is a sample */\nint main() {\n\tint x = 0; // initialize x\n\tfor (int i = 0; i < 10; i++) {\n\t\tif (i % 2 == 0) {\n\t\t\tx = x + i;\n\t\t}\n\t}\n\treturn x;\n}";

    // print the uncleaned code
    printf("Uncleaned code:\n%s\n", code);

    // clean the code
    char* clean = clean_code(code);

    // print the cleaned code
    printf("Cleaned code:\n%s\n", clean);

    // free the memory used by the cleaned code
    free(clean);

    return 0;
}