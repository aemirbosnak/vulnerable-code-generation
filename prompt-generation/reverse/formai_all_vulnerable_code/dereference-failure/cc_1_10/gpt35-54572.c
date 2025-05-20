//FormAI DATASET v1.0 Category: Syntax parsing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000   // Maximum length of input string

// Function to check if character is a valid C keyword
int isKeyword(char str[])
{
    int n = strlen(str);
    char keywords[][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do",
                           "double", "else", "enum", "extern", "float", "for", "goto", "if",
                           "int", "long", "register", "return", "short", "signed", "sizeof", "static",
                           "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
                          };
    for(int i = 0; i < 32; i++)
    {
        if(strcmp(keywords[i], str) == 0)
            return 1;
    }
    return 0;
}

// Function to check if character is a valid C operator
int isOperator(char c)
{
    char operators[] = "+-*/%(){}[];,.";
    for(int i = 0; i < strlen(operators); i++)
    {
        if(c == operators[i])
            return 1;
    }
    return 0;
}

void parseCCode(char input[])
{
    printf("Input C code: %s\n", input);
    printf("Parsed output:\n");
    int i = 0, j, k;
    while(i < strlen(input))
    {
        // Ignore whitespaces
        while(input[i] == ' ')
            i++;
        
        // Parse variables and keywords
        j = i;
        while(isalnum(input[j]))
            j++;
        if(j > i)
        {
            char* token = (char*)malloc(sizeof(char) * (j-i+1));
            strncpy(token, input+i, j-i);
            token[j-i] = '\0';
            if(isKeyword(token))
                printf("<Keyword, %s> ", token);
            else
                printf("<Variable, %s> ", token);
            free(token);
            i = j;
            continue;
        }
        
        // Parse operators and punctuations
        if(isOperator(input[i]))
        {
            if(input[i] == '#')
            {
                while(input[j] != '\n')
                    j++;
                printf("<Pre-processor Directive> ");
            }
            else if(input[i] == '/')
            {
                if(input[i+1] == '/')
                {
                    while(input[j] != '\n')
                        j++;
                    printf("<Single Line Comment> ");
                }
                else if(input[i+1] == '*')
                {
                    j = i + 2;
                    while(input[j] != '*' && input[j+1] != '/')
                        j++;
                    j += 2;
                    printf("<Multi Line Comment> ");
                }
                else
                {
                    printf("%c", input[i]);
                }
            }
            else if(input[i] == '\'' || input[i] == '\"')
            {
                char delimiter = input[i];
                j = i+1;
                while(input[j] != delimiter)
                    j++;
                j++;
                printf("<String or Character Literal> ");
            }
            else
            {
                printf("%c", input[i]);
            }
            i = j;
            continue;
        }
        
        // Invalid character
        printf("Invalid character: %c\n", input[i++]);
    }
}

// Driver function
int main()
{
    char input[MAX_LENGTH];
    printf("Enter C code to be parsed:\n");
    fgets(input, MAX_LENGTH, stdin);
    parseCCode(input);
    return 0;
}