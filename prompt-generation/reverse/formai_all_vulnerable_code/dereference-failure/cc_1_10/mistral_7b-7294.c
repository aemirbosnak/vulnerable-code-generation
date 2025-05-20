//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256
#define KEYWORD_SIZE 10

typedef struct {
    char name[KEYWORD_SIZE];
    int length;
} keyword;

keyword reserved_words[10] = {
    {"if", 2},
    {"else", 4},
    {"while", 5},
    {"int", 3},
    {"float", 5},
    {"char", 4},
    {"void", 4},
    {"return", 6},
    {"for", 3},
    {"switch", 6}
};

int is_reserved_word(char *str) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(str, reserved_words[i].name) == 0) {
            return 1;
        }
    }
    return 0;
}

int extract_metadata(char *code, int *num_variables, int *num_functions, int *max_line_length) {
    int lines = 1;
    int current_line_length = 0;
    int variables = 0;
    int functions = 0;
    int in_string = 0;

    for (int i = 0; code[i] != '\0'; i++) {
        if (isspace(code[i])) {
            if (current_line_length > *max_line_length) {
                *max_line_length = current_line_length;
            }
            current_line_length = 0;
            continue;
        }

        if (code[i] == '\'' && !in_string) {
            in_string = 1;
            continue;
        }

        if (code[i] == '\'' && in_string) {
            in_string = 0;
            continue;
        }

        if (code[i] == ';' || isalnum(code[i])) {
            if (!in_string && isalnum(code[i])) {
                char variable_name[MAX_SIZE];
                int j = 0;

                while (isalnum(code[i]) || code[i] == '_') {
                    variable_name[j++] = code[i];
                    i++;
                    if (i >= MAX_SIZE) {
                        break;
                    }
                }

                variable_name[j] = '\0';

                if (!is_reserved_word(variable_name)) {
                    variables++;
                }

                if (strchr(code, '(') && strchr(code, '(') < strchr(code, ';')) {
                    functions++;
                }

                current_line_length++;
            }
        }

        if (code[i] == '{') {
            lines++;
        } else if (code[i] == '}') {
            lines--;
            if (lines == 0) {
                break;
            }
        }
    }

    *num_variables = variables;
    *num_functions = functions;

    return 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <source_code>\n", argv[0]);
        return 1;
    }

    int num_variables, num_functions, max_line_length;
    int success = extract_metadata(argv[1], &num_variables, &num_functions, &max_line_length);

    if (!success) {
        printf("Error: Failed to extract metadata from source code.\n");
        return 1;
    }

    printf("Number of variables: %d\n", num_variables);
    printf("Number of functions: %d\n", num_functions);
    printf("Maximum line length: %d\n", max_line_length);

    return 0;
}