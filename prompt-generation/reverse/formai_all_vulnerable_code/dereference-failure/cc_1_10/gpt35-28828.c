//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_INPUT_LENGTH 1000

typedef enum {
    INTEGER,
    FLOAT,
    OPERATOR,
    IDENTIFIER
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

Token tokenize(char* input);
void parse_expression(char* input);

int main(int argc, char* argv[]) {
    printf("Welcome to the C syntax parsing game!\n");
    printf("Enter an expression to parse: ");

    char input[MAX_INPUT_LENGTH];
    fgets(input, MAX_INPUT_LENGTH, stdin);
    strtok(input, "\n"); // Remove trailing newline

    // Split input into tokens
    Token tokens[50];
    int num_tokens = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        tokens[num_tokens++] = tokenize(token);
        token = strtok(NULL, " ");
    }

    // Parse expression
    parse_expression(input);

    printf("Congratulations! You have successfully parsed an expression in C syntax!\n");
    return 0;
}

Token tokenize(char* input) {
    Token token;
    int i = 0;

    if (isdigit(input[0])) {
        token.type = INTEGER;
        while (isdigit(input[i])) {
            token.value[i] = input[i];
            i++;
        }
        token.value[i] = '\0';
    }
    else if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/') {
        token.type = OPERATOR;
        token.value[0] = input[0];
        token.value[1] = '\0';
    }
    else {
        token.type = IDENTIFIER;
        strcpy(token.value, input);
    }

    return token;
}

void parse_expression(char* input) {
    printf("Player 1, it is your turn to parse the expression:\n");
    printf("%s\n", input);
    printf("Enter the first token in the expression: ");

    char player_input[MAX_INPUT_LENGTH];
    fgets(player_input, MAX_INPUT_LENGTH, stdin);
    strtok(player_input, "\n"); // Remove trailing newline

    Token expected_token = tokenize(player_input);
    Token actual_token = tokenize(strtok(input, " "));

    if (expected_token.type != actual_token.type || strcmp(expected_token.value, actual_token.value) != 0) {
        printf("Sorry, you entered the wrong token. The correct token was \"%s\".\n", actual_token.value);
        printf("Player 2, it is your turn to parse the expression:\n");
        printf("%s\n", input);
        printf("Enter the first token in the expression: ");
        fgets(player_input, MAX_INPUT_LENGTH, stdin);
        strtok(player_input, "\n"); // Remove trailing newline
        expected_token = tokenize(player_input);
    }

    int num_tokens = 1;

    while (actual_token.type != OPERATOR || (actual_token.type == OPERATOR && actual_token.value[0] != '+' && actual_token.value[0] != '-')) {
        if (actual_token.type == OPERATOR) {
            printf("Player %d, it is your turn to parse the expression:\n", num_tokens % 2 + 1);
            printf("%s\n", input);
            printf("Enter the next token in the expression: ");
            fgets(player_input, MAX_INPUT_LENGTH, stdin);
            strtok(player_input, "\n"); // Remove trailing newline
            expected_token = tokenize(player_input);
        }

        actual_token = tokenize(strtok(NULL, " "));

        if (expected_token.type != actual_token.type || strcmp(expected_token.value, actual_token.value) != 0) {
            printf("Sorry, you entered the wrong token. The correct token was \"%s\".\n", actual_token.value);
            printf("Player %d, it is your turn to parse the expression:\n", num_tokens % 2 + 1);
            printf("%s\n", input);
            printf("Enter the next token in the expression: ");
            fgets(player_input, MAX_INPUT_LENGTH, stdin);
            strtok(player_input, "\n"); // Remove trailing newline
            expected_token = tokenize(player_input);
        }

        num_tokens++;
    }

    printf("Congratulations, player %d! You have correctly parsed the expression!\n", num_tokens % 2 + 1);
}