//MISTRAL-7B DATASET v1.0 Category: HTML beautifier ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024

void print_line(char *line) {
    int length = strlen(line);
    int i;
    for (i = 0; i < length; i++) {
        if (line[i] >= 'a' && line[i] <= 'z') {
            putchar((line[i] - 32 > 'Z' ? line[i] : line[i] + 32));
        } else {
            putchar(line[i]);
        }
    }
    putchar('\n');
}

void beautify_code(char *code, int start_index, int end_index) {
    int i, j, k;
    char *token;
    char temp_char;

    // Calculate the length of the token before the current position
    int token_length = 0;
    for (i = start_index; i >= 0 && code[i] != ' '; i--) {
        token_length++;
    }

    // Allocate memory for the token
    token = (char*) malloc((token_length + 1) * sizeof(char));
    strncpy(token, &code[i + 1], token_length);
    token[token_length] = '\0';

    // Handle different types of tokens
    if (strcmp(token, "float") == 0 || strcmp(token, "double") == 0) {
        for (i = start_index - 1; i >= 0 && code[i] != ' '; i--) {
            if (code[i] == '=') {
                for (j = i - 1; j >= 0 && code[j] != ' '; j--) {
                    if (code[j] == ';') {
                        for (k = i + token_length + 2; k <= end_index && code[k] != '{' && code[k] != '}'; k++) {
                            if (code[k] == ' ') {
                                temp_char = code[k - 1];
                                code[k - 1] = code[k];
                                code[k] = temp_char;
                            }
                        }
                        for (j = i; j <= end_index; j++) {
                            print_line(&code[j]);
                        }
                        break;
                    }
                }
            }
        }
        free(token);
        return;
    }

    free(token);

    // Recursively call the function for the next token
    beautify_code(&code[end_index + 1], start_index, end_index);
}

int main() {
    char code[MAX_LINE_LENGTH];
    int length;

    while (fgets(code, sizeof(code), stdin) != NULL) {
        length = strlen(code);
        beautify_code(code, 0, length - 1);
        puts(code);
    }

    return 0;
}