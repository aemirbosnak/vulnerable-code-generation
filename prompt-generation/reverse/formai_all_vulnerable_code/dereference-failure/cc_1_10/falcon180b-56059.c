//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBERS 100
#define MAX_DIGITS 1000
#define MAX_OPERATORS 100
#define MAX_OPERAND_SIZE 1000
#define MAX_RESULT_SIZE 1000
#define MAX_EXPRESSION_SIZE 1000

typedef struct {
    char *value;
    int length;
} String;

typedef struct {
    String *operands;
    int num_operands;
    char *operator;
} Expression;

String *create_string(char *value) {
    String *string = (String *)malloc(sizeof(String));
    string->value = value;
    string->length = strlen(value);
    return string;
}

Expression *create_expression() {
    Expression *expression = (Expression *)malloc(sizeof(Expression));
    expression->operands = (String *)malloc(MAX_NUMBERS * sizeof(String));
    expression->num_operands = 0;
    expression->operator = NULL;
    return expression;
}

void add_operand(Expression *expression, String *operand) {
    expression->operands[expression->num_operands] = *operand;
    expression->num_operands++;
}

int evaluate_expression(Expression *expression) {
    int result = 0;
    int i;
    String *operand;
    char *endptr;

    for (i = 0; i < expression->num_operands; i++) {
        operand = &expression->operands[i];
        result += atoi(operand->value);
    }

    return result;
}

int main() {
    srand(time(NULL));

    int num_operands;
    int i;
    Expression *expression;
    String *operand;

    printf("Enter the number of operands: ");
    scanf("%d", &num_operands);

    expression = create_expression();

    for (i = 0; i < num_operands; i++) {
        operand = create_string(malloc(MAX_DIGITS * sizeof(char)));
        sprintf(operand->value, "%d", rand() % 1000);
        add_operand(expression, operand);
    }

    printf("Enter an operator (+, -, *, /): ");
    scanf("%s", expression->operator);

    int result = evaluate_expression(expression);

    printf("Result: %d\n", result);

    return 0;
}