//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 100

typedef struct {
    char op;
    int num;
} Token;

void print_error_and_exit(char *msg) {
    printf("%s\n", msg);
    exit(1);
}

void tokenize(char *input, Token **tokens, int *num_tokens) {
    char current_char;
    int i = 0, num_spaces = 0;
    Token *token = NULL;

    *tokens = malloc(*num_tokens * sizeof(Token));
    if (!*tokens) {
        print_error_and_exit("Memory allocation failed!");
    }

    while (input[i] != '\0') {
        current_char = input[i];

        if (isspace(current_char)) {
            num_spaces++;
            if (num_spaces > 1) {
                token->op = ' ';
                (*num_tokens)++;
                token++;
                num_spaces = 0;
            }
            i++;
            continue;
        }

        if (isdigit(current_char)) {
            token->num = 0;
            while (isdigit(input[i])) {
                token->num = 10 * token->num + (input[i] - '0');
                i++;
            }
            token->op = 'N';
            (*num_tokens)++;
            token++;
            i--;
        } else if (current_char == '=') {
            token->op = '=';
            (*num_tokens)++;
            token++;
            i++;
        } else {
            print_error_and_exit("Invalid character found!");
        }

        i++;
    }

    if (token != *tokens) {
        (*num_tokens)++;
    }
}

int evaluate_expression(Token *tokens, int num_tokens) {
    int cat_age = 0, human_age = 0;
    Token *current_token = tokens;

    while (current_token < tokens + num_tokens) {
        switch (current_token->op) {
            case 'N':
                cat_age += current_token->num;
                current_token++;
                break;
            case '=':
                human_age = cat_age * 22 / current_token->num;
                current_token++;
                break;
            default:
                print_error_and_exit("Invalid operator found!");
        }
    }

    return human_age;
}

int main() {
    char input[MAX_LINE];
    Token *tokens = NULL;
    int num_tokens = 0;

    printf("Enter a CAT expression (e.g., '3cat years is equal to 22 human years'):\n");
    fgets(input, MAX_LINE, stdin);
    input[strcspn(input, "\n")] = '\0';

    tokenize(input, &tokens, &num_tokens);

    int human_age = evaluate_expression(tokens, num_tokens);

    printf("The human age equivalent is: %d\n", human_age);

    free(tokens);

    return 0;
}