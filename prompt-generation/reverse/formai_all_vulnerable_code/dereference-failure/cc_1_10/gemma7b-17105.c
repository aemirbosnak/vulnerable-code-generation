//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_c_syntax(char *source)
{
    int i = 0;
    char current_token[1024] = "";
    char **keywords = malloc(100 * sizeof(char *));
    char **operators = malloc(100 * sizeof(char *));
    int num_keywords = 0;
    int num_operators = 0;

    // Tokenization
    while (source[i] != '\0')
    {
        char token[1024] = "";
        int j = 0;
        for (; source[i] != '\0' && source[i] != ' ' && source[i] != '\t' && source[i] != '\n'; i++)
        {
            token[j] = source[i];
            j++;
        }
        token[j] = '\0';
        strcpy(current_token, token);

        // Keyword Recognition
        for (int k = 0; keywords[k] != NULL; k++)
        {
            if (strcmp(current_token, keywords[k]) == 0)
            {
                printf("Keyword: %s\n", current_token);
                num_keywords++;
                break;
            }
        }

        // Operator Recognition
        for (int k = 0; operators[k] != NULL; k++)
        {
            if (strcmp(current_token, operators[k]) == 0)
            {
                printf("Operator: %s\n", current_token);
                num_operators++;
                break;
            }
        }

        // Other Processing
        printf("Token: %s\n", current_token);
    }

    // Summary
    printf("Number of keywords: %d\n", num_keywords);
    printf("Number of operators: %d\n", num_operators);
    free(keywords);
    free(operators);
}

int main()
{
    char source[] = "int main() { printf(\"Hello, world!\"); }";
    parse_c_syntax(source);

    return 0;
}