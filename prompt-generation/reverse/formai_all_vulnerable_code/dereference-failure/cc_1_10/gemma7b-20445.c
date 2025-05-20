//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parser(char *);

int main()
{
    char *sourceCode = "int main() { printf(\"Hello, world!\"); }";
    parser(sourceCode);
    return 0;
}

void parser(char *sourceCode)
{
    int state = 0;
    char *token = NULL;
    char *buffer = NULL;
    int bufferSize = 0;

    while (sourceCode[state] != '\0')
    {
        switch (sourceCode[state])
        {
            case '(':
                buffer = realloc(buffer, bufferSize * 2);
                bufferSize *= 2;
                buffer[bufferSize - 1] = sourceCode[state];
                token = buffer;
                state++;
                break;
            case ')':
                token = strchr(buffer, '(');
                if (token)
                {
                    state = token - sourceCode;
                }
                else
                {
                    printf("Error: Missing parenthesis.\n");
                    exit(1);
                }
                break;
            case '{':
                buffer = realloc(buffer, bufferSize * 2);
                bufferSize *= 2;
                buffer[bufferSize - 1] = sourceCode[state];
                token = buffer;
                state++;
                break;
            case '}':
                token = strchr(buffer, '{');
                if (token)
                {
                    state = token - sourceCode;
                }
                else
                {
                    printf("Error: Missing curly braces.\n");
                    exit(1);
                }
                break;
            default:
                buffer = realloc(buffer, bufferSize * 2);
                bufferSize *= 2;
                buffer[bufferSize - 1] = sourceCode[state];
                state++;
                break;
        }
    }

    if (token)
    {
        printf("Syntax error: Unexpected token.\n");
        exit(1);
    }

    printf("Source code parsed successfully.\n");
}