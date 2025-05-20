//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_token(char c) {
    switch (c) {
        case '(':
        case ')':
        case '{':
        case '}':
        case ';':
        case ',':
        case '.':
        case '*':
        case '/':
        case '+':
        case '-':
        case '[':
        case ']':
        case '<':
        case '>':
        case '=':
        case '!':
        case '&':
        case '|':
        case '^':
        case '?':
            return 1;
        default:
            return 0;
    }
}

int is_keyword(char *str) {
    if (strcmp(str, "int") == 0) {
        return 1;
    } else if (strcmp(str, "float") == 0) {
        return 1;
    } else if (strcmp(str, "char") == 0) {
        return 1;
    } else if (strcmp(str, "bool") == 0) {
        return 1;
    } else if (strcmp(str, "void") == 0) {
        return 1;
    } else if (strcmp(str, "main") == 0) {
        return 1;
    } else if (strcmp(str, "return") == 0) {
        return 1;
    } else if (strcmp(str, "if") == 0) {
        return 1;
    } else if (strcmp(str, "else") == 0) {
        return 1;
    } else if (strcmp(str, "for") == 0) {
        return 1;
    } else if (strcmp(str, "while") == 0) {
        return 1;
    } else if (strcmp(str, "break") == 0) {
        return 1;
    } else if (strcmp(str, "continue") == 0) {
        return 1;
    } else if (strcmp(str, "switch") == 0) {
        return 1;
    } else if (strcmp(str, "case") == 0) {
        return 1;
    } else if (strcmp(str, "default") == 0) {
        return 1;
    } else if (strcmp(str, "goto") == 0) {
        return 1;
    } else if (strcmp(str, "const") == 0) {
        return 1;
    } else if (strcmp(str, "volatile") == 0) {
        return 1;
    } else if (strcmp(str, "struct") == 0) {
        return 1;
    } else if (strcmp(str, "union") == 0) {
        return 1;
    } else if (strcmp(str, "enum") == 0) {
        return 1;
    } else if (strcmp(str, "typedef") == 0) {
        return 1;
    } else if (strcmp(str, "if") == 0) {
        return 1;
    } else if (strcmp(str, "else") == 0) {
        return 1;
    } else if (strcmp(str, "for") == 0) {
        return 1;
    } else if (strcmp(str, "while") == 0) {
        return 1;
    } else if (strcmp(str, "break") == 0) {
        return 1;
    } else if (strcmp(str, "continue") == 0) {
        return 1;
    } else if (strcmp(str, "switch") == 0) {
        return 1;
    } else if (strcmp(str, "case") == 0) {
        return 1;
    } else if (strcmp(str, "default") == 0) {
        return 1;
    } else if (strcmp(str, "goto") == 0) {
        return 1;
    } else if (strcmp(str, "const") == 0) {
        return 1;
    } else if (strcmp(str, "volatile") == 0) {
        return 1;
    } else if (strcmp(str, "struct") == 0) {
        return 1;
    } else if (strcmp(str, "union") == 0) {
        return 1;
    } else if (strcmp(str, "enum") == 0) {
        return 1;
    } else if (strcmp(str, "typedef") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char *str = "int x = 10;";
    char *token;
    int token_type;
    int i = 0;

    while (str[i]!= '\0') {
        token = strtok(str, " \t\n");
        token_type = is_keyword(token);
        if (token_type == 1) {
            printf("%s ", token);
        } else if (token_type == 0) {
            token_type = is_token(token[0]);
            if (token_type == 1) {
                printf("%c ", token[0]);
            } else if (token_type == 0) {
                printf("UNKNOWN ");
            }
        }
        i++;
    }
    return 0;
}