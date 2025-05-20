//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_syntax(char *source)
{
    char **tokens = NULL;
    int token_count = 0;
    char current_state = 'S';
    int i = 0;

    while (source[i] != '\0')
    {
        switch (current_state)
        {
            case 'S':
                if (source[i] == '(')
                {
                    tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
                    tokens[token_count++] = malloc(1);
                    tokens[token_count - 1][0] = '(';
                    current_state = 'P';
                }
                else if (source[i] == '"')
                {
                    tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
                    tokens[token_count++] = malloc(1);
                    tokens[token_count - 1][0] = '"';
                    current_state = 'Q';
                }
                else
                {
                    current_state = 'A';
                }
                break;
            case 'P':
                if (source[i] == ')')
                {
                    current_state = 'S';
                }
                else if (source[i] == '"')
                {
                    current_state = 'Q';
                }
                else
                {
                    current_state = 'A';
                }
                break;
            case 'Q':
                if (source[i] == '"')
                {
                    current_state = 'S';
                }
                else
                {
                    current_state = 'A';
                }
                break;
            case 'A':
                if (source[i] == ' ' || source[i] == '\t' || source[i] == '\n')
                {
                    current_state = 'S';
                }
                else
                {
                    current_state = 'A';
                }
                break;
        }

        i++;
    }

    printf("Tokens:");
    for (int j = 0; j < token_count; j++)
    {
        printf(" %s", tokens[j]);
    }

    free(tokens);
}

int main()
{
    parse_syntax("foo (bar) \"baz\"");

    return 0;
}