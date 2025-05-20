//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} Complex;

typedef struct {
    int top;
    double operands[10];
    Complex complexOperands[10];
    int complexCount;
} Stack;

Stack* createStack(void) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = 0;
    stack->complexCount = 0;
    return stack;
}

void push(Stack* stack, double operand) {
    if (stack->top >= 10) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->operands[stack->top++] = operand;
}

void pushComplex(Stack* stack, Complex operand) {
    if (stack->complexCount >= 10) {
        printf("Stack overflow!\n");
        exit(1);
    }
    stack->complexOperands[stack->complexCount++] = operand;
}

double pop(Stack* stack) {
    if (stack->top < 1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    double result = stack->operands[--stack->top];
    return result;
}

Complex popComplex(Stack* stack) {
    if (stack->complexCount < 1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    Complex result = stack->complexOperands[--stack->complexCount];
    return result;
}

void add(Stack* stack, double operand1, double operand2) {
    double sum = operand1 + operand2;
    push(stack, sum);
}

void subtract(Stack* stack, double operand1, double operand2) {
    double diff = operand1 - operand2;
    push(stack, diff);
}

void multiply(Stack* stack, double operand1, double operand2) {
    double product = operand1 * operand2;
    push(stack, product);
}

void divide(Stack* stack, double operand1, double operand2) {
    double quotient = operand1 / operand2;
    push(stack, quotient);
}

void addComplex(Stack* stack, Complex operand1, Complex operand2) {
    Complex sum = {operand1.real + operand2.real, operand1.imag + operand2.imag};
    pushComplex(stack, sum);
}

void subtractComplex(Stack* stack, Complex operand1, Complex operand2) {
    Complex diff = {operand1.real - operand2.real, operand1.imag - operand2.imag};
    pushComplex(stack, diff);
}

void multiplyComplex(Stack* stack, Complex operand1, Complex operand2) {
    Complex product = {operand1.real * operand2.real - operand1.imag * operand2.imag, operand1.real * operand2.imag + operand1.imag * operand2.real};
    pushComplex(stack, product);
}

void divideComplex(Stack* stack, Complex operand1, Complex operand2) {
    Complex quotient = {operand1.real / operand2.real - operand1.imag / operand2.imag, operand1.real / operand2.imag + operand1.imag / operand2.real};
    pushComplex(stack, quotient);
}

int main(void) {
    Stack* stack = createStack();

    add(stack, 2, 3);
    add(stack, 5, 7);
    add(stack, 9, 11);

    printf("2 + 3 = %.2f\n", pop(stack));
    printf("5 + 7 = %.2f\n", pop(stack));
    printf("9 + 11 = %.2f\n", pop(stack));

    subtract(stack, 2, 3);
    subtract(stack, 5, 7);
    subtract(stack, 9, 11);

    printf("2 - 3 = %.2f\n", pop(stack));
    printf("5 - 7 = %.2f\n", pop(stack));
    printf("9 - 11 = %.2f\n", pop(stack));

    multiply(stack, 2, 3);
    multiply(stack, 5, 7);
    multiply(stack, 9, 11);

    printf("2 * 3 = %.2f\n", pop(stack));
    printf("5 * 7 = %.2f\n", pop(stack));
    printf("9 * 11 = %.2f\n", pop(stack));

    divide(stack, 2, 3);
    divide(stack, 5, 7);
    divide(stack, 9, 11);

    printf("2 / 3 = %.2f\n", pop(stack));
    printf("5 / 7 = %.2f\n", pop(stack));
    printf("9 / 11 = %.2f\n", pop(stack));

    Complex complexNumber1 = {2.5, 3.5};
    Complex complexNumber2 = {5.5, 7.5};

    addComplex(stack, complexNumber1, complexNumber2);
    addComplex(stack, complexNumber1, complexNumber2);
    addComplex(stack, complexNumber1, complexNumber2);

    printf("2.5 + 3.5i + 5.5 + 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);
    printf("2.5 + 3.5i + 5.5 + 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);
    printf("2.5 + 3.5i + 5.5 + 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);

    subtractComplex(stack, complexNumber1, complexNumber2);
    subtractComplex(stack, complexNumber1, complexNumber2);
    subtractComplex(stack, complexNumber1, complexNumber2);

    printf("2.5 - 3.5i - 5.5 - 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);
    printf("2.5 - 3.5i - 5.5 - 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);
    printf("2.5 - 3.5i - 5.5 - 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);

    multiplyComplex(stack, complexNumber1, complexNumber2);
    multiplyComplex(stack, complexNumber1, complexNumber2);
    multiplyComplex(stack, complexNumber1, complexNumber2);

    printf("2.5 * 3.5i * 5.5 * 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);
    printf("2.5 * 3.5i * 5.5 * 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);
    printf("2.5 * 3.5i * 5.5 * 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);

    divideComplex(stack, complexNumber1, complexNumber2);
    divideComplex(stack, complexNumber1, complexNumber2);
    divideComplex(stack, complexNumber1, complexNumber2);

    printf("2.5 / 3.5i / 5.5 / 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);
    printf("2.5 / 3.5i / 5.5 / 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);
    printf("2.5 / 3.5i / 5.5 / 7.5i = %.2f + %.2fi\n", popComplex(stack).real, popComplex(stack).imag);

    return 0;
}