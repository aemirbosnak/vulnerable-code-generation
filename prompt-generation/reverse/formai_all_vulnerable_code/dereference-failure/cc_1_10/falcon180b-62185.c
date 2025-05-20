//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

// Define structure for a token
typedef struct {
    char *value;
    int length;
} Token;

// Function to split input string into tokens
void tokenize(char *input, Token *tokens) {
    int num_tokens = 0;
    char *token = strtok(input, " ");

    while (token!= NULL && num_tokens < MAX_TOKENS) {
        int token_length = strlen(token);

        if (token_length > MAX_TOKEN_LENGTH) {
            printf("Error: token length exceeds maximum limit.\n");
            exit(1);
        }

        tokens[num_tokens].value = malloc(token_length + 1);
        strcpy(tokens[num_tokens].value, token);
        tokens[num_tokens].length = token_length;

        num_tokens++;
        token = strtok(NULL, " ");
    }
}

// Function to execute SQL query and print results
void execute_query(char *query, Token *tokens) {
    char *table_name = tokens[1].value;
    char *column_name = tokens[2].value;
    char *condition = tokens[3].value;

    printf("SELECT %s FROM %s WHERE %s;\n", column_name, table_name, condition);
}

int main() {
    char input[1000];
    Token tokens[MAX_TOKENS];

    printf("Enter SQL query (SELECT column_name FROM table_name WHERE condition):\n");
    fgets(input, sizeof(input), stdin);

    tokenize(input, tokens);

    if (tokens[0].value!= NULL && strcmp(tokens[0].value, "SELECT") == 0) {
        execute_query(input, tokens);
    } else {
        printf("Invalid SQL query.\n");
    }

    return 0;
}