//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to sanitize user input */
char* sanitize(char* input)
{
    int length = strlen(input);
    char* output = (char*)malloc(length*sizeof(char));
    int i;
    for(i = 0; i < length; i++)
    {
        /* Check for dangerous characters */
        if(input[i] == '<' || input[i] == '>' || input[i] == '&' || input[i] == '\'')
        {
            /* Replace with safe alternative */
            switch(input[i])
            {
                case '<':
                    output[i] = '&lt;';
                    break;
                case '>':
                    output[i] = '&gt;';
                    break;
                case '&':
                    output[i] = '&amp;';
                    break;
                case '\'':
                    output[i] = '\\\'';
                    break;
            }
        }
        else
        {
            /* Copy non-dangerous characters into output string */
            output[i] = input[i];
        }
    }
    return output;
}

/* Main function */
int main()
{
    char input[100];
    printf("Enter your input: ");
    fgets(input, sizeof(input), stdin);

    /* Sanitize user input */
    char* output = sanitize(input);

    printf("Sanitized output: %s \n", output);
    free(output); /* Free allocated memory */

    return 0;
}