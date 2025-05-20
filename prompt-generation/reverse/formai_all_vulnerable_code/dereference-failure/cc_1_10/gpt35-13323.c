//FormAI DATASET v1.0 Category: Syntax parsing ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_NUM_TOKENS 100

char** parse_input(char* input)
{
    char** tokens = malloc(MAX_NUM_TOKENS * sizeof(char*));
    char* token = strtok(input, " ");

    int i = 0;
    while(token != NULL)
    {
        tokens[i++] = token;
        token = strtok(NULL, " ");

        if(i >= MAX_NUM_TOKENS)
        {
            printf("Too many tokens in input!\n");
            exit(1);
        }
    }

    tokens[i] = NULL;
    return tokens;
}

void free_tokens(char** tokens)
{
    for(int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}

void parse_statement(char* statement)
{
    char** tokens = parse_input(statement);

    if(strcmp(tokens[0], "print") == 0)
    {
        for(int i = 1; tokens[i] != NULL; i++)
        {
            printf("%s ", tokens[i]);
        }
        printf("\n");
    }
    else if(strcmp(tokens[0], "add") == 0)
    {
        int result = 0;
        for(int i = 1; tokens[i] != NULL; i++)
        {
            result += atoi(tokens[i]);
        }
        printf("Result: %d\n", result);
    }
    else
    {
        printf("Invalid statement!\n");
    }

    free_tokens(tokens);
}

int main()
{
    char input[100];
    printf("Enter statement:\n");
    fgets(input, 100, stdin);

    // remove newline character
    input[strcspn(input, "\n")] = 0;

    parse_statement(input);

    return 0;
}