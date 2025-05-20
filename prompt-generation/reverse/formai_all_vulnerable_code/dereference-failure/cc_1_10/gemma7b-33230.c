//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100

void scientific_calculator(char **buffer, int position, double value, double previous_value, char operator)
{
    if (position >= MAX_BUFFER_SIZE - 1)
    {
        return;
    }

    switch (operator)
    {
        case '+':
            value = previous_value + value;
            break;
        case '-':
            value = previous_value - value;
            break;
        case '*':
            value = previous_value * value;
            break;
        case '/':
            if (value == 0)
            {
                printf("Cannot divide by zero.\n");
                return;
            }
            value = previous_value / value;
            break;
        default:
            return;
    }

    buffer[position] = operator;
    position++;

    scientific_calculator(buffer, position, value, previous_value, buffer[position - 1]);
}

int main()
{
    char **buffer = (char **)malloc(MAX_BUFFER_SIZE * sizeof(char *));
    for (int i = 0; i < MAX_BUFFER_SIZE; i++)
    {
        buffer[i] = NULL;
    }

    double value = 0.0;
    double previous_value = 0.0;
    char operator = '\0';
    int position = 0;

    printf("Enter an expression: ");

    // Get the expression from the user
    char expression[100];
    scanf("%s", expression);

    // Parse the expression
    for (int i = 0; expression[i] != '\0'; i++)
    {
        switch (expression[i])
        {
            case '(':
            case ')':
            case '+':
            case '-':
            case '*':
            case '/':
                operator = expression[i];
                break;
            default:
                value = value * 10 + expression[i] - '0';
                previous_value = value;
                position++;
                buffer[position - 1] = expression[i];
                break;
        }
    }

    scientific_calculator(buffer, position, value, previous_value, operator);

    // Print the result
    printf("The result is: %.2lf\n", value);

    free(buffer);

    return 0;
}