//FormAI DATASET v1.0 Category: Syntax parsing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Function to check if the character is a valid identifier character
bool valid_identifier(char c)
{
    return isalnum(c) || c == '_';
}

// Struct to represent a single token
typedef struct Token
{
    enum { IDENTIFIER, NUMBER, LPAREN, RPAREN, PLUS, MINUS, TIMES, DIVIDE, ASSIGN, END } type;
    char* value;
} Token;

// Function to create a new token
Token* new_token(int type, char* value)
{
    Token* token = (Token*) malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    return token;
}

// Function to parse the next token in the input string
Token* next_token(char** input)
{
    char* value = (char*) malloc(sizeof(char));
    *value = '\0';
    while (**input && isspace(**input))
    {
        (*input)++;
    }
    if (**input && valid_identifier(**input))
    {
        while (**input && valid_identifier(**input))
        {
            value = (char*) realloc(value, (strlen(value) + 1) * sizeof(char));
            strncat(value, (*input)++, 1);
        }
        return new_token(IDENTIFIER, value);
    }
    if (**input && isdigit(**input))
    {
        while (**input && isdigit(**input))
        {
            value = (char*) realloc(value, (strlen(value) + 1) * sizeof(char));
            strncat(value, (*input)++, 1);
        }
        return new_token(NUMBER, value);
    }
    if (**input)
    {
        switch (**input)
        {
            case '(':
                (*input)++;
                return new_token(LPAREN, "(");
            case ')':
                (*input)++;
                return new_token(RPAREN, ")");
            case '+':
                (*input)++;
                return new_token(PLUS, "+");
            case '-':
                (*input)++;
                return new_token(MINUS, "-");
            case '*':
                (*input)++;
                return new_token(TIMES, "*");
            case '/':
                (*input)++;
                return new_token(DIVIDE, "/");
            case '=':
                (*input)++;
                return new_token(ASSIGN, "=");
        }
    }
    return new_token(END, "");
}

// Function to print a token
void print_token(Token* token)
{
    printf("[%d, %s]", token->type, token->value);
}

// Function to free a token
void free_token(Token* token)
{
    free(token->value);
    free(token);
}

// Recursive descent parser functions
void statement(char** input);
void expression(char** input);
void term(char** input);
void factor(char** input);
void identifier(char** input);
void number(char** input);

// Function to handle a syntax error
void syntax_error(char** input, char* message)
{
    printf("Syntax error: %s\n", message);
    exit(1);
}

// Function to parse a statement
void statement(char** input)
{
    identifier(input);
    Token* token = next_token(input);
    if (token->type != ASSIGN)
    {
        syntax_error(input, "Expected '=' after identifier in statement");
    }
    expression(input);
}

// Function to parse an expression
void expression(char** input)
{
    term(input);
    Token* token = next_token(input);
    while (token->type == PLUS || token->type == MINUS)
    {
        term(input);
        token = next_token(input);
    }
}

// Function to parse a term
void term(char** input)
{
    factor(input);
    Token* token = next_token(input);
    while (token->type == TIMES || token->type == DIVIDE)
    {
        factor(input);
        token = next_token(input);
    }
}

// Function to parse a factor
void factor(char** input)
{
    Token* token = next_token(input);
    if (token->type == LPAREN)
    {
        expression(input);
        token = next_token(input);
        if (token->type != RPAREN)
        {
            syntax_error(input, "Expected ')' after expression in factor");
        }
    }
    else if (token->type == IDENTIFIER)
    {
        // Do nothing
    }
    else if (token->type == NUMBER)
    {
        // Do nothing
    }
    else
    {
        syntax_error(input, "Unexpected token in factor");
    }
}

// Function to parse an identifier
void identifier(char** input)
{
    Token* token = next_token(input);
    if (token->type != IDENTIFIER)
    {
        syntax_error(input, "Expected identifier");
    }
}

// Function to parse a number
void number(char** input)
{
    Token* token = next_token(input);
    if (token->type != NUMBER)
    {
        syntax_error(input, "Expected number");
    }
}

// Main function
int main()
{
    char* input = "a = b + c * 2";
    printf("Input: %s\n", input);
    while (*input)
    {
        Token* token = next_token(&input);
        print_token(token);
        free_token(token);
    }
    printf("\n");
    return 0;
}