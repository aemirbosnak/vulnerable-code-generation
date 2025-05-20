//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int division(int a, int b);
int power(int a, int b);
int modulus(int a, int b);
int absolute(int a);

int main()
{
    int num1, num2, answer;
    char op;
    printf("Greetings Sir/Madam, I am Thy Scientific Calculator in Medieval Era.\n");
    printf("Please enter your first number: ");
    scanf("%d", &num1);
    printf("Please enter your second number: ");
    scanf("%d", &num2);
    printf("Please select the operation you wish to perform:\n");
    printf("+ for addition\n- for subtraction\n* for multiplication\n/ for division\n^ for power\n%% for modulus\nabs for absolute value\n");
    scanf(" %c", &op);

    switch (op)
    {
    case '+':
        answer = addition(num1, num2);
        printf("The sum of %d and %d is %d.\n", num1, num2, answer);
        break;
    case '-':
        answer = subtraction(num1, num2);
        printf("The difference between %d and %d is %d.\n", num1, num2, answer);
        break;
    case '*':
        answer = multiplication(num1, num2);
        printf("The product of %d and %d is %d.\n", num1, num2, answer);
        break;
    case '/':
        answer = division(num1, num2);
        printf("The quotient of %d divided by %d is %d.\n", num1, num2, answer);
        break;
    case '^':
        answer = power(num1, num2);
        printf("%d raised to the power of %d is %d.\n", num1, num2, answer);
        break;
    case '%':
        answer = modulus(num1, num2);
        printf("%d modulo %d is %d.\n", num1, num2, answer);
        break;
    case 'a':
    case 'A':
        answer = absolute(num1);
        printf("The absolute value of %d is %d.\n", num1, answer);
        answer = absolute(num2);
        printf("The absolute value of %d is %d.\n", num2, answer);
        break;
    default:
        printf("Invalid operator selected.\n");
        break;
    }

    return 0;
}

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int multiplication(int a, int b)
{
    return a * b;
}

int division(int a, int b)
{
    if (b == 0)
    {
        printf("Error: Divide by zero.\n");
        exit(0);
    }
    return a / b;
}

int power(int a, int b)
{
    int i, result = 1;
    for (i = 1; i <= b; i++)
    {
        result = result * a;
    }
    return result;
}

int modulus(int a, int b)
{
    return a % b;
}

int absolute(int a)
{
    if (a < 0)
    {
        return (-a);
    }
    else
    {
        return a;
    }
}