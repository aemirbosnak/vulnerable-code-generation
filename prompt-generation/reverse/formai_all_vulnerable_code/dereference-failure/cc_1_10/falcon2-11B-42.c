//Falcon2-11B DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBER 1000000000

struct Node {
    int value;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (stack->top == NULL) {
        stack->top = newNode;
        return;
    }

    stack->top->next = newNode;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return -1;
    }

    int value = stack->top->value;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;

    free(temp);

    return value;
}

int isPalindrome(int number) {
    int reversed = 0;

    while (number > 0) {
        int remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    return reversed == number;
}

int main() {
    int a = 123456789;
    int b = 987654321;

    struct Stack stack;
    push(&stack, a);
    push(&stack, b);

    int sum = 0;
    int difference = 0;
    int product = 1;
    int quotient = 1;
    int exponent = 0;

    while (!isPalindrome(a)) {
        int current = pop(&stack);

        if (current == 0) {
            exponent++;
        } else {
            sum += current;
            difference += current;
            product *= current;
            quotient /= current;
            exponent++;
        }
    }

    a = sum;
    b = difference;
    product *= b;
    quotient /= b;

    if (exponent > 1) {
        int power = pow(a, exponent);
        a = (b * power) % MAX_NUMBER;
    }

    printf("Sum: %d\n", a);
    printf("Difference: %d\n", b);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);

    return 0;
}