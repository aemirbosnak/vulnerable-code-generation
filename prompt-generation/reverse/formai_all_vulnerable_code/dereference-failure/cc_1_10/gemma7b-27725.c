//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

void calculator(char **buffer, int *buffer_size)
{
    int i = 0, sign = 1, number = 0, operand_flag = 0;
    char operator = '\0';

    // Loop over the buffer to find the operator
    for (i = 0; i < *buffer_size && buffer[i] != '\0'; i++)
    {
        // Check if the character is an operator
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            operator = buffer[i];
            break;
        }
    }

    // If an operator is found, calculate the result
    if (operator)
    {
        // Calculate the number
        for (i = i + 1; buffer[i] != '\0' && buffer[i] != operator; i++)
        {
            number = number * 10 + buffer[i] - '0';
        }

        // Apply the sign
        if (sign == -1)
        {
            number = -number;
        }

        // Print the result
        printf("%d\n", number);
    }

    // Reset the buffer and variables
    *buffer_size = 0;
    free(buffer);
    buffer = NULL;
    sign = 1;
    number = 0;
    operand_flag = 0;
    operator = '\0';
}

int main()
{
    char **buffer = NULL;
    int buffer_size = 0;

    // Get the input from the user
    char input[MAX_BUFFER_SIZE];
    printf("Enter an expression: ");
    scanf("%s", input);

    // Calculate the result
    calculator(&buffer, &buffer_size);

    return 0;
}