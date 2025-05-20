//FormAI DATASET v1.0 Category: Syntax parsing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* clean_string(char* str) {
    int len = strlen(str);
    char* clean_str = (char*) malloc(len + 1);

    for (int i = 0, j = 0; i < len; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\r' && str[i] != '\t' && str[i] != '\0') {
                clean_str[j++] = str[i];
        }
    }
    clean_str[len] = '\0';

    return clean_str;
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_valid_variable_name(char* str) {
    int len = strlen(str);
    if (len > 64) {
        return 0; // Variable name length should not exceed 64 characters
    }
    if (is_digit(str[0])) {
        return 0; // Variable name should not start with a digit
    }
    for (int i = 0; i < len; i++) {
        if (!(is_digit(str[i]) || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            return 0; // Variable name should only contain letters and digits
        }
    }
    return 1;
}

int is_valid_syntax(char* str) {
    str = clean_string(str);
    int len = strlen(str);
    int i = 0;

    while (i < len) {
        if (str[i] == ';') {
            i++;
            continue;
        }
        if (i != 0 && str[i-1] != ';') {
            return 0; // Statement should end with a semicolon
        }
        char* word = (char*) malloc(len - i + 1);
        int j = 0;
        while (i < len && str[i] != ';' && str[i] != ',') {
            word[j++] = str[i++];
        }
        word[j] = '\0';

        if (strcmp(word, "int") == 0) {
            i++;
            free(word);

            // Check variable declaration syntax
            if (i >= len || !is_valid_variable_name(&str[i])) {
                return 0;
            }

            while (i < len && str[i] != ';' && str[i] != ',') {
                i++;
            }
        } else if (is_valid_variable_name(word)) {
            int is_assignment = 0;

            // Check if it's an assignment
            while (i < len && str[i] != ';') {
                if (str[i] == '=') {
                    is_assignment = 1;
                } else if (!is_digit(str[i]) && str[i] != '-') {
                    return 0; // Invalid character in variable assignment
                }
                i++;
            }

            if (is_assignment == 0) {
                return 0; // Variable used without assignment
            }
        } else {
            return 0; // Invalid syntax
        }
    }

    return 1;
}

int main() {
    char input[1024];
    printf("Enter C syntax to validate:\n");
    fgets(input, 1024, stdin);

    printf("Syntax is %s\n", is_valid_syntax(input) ? "valid" : "invalid");
    return 0;
}