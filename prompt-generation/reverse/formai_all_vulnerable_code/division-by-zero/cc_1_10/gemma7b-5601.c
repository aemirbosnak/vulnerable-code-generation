//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int top = -1;

void push(char data)
{
    if (top == MAX_BUFFER_SIZE - 1)
    {
        printf("Stack Overflow!\n");
        exit(1);
    }

    buffer[++top] = data;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }

    return buffer[top--];
}

int main()
{
    char input[MAX_BUFFER_SIZE];
    char operator;
    float result;

    printf("Enter an expression: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    // Parse the expression
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            push(input[i]);
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            push(input[i] - '0');
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            operator = input[i];
        }
    }

    // Calculate the result
    switch (operator)
    {
        case '+':
            result = pop() + pop();
            break;
        case '-':
            result = pop() - pop();
            break;
        case '*':
            result = pop() * pop();
            break;
        case '/':
            result = pop() / pop();
            break;
    }

    // Print the result
    printf("The result is: %.2f\n", result);

    return 0;
}