//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char syntax_error = 0;
    char buffer[1024];
    char *ptr = NULL;
    char *end = NULL;
    char operator = '\0';
    int num1 = 0;
    int num2 = 0;

    printf("Welcome to the Last Syntax Parser!\n");
    printf("Enter a C expression: ");

    // Get the expression from the user
    fgets(buffer, 1024, stdin);

    // Allocate memory for the pointer
    ptr = malloc(strlen(buffer) + 1);

    // Copy the expression into the pointer
    strcpy(ptr, buffer);

    // Find the operator
    operator = ptr[0];

    // Find the first number
    num1 = atoi(ptr + 1);

    // Find the second number
    num2 = atoi(ptr + 2);

    // Check for syntax errors
    if (operator == '\0' || num1 == 0 || num2 == 0)
    {
        syntax_error = 1;
    }

    // Perform the operation
    int result = 0;
    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
    }

    // Print the result
    if (!syntax_error)
    {
        printf("The result is: %d\n", result);
    }
    else
    {
        printf("Syntax error!\n");
    }

    // Free the memory
    free(ptr);

    return 0;
}