//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Calculator
{
    double value;
    char operator;
    struct Calculator* next;
} Calculator;

Calculator* createCalculator()
{
    Calculator* calculator = (Calculator*)malloc(sizeof(Calculator));
    calculator->value = 0.0;
    calculator->operator = '\0';
    calculator->next = NULL;
    return calculator;
}

void addCalculator(Calculator* calculator, double value, char operator)
{
    Calculator* newCalculator = createCalculator();
    newCalculator->value = value;
    newCalculator->operator = operator;
    newCalculator->next = calculator;
    calculator = newCalculator;
}

double evaluateCalculator(Calculator* calculator)
{
    double result = calculator->value;
    switch (calculator->operator)
    {
        case '+':
            result += evaluateCalculator(calculator->next);
            break;
        case '-':
            result -= evaluateCalculator(calculator->next);
            break;
        case '*':
            result *= evaluateCalculator(calculator->next);
            break;
        case '/':
            result /= evaluateCalculator(calculator->next);
            break;
    }
    return result;
}

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    double result = 0.0;
    Calculator* calculator = NULL;

    printf("Enter an expression: ");
    scanf("%s", buffer);

    // Parse the expression and create a calculator chain
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        double number = atof(buffer[i]) / 10.0;
        addCalculator(calculator, number, buffer[i]);
    }

    // Evaluate the calculator chain and get the result
    result = evaluateCalculator(calculator);

    // Print the result
    printf("The result is: %.2lf\n", result);

    return 0;
}