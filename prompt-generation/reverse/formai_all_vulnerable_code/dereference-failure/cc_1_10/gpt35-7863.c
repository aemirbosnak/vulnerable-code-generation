//FormAI DATASET v1.0 Category: Syntax parsing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

int parse_variable(char *input);
int parse_expression(char *input);
int parse_statement(char *input);
int parse_program(char *input);

int main()
{
    char input[MAX_INPUT];
    printf("Enter a program: ");
    fgets(input, MAX_INPUT, stdin);

    int result = parse_program(input);
    if (result == 0)
        printf("Program successfully parsed!\n");
    else
        printf("Parsing error occured.\n");

    return 0;
}

int parse_variable(char *input)
{
    // A variable declaration consists of a type and a name
    char *types[] = {"int", "char", "float", "double"};
    int num_types = sizeof(types) / sizeof(char*);
    char *name = strstr(input, " ") + 1;
    // Get the first word in the input string
    char *type = strtok(input, " ");
    // Check if the type is valid
    for (int i = 0; i < num_types; i++)
    {
        if (strcmp(type, types[i]) == 0)
            return 0;
    }
    printf("Invalid variable type '%s'\n", type);
    return -1;
}

int parse_expression(char *input)
{
    // An expression must have at least one operand and one operator
    char *operators[] = {"+", "-", "*", "/"};
    int num_operators = sizeof(operators) / sizeof(char*);
    char *operand1 = strtok(input, operators[0]);
    if (operand1 == NULL)
    {
        printf("Error: expression must have at least one operand.\n");
        return -1;
    }
    char *operator = strtok(NULL, " ");
    if (operator == NULL)
    {
        printf("Error: expression must have an operator.\n");
        return -1;
    }
    char *operand2 = strtok(NULL, operators[1]);
    if (operand2 == NULL)
    {
        printf("Error: expression must have at least two operands.\n");
        return -1;
    }
    // Check if the operator is valid
    for (int i = 0; i < num_operators; i++)
    {
        if (strcmp(operator, operators[i]) == 0)
            return 0;
    }
    printf("Invalid operator '%s'\n", operator);
    return -1;
}

int parse_statement(char *input)
{
    char *keywords[] = {"if", "for", "while", "switch", "case"};
    int num_keywords = sizeof(keywords) / sizeof(char*);
    char *keyword = strtok(input, " ");
    // Check if the statement is a keyword
    for (int i = 0; i < num_keywords; i++)
    {
        if (strcmp(keyword, keywords[i]) == 0)
            return 0;
    }
    // If not a keyword, assume it is an expression
    return parse_expression(input);
}

int parse_program(char *input)
{
    // A program is a series of statements separated by semicolons
    char *statement = strtok(input, ";");
    while (statement != NULL)
    {
        int result = parse_statement(statement);
        if (result == -1)
            return -1;
        statement = strtok(NULL, ";");
    }
    return 0;
}