//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_syntax(char **buffer)
{
    int i = 0;
    int state = 0;
    char current_token[1024] = "";

    for (; buffer[i] && state != 3; i++)
    {
        switch (state)
        {
            case 0:
                if (buffer[i] == '(')
                {
                    state = 1;
                    strcpy(current_token, "(");
                }
                else if (buffer[i] == ')')
                {
                    state = 3;
                    printf("Syntax error: unbalanced parenthesis.\n");
                }
                else if (buffer[i] == '"')
                {
                    state = 2;
                    strcpy(current_token, "\"");
                }
                else if (buffer[i] == ' ')
                {
                    state = 0;
                    printf("Syntax error: unexpected space.\n");
                }
                else
                {
                    strcat(current_token, buffer[i]);
                }
                break;

            case 1:
                if (buffer[i] == ')')
                {
                    state = 0;
                    printf("Token: %s\n", current_token);
                }
                else
                {
                    strcat(current_token, buffer[i]);
                }
                break;

            case 2:
                if (buffer[i] == '"')
                {
                    state = 0;
                    printf("Token: %s\n", current_token);
                }
                else
                {
                    strcat(current_token, buffer[i]);
                }
                break;
        }
    }

    if (state != 3)
    {
        printf("Syntax error: unexpected end of input.\n");
    }
}

int main()
{
    char *buffer = "((a) b \"c\")";
    parse_syntax(&buffer);

    return 0;
}